// Header
#include <apps/Launcher.hpp>

// Apps
#include <apps/TestApp.hpp>
#include <apps/Settings.hpp>
#include <apps/Debug.hpp>

// Local dependencies
#include <core/HardwareManager.hpp>
#include <core/AppFramework.hpp>

// Apps instances
Settings settings;
TestApp testApp;
Debug debugApp;

// Variables
const char* appNames[] = {"Settings", "TestApp", "Debug"};
short cursorPos = 0;

// Widgets
Button appLabel(32, 32, 64, 16, 7);

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
  else if(appID == 2)
  {
    debugApp.draw();
  }
}

void Launcher::draw() 
{
  while(1)
  {
    tickAll();
    if(leftBtn.click())
    {
      (cursorPos == 0) ? cursorPos = 2 : cursorPos--;
    }
    else if(rightBtn.click())
    {
      (cursorPos == 2) ? cursorPos = 0 : cursorPos++;
    }
    else if(aBtn.click())
    {
      loadApp(cursorPos);
    }

    appLabel.setText(appNames[cursorPos]);
    disp.clearBuffer();
    appLabel.draw();
    disp.sendBuffer();
  }
}
