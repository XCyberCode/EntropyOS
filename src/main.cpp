// Libraries
#include <Arduino.h>

// Local dependencies
#include <apps/Launcher.hpp>
#include <apps/Welcome.hpp>
#include <apps/TestApp.hpp>
#include <core/HardwareManager.hpp>

LauncherApp appLauncher;
WelcomeApp appWelcome;
TestApp appTest;

void setup()
{
  beginHardware();
  if(!storage.getShort("initialized"))
  {
    // appTest.draw();
    appWelcome.draw();
    appLauncher.draw();
  }
  else 
  {
    appLauncher.draw();
  }
}

void loop(){}
