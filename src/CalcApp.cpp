#include <AppFramework.hpp>
#include <CalcApp.hpp>

AppFramework framework;
Button testButton;
TextLabel testLabel;
Icon testIcon;

unsigned char calculatorIcon[] = {
  0x00,0x10,0xc0,0x00,0x28,0xc0,0x00,0x44,0xc0,0x00,0x82,0xc0,
  0x00,0x05,0xc1,0x80,0x08,0xc2,0x40,0x10,0xc4,0xa0,0x28,0xc8,
  0x10,0x45,0xd0,0x08,0x82,0xe0,0x14,0x45,0xd1,0xa2,0x28,0xca,
  0x41,0x10,0xc4,0xa2,0x28,0xc2,0x14,0x45,0xc1,0x08,0x82,0xc0,
  0x10,0x41,0xc0,0xa0,0x20,0xc0,0x40,0x10,0xc0,0x80,0x08,0xc0,
  0x00,0x05,0xc0,0x00,0x02,0xc0
};

void CalcApp::draw()
{
  disp.begin();
  testButton.positionX = 3;
  testButton.positionY = 17;
  testButton.text = "Hello, Framework!";
  testButton.width = 120;
  testButton.height = 30;
  testButton.isHighlighted = true;
  testButton.textAnchorV = "center";
  testButton.textAnchorH = "center";
 
  testIcon.width = 22;
  testIcon.height = 22;

  while(1)
  {
    testButton.isHighlighted = !testButton.isHighlighted;
    disp.clearBuffer();
    //testIcon.draw(calculatorIcon);
    testButton.draw();
    disp.sendBuffer();
    delay(400);
  }
}
