include <BOSL2/std.scad>
$fn = 50;

// Global variable
BOARD_WIDTH = 70;
BOARD_HEIGHT = 50;
WALL_THICKNESS = 3;

PLATE_HEIGHT = 3;
PLATE_SHIFT_HEIGHT = 2;

BUZZER_RADIUS = 6.5;

difference()
{
  // Main plate
  difference()
  {
    linear_extrude(PLATE_HEIGHT)
    rect([
      BOARD_WIDTH + WALL_THICKNESS * 2, 
      BOARD_HEIGHT + WALL_THICKNESS * 2], 
      rounding = 3, 
      anchor = [-1, 0, -1]
    );
  
    translate([3, 3, -1])
    linear_extrude(PLATE_SHIFT_HEIGHT)
    rect([
      BOARD_WIDTH, 
      BOARD_HEIGHT], 
      rounding = 2, 
      anchor = [-1, 0, -1]
    );
  }
  
  // Components
  // Buttons
  translate([12, 4, 0])
  cube([9, 19, 4]); // Up and Down
    
  translate([5, 9, 0])
  cube([23, 8, 4]); // Right and Left
  // cube([23, 19, 4]);
  
  // Left pin header
  translate([30, 5, 0])
  cube([4, 41, 4]);
  
  // Right pin header
  translate([55, 5, 0])
  cube([4, 41, 4]);
  
  // Display pin header
  translate([11, 47, 0])
  cube([13, 4, 4]);
  
  // I2C pin header
  translate([37, 47, -1])
  cube([12, 20, 5]);
  
  // Buzzer
  translate([65, 44, 0])
  linear_extrude(4)
  circle(r = BUZZER_RADIUS);
  
  // A/B Buttons
  translate([60.4, 4, 0])
  cube([8.6, 16, 4]);
}