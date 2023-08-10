// Header
#include <apps/TestApp.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>
#include <core/Icons.hpp>

Button testButton;
Timer invertTimer(400, 0, 0);

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
  
  invertTimer.start();

  while(1)
  {
    tickAll();

    if(bBtn.click())
    {
      return;
    }
    if(invertTimer.tick())
    {
      testButton.isHighlighted = !testButton.isHighlighted;
    }
    disp.clearBuffer();
    testButton.draw();
    disp.sendBuffer();
  }
}
