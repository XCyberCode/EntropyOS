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
  disp.clearBuffer();
  stepLabel.setPositionY(37);
  stepLabel.setText("< > Change value");
  stepLabel.draw();
  stepLabel.setPositionY(47);
  stepLabel.setText("A  Next step");
  stepLabel.draw();
  stepIcon.draw(welcomeIcon);
  disp.sendBuffer();

  stepLabel.setPositionY(37);

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

  disp.clearBuffer();
  stepLabel.draw();
  stepIcon.draw(welcomeIcon);
  disp.sendBuffer();

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
