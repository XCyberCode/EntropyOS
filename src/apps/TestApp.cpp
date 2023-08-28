// Header
#include <apps/TestApp.hpp>

// Local dependencies
#include <core/AppFramework.h>
#include <core/HardwareManager.h>

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

  FastString<20> testString;
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
  FastString<30> newTestString;
  testString = 12345943223544;
  Serial.println(testString == 12345632452345);
}
