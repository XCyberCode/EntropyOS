// Header
#include <apps/Launcher.hpp>

// Apps
#include <apps/TestApp.hpp>
#include <apps/Settings.hpp>

// Local dependencies
#include <core/HardwareManager.hpp>
#include <core/AppFramework.hpp>

// Apps instances
Settings settings;
TestApp testApp;

// Variables
const char* appNames[] = {"Settings", "TestApp"};
short cursorPos = 0;

// Widgets
Button appLabel;

void loadApp(short appID)
{
  if(appID == 0)
  {
    settings.draw();
  }
  else if(appID == 1)
  {
    testApp.draw();
  }
}

void Launcher::draw() 
{
  appLabel.width = 64;
  appLabel.height = 16;
  appLabel.positionX = 32;
  appLabel.positionY = 32;
  appLabel.textAnchorH = "center";
  appLabel.textAnchorV = "center";
  appLabel.isFramed = true;
  appLabel.cornerRadius = 7;

  while(1)
  {
    tickAll();
    if(leftBtn.click())
    {
      (cursorPos == 0) ? cursorPos = 1 : cursorPos--;
    }
    else if(rightBtn.click())
    {
      (cursorPos == 1) ? cursorPos = 0 : cursorPos++;
    }
    else if(aBtn.click())
    {
      loadApp(cursorPos);
    }

    appLabel.text = appNames[cursorPos];
    disp.clearBuffer();
    appLabel.draw();
    disp.sendBuffer();
  }
}
