// Header
#include <apps/Settings.hpp>

// Libraries
// #include <NTPClient.h>
// #include <WiFi.h>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>

TextLabel itemLabel(0, 0, 128, 16, "", "center", "left");
String items[] = {"Load time from NTP", "Set timezone", "Set contrast"};
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

void executeTask(short taskID)
{
  if(taskID == 0)
  {
  }

  else if(taskID == 1)
  {
    timezoneWindow();
  }

  else if(taskID == 2)
  {
    contrastWindow();
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
    for(int currentItem = 0; currentItem < 3; currentItem++)
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
