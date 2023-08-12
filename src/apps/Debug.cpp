// Header
#include <apps/Debug.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>

Button upBtnWidget;
Button downBtnWidget;
Button leftBtnWidget;
Button rightBtnWidget;
Button aBtnWidget;
Button bBtnWidget;

void Debug::draw()
{
  upBtnWidget.positionX = 31;
  upBtnWidget.positionY = 5;
  upBtnWidget.width = 18;
  upBtnWidget.height = 18;
  upBtnWidget.text = "U";
  upBtnWidget.textAnchorV = "center";
  upBtnWidget.textAnchorH = "center";
  upBtnWidget.cornerRadius = 4;

  downBtnWidget.positionX = 31;
  downBtnWidget.positionY = 41;
  downBtnWidget.width = 18;
  downBtnWidget.height = 18;
  downBtnWidget.text = "D";
  downBtnWidget.textAnchorV = "center";
  downBtnWidget.textAnchorH = "center";
  downBtnWidget.cornerRadius = 4;

  while(1)
  {
    tickAll();
    if(upBtn.click()) {upBtnWidget.isHighlighted = !upBtnWidget.isHighlighted;}

    if(downBtn.click()) {downBtnWidget.isHighlighted = !downBtnWidget.isHighlighted;}

    if(bBtn.click())
    {
      return;
    }

    disp.clearBuffer();
    upBtnWidget.draw();
    downBtnWidget.draw();
    disp.sendBuffer();
  }
}
