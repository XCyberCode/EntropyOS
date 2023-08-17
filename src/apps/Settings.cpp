// Header
#include <apps/Settings.hpp>

// Defines
// Numder of menu items
#define NUMBER_OF_ITEMS 4

// #include <NTPClient.h>
// #include <WiFi.h>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>

TextLabel itemLabel(0, 0, 128, 16, "", 2, 1);
String items[] = {"Load time from NTP", "Set timezone", "Set contrast", "Reset all data"};
short cursorPosition = 0;

void contrastWindow()
{
  TextLabel contrastLabel(0, 0, 128, 64);
  short contrastValue = storage.getShort("contrast");

  while(1)
  {
    tickAll();
    if(bBtn.click())
    {
      storage.putShort("contrast", contrastValue);
      return;
    }
    if(rightBtn.click() && contrastValue < 255) 
    {
      contrastValue += 5;
      disp.setContrast(contrastValue);
    }
    if(leftBtn.click() && contrastValue > 0) 
    {
      contrastValue -= 5;
      disp.setContrast(contrastValue);
    }

    disp.clearBuffer();
    contrastLabel.setText("Contrast: " + String(contrastValue));
    contrastLabel.draw();
    disp.sendBuffer();
  }
}

void timezoneWindow()
{
  TextLabel timezoneLabel(0, 0, 128, 64);
  short timezoneOffset = storage.getShort("timezone");

  while(1)
  {
    tickAll();
    if(bBtn.click()) {
      storage.putShort("timezone", timezoneOffset);
      return;
    }
    if(rightBtn.click()) {timezoneOffset++;}
    if(leftBtn.click()) {timezoneOffset--;}

    disp.clearBuffer();
    timezoneLabel.setText("Timezone: UTC" + String(timezoneOffset));
    timezoneLabel.draw();
    disp.sendBuffer();
  }
}

void resetWindow()
{
  TextLabel warningLabel(0, 0, 128, 64, "All data will be erased.");
  disp.clearBuffer();
  warningLabel.draw();
  disp.sendBuffer();

  while(1)
  {
    tickAll();
    if(bBtn.click()) {return;}
    if(aBtn.click())
    {
      disp.clearBuffer();
      warningLabel.setText("Loading. Please wait.");
      warningLabel.draw();
      disp.sendBuffer();

      storage.putBool("initialized", false);
      ESP.restart();
    }
  }
}

void executeTask(short taskID)
{
  switch(taskID)
  {
    case 1: timezoneWindow(); break;
    case 2: contrastWindow(); break;
    case 3: resetWindow(); break;
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
    for(int currentItem = 0; currentItem < NUMBER_OF_ITEMS; currentItem++)
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
