// Libraries
#include <Arduino.h>

// Local dependencies
#include <apps/Launcher.hpp>
#include <core/HardwareManager.hpp>

void setup()
{
  beginHardware();
  Launcher::draw();
}

void loop(){}
