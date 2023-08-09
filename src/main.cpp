// Libraries
#include <Arduino.h>
#include <TimerMs.h>
#include <EncButton.h>

// Local dependencies
#include <apps/FirstSetup.hpp>
#include <apps/TestApp.hpp>
#include <core/AppFramework.hpp>

// FirstSetup welcome;
TestApp testApp;

void setup()
{
  beginFramework();
  testApp.draw();
}

void loop(){}
