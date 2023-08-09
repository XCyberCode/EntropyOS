// Header
#include <apps/TestApp.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>
#include <core/Icons.hpp>

Button testButton;
TextLabel testLabel;
Icon testIcon;

void TestApp::draw()
{
  testButton.positionX = 3;
  testButton.positionY = 17;
  testButton.text = "Hello, Framework!";
  testButton.width = 120;
  testButton.height = 30;
  testButton.isHighlighted = true;
  testButton.textAnchorV = "center";
  testButton.textAnchorH = "center";
  testButton.cornerRadius = 9;
 
  testIcon.width = 22;
  testIcon.height = 22;

  while(1)
  {
    testButton.isHighlighted = !testButton.isHighlighted;
    disp.clearBuffer();
    testIcon.draw(calculatorIcon);
    testButton.draw();
    disp.sendBuffer();
    delay(400);
  }
}
