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

void Debug::draw()
{
  while(1)
  {
    tickAll();
    if(upBtn.click()) {upBtnWidget.isHighlighted = !upBtnWidget.isHighlighted;}
    if(downBtn.click()) {downBtnWidget.isHighlighted = !downBtnWidget.isHighlighted;}
    if(leftBtn.click()) {leftBtnWidget.isHighlighted = !leftBtnWidget.isHighlighted;}
    if(rightBtn.click()) {rightBtnWidget.isHighlighted = !rightBtnWidget.isHighlighted;}
    if(aBtn.click()) {aBtnWidget.isHighlighted = !rightBtnWidget.isHighlighted;}

    if(bBtn.click())
    {
      return;
    }

    disp.clearBuffer();
    upBtnWidget.draw();
    downBtnWidget.draw();
    leftBtnWidget.draw();
    rightBtnWidget.draw();
    aBtnWidget.draw();
    disp.sendBuffer();
  }
}
