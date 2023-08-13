// Header
#include <apps/TestApp.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>
#include <core/Icons.hpp>

Button testButton(3, 17, 120, 30, 9, "Hello, Framework!");
Timer invertTimer(400, 0, 0);

void TestApp::draw()
{
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
      testButton.invertFocus();
    }

    disp.clearBuffer();
    testButton.draw();
    disp.sendBuffer();
  }
}
