// Libraries
#include <Arduino.h>

// Local dependencies
#include <apps/Launcher.hpp>
#include <core/HardwareManager.hpp>

// FirstSetup welcome;
// TestApp testApp;
Launcher launcher;

void setup()
{
  disp.begin();
  disp.setFontMode(1);
  launcher.draw();
}

void loop(){}
