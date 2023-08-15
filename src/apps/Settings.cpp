// Header
#include <apps/Settings.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>

TextLabel itemLabel(0, 0, 128, 16, "", "center", "left");
String items[] = {"General", "System", "Network", "Hardware"};
short cursorPosition = 0;

void Settings::draw()
{
  while(1)
  {
    tickAll();

    if(upBtn.click())
    {
      if(cursorPosition == 0)
      {
        cursorPosition = 3;
      }
      else
      {
        cursorPosition--;
      }
    }
    if(downBtn.click())
    {
      if(cursorPosition == 3)
      {
        cursorPosition = 0;
      }
      else 
      {
        cursorPosition++;
      }
    }
    if(bBtn.click())
    {
      return;
    }

    disp.clearBuffer();
    for(int currentItem = 0; currentItem < 4; currentItem++)
    {
      itemLabel.setPositionY(16 * currentItem);
      if(currentItem == cursorPosition)
      {
        itemLabel.setText("> " + items[currentItem]);
      }
      else
      {
        itemLabel.setText("  " + items[currentItem]);
      }
      itemLabel.draw();
    }
    disp.sendBuffer();
  }
}
