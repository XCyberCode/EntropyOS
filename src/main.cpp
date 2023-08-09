// Libraries
#include <Arduino.h>
#include <TimerMs.h>
#include <EncButton.h>

// Local dependencies
// #include <apps/FirstSetup.hpp>
// #include <apps/TestApp.hpp>
#include <apps/Launcher.hpp>
#include <core/AppFramework.hpp>

// FirstSetup welcome;
// TestApp testApp;
Launcher launcher;

void setup()
{
  beginFramework();
  launcher.draw();
}

void loop(){}
