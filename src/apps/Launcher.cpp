// === Header
#include <apps/Launcher.hpp>

// === Defines
// Number of entries in the launcher - 1
#define MAX_CURSOR_POS 2 

// === Apps
#include <apps/Settings.hpp>
#include <apps/Debug.hpp>
#include <apps/I2CScanner.hpp>

// === Local dependencies
#include <core/HardwareManager.hpp>
#include <core/AppFramework.hpp>
#include <core/Icons.hpp>

// === Apps instances
Debug appDebug;
Settings appSettings;
I2CScanner appScanner;

// == Global variables
// Names of the apps
const char* appNames[] = {
  appSettings.appName,
  appDebug.appName, 
  appScanner.appName
};

// Icons of the apps
unsigned char* appIcons[] = {
  appSettings.appIcon, 
  appDebug.appIcon, 
  appScanner.appIcon
};

// Position of the menu cursor
uint8_t cursorPos = 0;

// === Widgets
TextLabel appLabel(0, 43, 128, 16); // A label with the name of the app
Icon appIcon(53, 13, 22, 22, true, 7, 5); // An icon with the icon of the app

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

    disp.clearBuffer();
    appLabel.draw(appNames[cursorPos]);
    appIcon.draw(appIcons[cursorPos]);
    disp.sendBuffer();
  }
}
