include <BOSL2/std.scad>

$fn = 50;

difference()
{
  difference()
  {
    linear_extrude(10)
    rect([76, 56], rounding = 3);
        
    translate([0, 0, 2])
    linear_extrude(10)
    rect([66, 46], rounding = 2);
  }
  
  translate([0, 0, 8])
  linear_extrude(10)
  rect([70, 50]);
}

translate([0, 0, 2])
linear_extrude(0.6)
text("Entropy", size = 6, valign = "center", halign = "center", font = "Cascadia Code");