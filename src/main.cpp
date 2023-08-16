// Libraries
#include <Arduino.h>

// Local dependencies
#include <apps/Launcher.hpp>
#include <apps/Welcome.hpp>
#include <core/HardwareManager.hpp>

Launcher appLauncher;
Welcome appWelcome;

void setup()
{
  beginHardware();
  if(!storage.getShort("initialized"))
  {
    appWelcome.draw();
  }
  else 
  {
    appLauncher.draw();
  }
}

void loop(){}
