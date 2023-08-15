// Header
#include <apps/Launcher.hpp>

// Defines
#define MAX_CURSOR_POS 3

// Apps
#include <apps/TestApp.hpp>
#include <apps/Settings.hpp>
#include <apps/Debug.hpp>
#include <apps/I2CScanner.hpp>

// Local dependencies
#include <core/HardwareManager.hpp>
#include <core/AppFramework.hpp>
#include <core/Icons.hpp>

// Variables
const char* appNames[] = {
  "Settings", 
  "TestApp", 
  "Debug", 
  "Scanner"
};

unsigned char* appIcons[] = {
  settingsIcon, 
  testIcon, 
  clockIcon, 
  scannerIcon
};

short cursorPos = 0;

// Widgets
Button appLabel(32, 42, 64, 16, 7);
Icon appIcon(53, 11, 22, 22, true, 3, 5);

void loadApp(short appID)
{
  if(appID == 0)
  {
    Settings::draw();
  }
  else if(appID == 1)
  {
    TestApp::draw();
  }
  else if(appID == 2)
  {
    Debug::draw();
  }
  else if(appID == 3)
  {
    I2CScanner::draw();
  }
}

void Launcher::draw() 
{
  while(1)
  {
    tickAll();
    if(leftBtn.click())
    {
      (cursorPos == 0) ? cursorPos = MAX_CURSOR_POS : cursorPos--;
    }
    else if(rightBtn.click())
    {
      (cursorPos == MAX_CURSOR_POS) ? cursorPos = 0 : cursorPos++;
    }
    else if(aBtn.click())
    {
      loadApp(cursorPos);
    }

    appLabel.setText(appNames[cursorPos]);
    disp.clearBuffer();
    appLabel.draw();
    appIcon.draw(appIcons[cursorPos]);
    disp.sendBuffer();
  }
}
