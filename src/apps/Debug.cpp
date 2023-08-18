// Header
#include <apps/Debug.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>
#include <lib/FastString.h>

Button upBtnWidget(36, 5, 18, 18, 4);
Button downBtnWidget(36, 41, 18, 18, 4);
Button leftBtnWidget(18, 23, 18, 18, 4);
Button rightBtnWidget(54, 23, 18, 18, 4);
Button aBtnWidget(90, 23, 18, 18, 4);

TextLabel timeWidget(0, 0, 128, 16, 1, 3);

Timer clockUpdateTimer(1000, 0, 0);

void Debug::draw()
{
  // clockModule.set(0, 0, 0, 3, 15, 8, 23);
  // tone(17, 500);
  clockUpdateTimer.start();
  FastString<8> timeWidgetStr = "N:N:N";
  while(1)
  {
    tickAll();
    if(upBtn.click()) {upBtnWidget.invertFocus();}
    if(downBtn.click()) {downBtnWidget.invertFocus();}
    if(leftBtn.click()) {leftBtnWidget.invertFocus();}
    if(rightBtn.click()) {rightBtnWidget.invertFocus();}
    if(aBtn.click()) {aBtnWidget.invertFocus();}

    if(bBtn.click())
    {
      noTone(17);
      return;
    }

    if(clockUpdateTimer.tick())
    {
      clockModule.read();
      timeWidgetStr.clearBuffer();
      timeWidgetStr = timeWidgetStr + clockModule.getSecond() + ":" + clockModule.getMinute() + ":" + clockModule.getHour();
    }

    disp.clearBuffer();
    upBtnWidget.draw("U");
    downBtnWidget.draw("D");
    leftBtnWidget.draw("L");
    rightBtnWidget.draw("R");
    aBtnWidget.draw("A");
    timeWidget.draw(timeWidgetStr.c_str());
    disp.sendBuffer();
  }
}
