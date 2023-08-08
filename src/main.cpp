// Libraries
#include <Arduino.h>
#include <TimerMs.h>
#include <EncButton.h>

// Local dependencies
#include <apps/FirstSetup.hpp>
#include <core/AppFramework.hpp>

FirstSetup welcome;

EncButton<EB_TICK, 27> leftBtn;
EncButton<EB_TICK, 26> centerBtn;
EncButton<EB_TICK, 25> rightBtn;

void setup()
{
  welcome.draw();
}

void loop(){}
