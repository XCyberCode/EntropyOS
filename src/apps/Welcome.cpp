// Header
#include <apps/Welcome.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>
#include <core/Icons.hpp>

Icon stepIcon(53, 13, 22, 22, true, 7, 5);
TextLabel stepLabel(0, 43, 128, 16, 2, 2);

void contrastStep()
{

}

void controlsStep()
{
  disp.clearBuffer();
  stepLabel.draw("A - Next step");
  stepIcon.draw(welcomeIcon);
  disp.sendBuffer();

  while(1)
  {
    tickAll();
    if(aBtn.click()) {break;}
  }

  disp.clearBuffer();
  stepLabel.draw("< > - Change value");
  stepIcon.draw(welcomeIcon);
  disp.sendBuffer();

  while(1)
  {
    tickAll();
    if(aBtn.click()) {return;}
  }
}

/*
void welcomeStep()
{
  disp.clearBuffer();
  stepLabel.draw("Welcome!");
  stepIcon.draw(welcomeIcon);
  disp.sendBuffer();

  while(1)
  {
    tickAll();
    if(aBtn.click()) {return;}
  }
}
*/

void Welcome::draw()
{
  controlsStep();
  contrastStep();
}
