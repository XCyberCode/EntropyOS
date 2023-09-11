// Header
#include <apps/Clock.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>
#include <core/Timer.hpp>
#include <lib/FastString.h>

// Libraries
#include <U8g2lib.h>

void ClockApp::draw()
{
  TextLabelWidget timeLabel(0, 0, 128, 64);
  Timer updateTimer(1000, 0, 0);
  FastString<8> timeInfo;

  clockModule.read();
  timeInfo.clearBuffer();
  timeInfo = timeInfo + clockModule.getSecond() + ":" + clockModule.getMinute() + ":" + clockModule.getHour();
  
  updateTimer.start();
  while(1)
  {
    tickAll();
    if(bBtn.click())
    {
      break;
    }
    if(updateTimer.tick())
    {
      clockModule.read();
      timeInfo.clearBuffer();
      timeInfo = timeInfo + clockModule.getSecond() + ":" + clockModule.getMinute() + ":" + clockModule.getHour();
    }
    disp.clearBuffer();
    timeLabel.draw(timeInfo.c_str(), u8g2_font_helvR14_tf);
    disp.sendBuffer();
  }
}
