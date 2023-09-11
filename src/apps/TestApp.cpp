// Header
#include <apps/TestApp.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>

// Libraries
#include <Arduino.h>
#include <lib/FastString.h>

TextLabelWidget testInfoLabel(0, 15, 128, 16);
TextLabelWidget testSpeedInfoLabel(0, 31, 128, 16);

void TestApp::draw()
{
  disp.clearBuffer();
  testInfoLabel.draw("=== Serial mode ===");
  testSpeedInfoLabel.draw("Boudrate: 115200");
  disp.sendBuffer();

  Serial.begin(115200);

  FastString<20> testString = "Hi";
  /*
  Serial.println(testString.getBuffer());
  testString = testString + 123 + "test";
  Serial.println(testString.getBuffer());
  testString.insert(0, "hi");
  Serial.println(testString.getBuffer());
  testString += "New";
  Serial.println(testString.getBuffer());
  testString.remove(0, 2);
  Serial.println(testString.getBuffer());
  testString.replace(0, 'w');
  Serial.println(testString.getBuffer());
  */
  FastString<30> newTestString = "Hello";
  FastString<40> sumStr;
  for(int i = 0; i < 2; i++)
  {   
    sumStr = testString + 123;
    Serial.println(testString.c_str());
    Serial.println(sumStr.c_str());
  }
}
