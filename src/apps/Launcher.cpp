// === Header
#include <apps/Launcher.hpp>

// === Defines
// Number of entries in the launcher - 1
#define MAX_CURSOR_POS 4

// === Apps
#include <apps/Settings.hpp>
#include <apps/Debug.hpp>
#include <apps/I2CScanner.hpp>
#include <apps/Clock.hpp>
#include <apps/Pong.hpp>

// === Local dependencies
#include <core/HardwareManager.hpp>
#include <core/AppFramework.hpp>
#include <core/Icons.h>

// === Apps instances
DebugApp appDebug;
SettingsApp appSettings;
I2CScannerApp appScanner;
ClockApp appClock;
PongApp appPong;

// == Global variables
// Names of the apps
const char* appNames[] = {
  appSettings.appName,
  appDebug.appName, 
  appScanner.appName,
  appClock.appName,
  appPong.appName
};

// Icons of the apps
unsigned char* appIcons[] = {
  appSettings.appIcon, 
  appDebug.appIcon, 
  appScanner.appIcon,
  appClock.appIcon,
  appClock.appIcon
};

// Position of the menu cursor
uint8_t cursorPos = 0;

// === Widgets
TextLabelWidget appNameLabel(0, 43, 128, 16);
IconWidget appIcon(53, 13, 22, 22, true, 7, 5);

void loadApp(short appID)
{
  if(appID == 0)
  {
    appSettings.draw();
  }
  else if(appID == 1)
  {
    appDebug.draw();
  }
  else if(appID == 2)
  {
    appScanner.draw();
  }
  else if(appID == 3)
  {
    appClock.draw();
  }
  else if(appID == 4)
  {
    appPong.draw();
  }
}

void LauncherApp::draw() 
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

    disp.clearBuffer();
    appNameLabel.draw(appNames[cursorPos]);
    appIcon.draw(appIcons[cursorPos]);
    disp.sendBuffer();
  }
}
