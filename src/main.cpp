// Libraries
#include <Arduino.h>

// Apps
#include <apps/Launcher.hpp>
#include <apps/Welcome.hpp>
#include <apps/TestApp.hpp>

// Local dependencies
#include <core/HardwareManager.h>

Launcher appLauncher;
Welcome appWelcome;
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
