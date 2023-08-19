// Header
#include <apps/TestApp.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>

// Libraries
#include <Arduino.h>
#include <lib/FastString.h>

TextLabel testInfoLabel(0, 15, 128, 16);
TextLabel testSpeedInfoLabel(0, 31, 128, 16);

void TestApp::draw()
{
  disp.clearBuffer();
  testInfoLabel.draw("=== Serial mode ===");
  testSpeedInfoLabel.draw("Boudrate: 115200");
  disp.sendBuffer();

  Serial.begin(115200);

  FastString<20> testString = "Hello";
  Serial.println(testString.getBuffer());
  testString = testString + 123 + "test";
  Serial.println(testString.getBuffer());
  testString.insert(1, "3");
  Serial.println(testString.getBuffer());
  testString += "New";
  Serial.println(testString.getBuffer());
}
