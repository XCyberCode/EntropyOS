// Header
#include <apps/Welcome.hpp>

// Local dependencies
#include <core/AppFramework.h>
#include <core/HardwareManager.h>
#include <core/Icons.h>

// Libraries
#include <lib/FastString.h>
#include <Arduino.h>

Icon stepIcon(53, 13, 22, 22, true, 7, 5);
TextLabel stepLabel(0, 43, 128, 16, 2, 2);

void contrastStep()
{
  FastString<12> contrastStr; 
  uint8_t contrastValue = 10;
  contrastStr = "Contrast: ";
  contrastStr += contrastValue;
  while(1)
  {
    tickAll();
    if(aBtn.click()) 
    {
      storage.putShort("contrast", contrastValue);
      break;
    }
    if(leftBtn.click() && contrastValue > 0)
    {
      contrastValue--;
      disp.setContrast(map(contrastValue, 0, 10, 1, 255));
      contrastStr = "Contrast: ";
      contrastStr += contrastValue;
    }
    if(rightBtn.click() && contrastValue < 10)
    {
      contrastValue++;
      disp.setContrast(map(contrastValue, 0, 10, 1, 255));
      contrastStr = "Contrast: ";
      contrastStr += contrastValue;
    }
    disp.clearBuffer();
    stepIcon.draw(contrastIcon);
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
