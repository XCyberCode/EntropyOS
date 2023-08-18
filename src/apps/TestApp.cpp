// Header
#include <apps/TestApp.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>

// Libraries
#include <Arduino.h>
#include <lib/FastString.h>

FastString<12> testString;

TextLabel testInfoLabel(0, 15, 128, 16);
TextLabel testSpeedInfoLabel(0, 31, 128, 16);

void TestApp::draw()
{
  disp.clearBuffer();
  testInfoLabel.draw("=== Serial mode ===");
  testSpeedInfoLabel.draw("Boudrate: 115200");
  disp.sendBuffer();

  Serial.begin(115200);
  testString = "Hello";
  Serial.println(testString.getBuffer());
  testString += "123";
  Serial.println(testString.getBuffer());
}
