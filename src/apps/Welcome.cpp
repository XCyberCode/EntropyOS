// Header
#include <apps/Welcome.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>
#include <core/Icons.hpp>

Icon stepIcon(53, 13, 22, 22, true, 5, 5);
TextLabel stepLabel(0, 43, 128, 16, "Loading", "center", "center");
short currentStep = 1;
short stepValue = 0;

void contrastStep()
{

}

void controlsStep()
{
  stepLabel.setText("Right, Left - change");

  while(1)
  {
    tickAll();
    if(aBtn.click()) {return;}
    disp.clearBuffer();
    stepLabel.draw();
    stepIcon.draw(welcomeIcon);
    disp.sendBuffer();
  }
}

void welcomeStep()
{
  stepLabel.setText("Welcome!");

  while(1)
  {
    tickAll();
    if(aBtn.click()) {return;}

    disp.clearBuffer();
    stepLabel.draw();
    stepIcon.draw(welcomeIcon);
    disp.sendBuffer();
  }
}

void Welcome::draw()
{
  welcomeStep();
  controlsStep();
  contrastStep();
}
