// Header
#include <apps/Debug.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>

Button upBtnWidget(36, 5, 18, 18, 4, "U");
Button downBtnWidget(36, 41, 18, 18, 4, "D");
Button leftBtnWidget(18, 23, 18, 18, 4, "L");
Button rightBtnWidget(54, 23, 18, 18, 4, "R");
Button aBtnWidget(90, 23, 18, 18, 4, "A");

TextLabel timeWidget(0, 0, 128, 16, "0:0:0", "top", "right");

Timer clockUpdateTimer(1000, 0, 0);

void Debug::draw()
{
  clockModule.setAll(0, 0, 0, 3, 15, 8, 23);
  //tone(17, 500);
  clockUpdateTimer.start();
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
      timeWidget.setText(String(clockModule.getSecond()) + ":" + String(clockModule.getMinute()) + ":" + String(clockModule.getHour()));
    }

    disp.clearBuffer();
    upBtnWidget.draw();
    downBtnWidget.draw();
    leftBtnWidget.draw();
    rightBtnWidget.draw();
    aBtnWidget.draw();
    timeWidget.draw();
    disp.sendBuffer();
  }
}
