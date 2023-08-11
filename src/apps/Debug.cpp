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
  upBtnWidget.positionX = 36;
  upBtnWidget.positionY = 14;
  upBtnWidget.width = 12;
  upBtnWidget.height = 12;
  upBtnWidget.text = "U";
  upBtnWidget.textAnchorV = "center";
  upBtnWidget.textAnchorH = "center";
  upBtnWidget.cornerRadius = 5;

  downBtnWidget.positionX = 36;
  downBtnWidget.positionY = 40;
  downBtnWidget.width = 12;
  downBtnWidget.height = 12;
  downBtnWidget.text = "D";
  downBtnWidget.textAnchorV = "center";
  downBtnWidget.textAnchorH = "center";
  downBtnWidget.cornerRadius = 5;

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
