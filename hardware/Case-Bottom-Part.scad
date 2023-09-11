include <BOSL2/std.scad>

$fn = 50;

// Global variables
CASE_HEIGHT = 10;
BOARD_WIDTH = 70;
BOARD_LENGTH = 50;
BOARD_SHIFT = 0.4;
BOARD_PLACE_HEIGHT = 8;
WALL_THICKNESS = 3;
SUPPORT_THICKNESS = 2;
BOTTOM_THICKNESS = 2;
BOTTOM_LABEL_HEIGHT = 0.6;
BOTTOM_TEXT = "Entropy";

difference()
{
  difference()
  {
    // Main case
    linear_extrude(CASE_HEIGHT)
    rect([
      BOARD_WIDTH + WALL_THICKNESS * 2, 
      BOARD_LENGTH + WALL_THICKNESS * 2], 
      rounding = 3
    );
        
    // Support
    translate([0, 0, BOTTOM_THICKNESS])
    linear_extrude(CASE_HEIGHT - BOTTOM_THICKNESS + 1)
    rect([
      BOARD_WIDTH - SUPPORT_THICKNESS * 2, 
      BOARD_LENGTH - SUPPORT_THICKNESS * 2], 
      rounding = 2
    );
  }
  
  // Board place
  translate([0, 0, BOARD_PLACE_HEIGHT])
  linear_extrude(CASE_HEIGHT - BOARD_PLACE_HEIGHT + 1)
  rect([
    BOARD_WIDTH + BOARD_SHIFT * 2,
    BOARD_LENGTH + BOARD_SHIFT * 2
  ]);
}

// Bottom label
translate([0, 0, BOTTOM_THICKNESS])
linear_extrude(BOTTOM_LABEL_HEIGHT)
text(BOTTOM_TEXT, size = 6, valign = "center", halign = "center", font = "Cascadia Code");