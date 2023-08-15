// Header
#include <apps/Settings.hpp>

// Libraries
// #include <NTPClient.h>
// #include <WiFi.h>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>

TextLabel itemLabel(0, 0, 128, 16, "", "center", "left");
String items[] = {"Load time from NTP", "Set timezone", "None", "None"};
short cursorPosition = 0;

void executeTask(short taskID)
{
  if(taskID == 0)
  {
  }

  else if(taskID == 1)
  {
    TextLabel timezoneLabel(0, 0, 128, 64);
    short timezoneOffset = storage.getShort("timezone");

    while(1)
    {
      tickAll();
      if(bBtn.click()) {
        storage.putShort("timezone", timezoneOffset);
        break;
      }
      if(rightBtn.click()) {timezoneOffset++;}
      if(leftBtn.click()) {timezoneOffset--;}

      disp.clearBuffer();
      timezoneLabel.setText("Timezone: UTC" + String(timezoneOffset));
      timezoneLabel.draw();
      disp.sendBuffer();
    }
  }
}

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
    if(aBtn.click())
    {
      executeTask(cursorPosition);
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
