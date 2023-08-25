// Header
#include <apps/Settings.hpp>

// Defines
// Numder of menu items
#define NUMBER_OF_ITEMS 4

// Libraries
// #include <NTPClient.h>
// #include <WiFi.h>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>
#include <lib/FastString.h>

TextLabel itemLabel(0, 0, 128, 16, 2, 1);
FastString<30> items[] = {"  Load time from NTP", "  Set timezone", "  Set contrast", "  Reset all data"};

uint8_t cursorPosition = 0;

void contrastWindow()
{
  FastString<12> contrastStr;
  TextLabel contrastLabel(0, 0, 128, 64);
  short contrastValue = storage.getShort("contrast");

  contrastStr = "Contrast: "; 
  contrastStr += contrastValue;

  while(1)
  {
    tickAll();
    if(bBtn.click())
    {
      disp.setContrast(map(storage.getShort("contrast"), 0, 10, 1, 255));
      return;
    }
    if(aBtn.click())
    {
      storage.putShort("contrast", contrastValue);
      return;
    }
    if(rightBtn.click() && contrastValue < 10) 
    {
      contrastValue++;
      disp.setContrast(map(contrastValue, 0, 10, 1, 255));
      contrastStr = "Contrast: ";
      contrastStr += contrastValue;
    }
    if(leftBtn.click() && contrastValue > 0) 
    {
      contrastValue--;
      disp.setContrast(map(contrastValue, 0, 10, 1, 255));
      contrastStr = "Contrast: ";
      contrastStr += contrastValue;
    }

    disp.clearBuffer();
    contrastLabel.draw(contrastStr.c_str());
    disp.sendBuffer();
  }
}

void timezoneWindow()
{
  FastString<16> timezoneStr;
  TextLabel timezoneLabel(0, 0, 128, 64);
  short timezoneOffset = storage.getShort("timezone");

  timezoneStr = "Timezone: UTC"; 
  timezoneStr += timezoneOffset;

  while(1)
  {
    tickAll();
    if(aBtn.click())
    {
      storage.putShort("timezone", timezoneOffset);
      return;
    }
    if(bBtn.click()) 
    {
      return;
    }
    if(rightBtn.click()) 
    {
      timezoneOffset++;
      timezoneStr = "Timezone: UTC"; 
      timezoneStr += timezoneOffset;
    }
    if(leftBtn.click()) 
    {
      timezoneOffset--;
      timezoneStr = "Timezone: UTC"; 
      timezoneStr += timezoneOffset;
    }

    disp.clearBuffer();
    timezoneLabel.draw(timezoneStr.c_str());
    disp.sendBuffer();
  }
}

void resetWindow()
{
  TextLabel warningLabel(0, 0, 128, 64);
  disp.clearBuffer();
  warningLabel.draw("All data will be erased.");
  disp.sendBuffer();

  while(1)
  {
    tickAll();
    if(bBtn.click()) {return;}
    if(aBtn.click())
    {
      disp.clearBuffer();
      warningLabel.draw("Loading. Please wait.");
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
        cursorPosition = NUMBER_OF_ITEMS - 1;
      }
      else
      {
        cursorPosition--;
      }
    }
    if(downBtn.click())
    {
      if(cursorPosition == NUMBER_OF_ITEMS - 1)
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
        items[currentItem].setCharAt(0, '>');
      }
      else
      {
        items[currentItem].setCharAt(0, ' ');
      }
      itemLabel.draw((items[currentItem] + " ").c_str());
    }
    disp.sendBuffer();
  }
}
