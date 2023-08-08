// Libraries
#include <Arduino.h>
#include <TimerMs.h>
#include <EncButton.h>

// Local dependencies
#include <apps/FirstSetup.hpp>
#include <core/AppFramework.hpp>

FirstSetup welcome;

void setup()
{
  welcome.draw();
}

void loop(){}
