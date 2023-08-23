// Header
#include <apps/Welcome.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>
#include <core/Icons.hpp>

// Libraries
#include <lib/FastString.h>
#include <Arduino.h>

Icon stepIcon(53, 13, 22, 22, true, 7, 5);
TextLabel stepLabel(0, 43, 128, 16, 2, 2);

void contrastStep()
{
  FastString<11> contrastStr; 
  contrastStr += "Contrast: 9";
  uint8_t contrastValue = 9;
  while(1)
  {
    tickAll();
    if(aBtn.click()) 
    {
      storage.putShort("contrast", contrastValue);
      break;
    }
    if(leftBtn.click())
    {
      (contrastValue > 0) ? contrastValue-- : contrastValue = 9;
      disp.setContrast(map(contrastValue, 0, 9, 1, 255));
      contrastStr.remove(10, 1);
      contrastStr += contrastValue;
    }
    if(rightBtn.click())
    {
      (contrastValue < 9) ? contrastValue++ : contrastValue = 0;
      disp.setContrast(map(contrastValue, 0, 9, 1, 255));
      contrastStr.remove(10, 1);
      contrastStr += contrastValue;
    }
    disp.clearBuffer();
    stepIcon.draw(welcomeIcon);
    stepLabel.draw(contrastStr.c_str());
    disp.sendBuffer();
  }
}

void controlsStep()
{
  disp.clearBuffer();
  stepLabel.draw("A - Next step");
  stepIcon.draw(controlsIcon);
  disp.sendBuffer();

  while(1)
  {
    tickAll();
    if(aBtn.click()) {break;}
  }

  disp.clearBuffer();
  stepLabel.draw("< > - Change value");
  stepIcon.draw(controlsIcon);
  disp.sendBuffer();

  while(1)
  {
    tickAll();
    if(aBtn.click()) {break;}
  }
}

void Welcome::draw()
{
  controlsStep();
  contrastStep();
}
