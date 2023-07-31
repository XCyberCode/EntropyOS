#include <Arduino.h>
#include <AppFramework.hpp>
#include <TimerMs.h>
#include <EncButton.h>

#include <CalcApp.hpp>

AppFramework mainFramework;
//Button testButton;
//TextLabel testLabel;

CalcApp calculator;

EncButton<EB_TICK, 27> leftBtn;
EncButton<EB_TICK, 26> centerBtn;
EncButton<EB_TICK, 25> rightBtn;

void setup()
{
  calculator.draw();
}

void loop(){}
