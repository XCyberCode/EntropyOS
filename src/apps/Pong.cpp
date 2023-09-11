// Header
#include <apps/Pong.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/Timer.hpp>
#include <core/HardwareManager.hpp>

uint8_t ballX, ballY;
uint8_t ballVectorX, ballVectorY;
uint16_t playerY, enemyY;
uint8_t playerLength = 8;

Timer inputUpdateTimer(50, 0, 0);

void drawGameField()
{
  disp.clearBuffer();
  disp.drawBox(0, playerY, 2, playerLength);
  disp.sendBuffer();
}

void PongApp::draw()
{
  inputUpdateTimer.start();
  while(1)
  {
    tickAll();
    if(bBtn.click())
    {
      return;
    }
    if(inputUpdateTimer.tick())
    {
      if(upBtn.read() && playerY > 0)
      {
        playerY--;
      }
      
      if(downBtn.read() && playerY < 63 - playerLength + 1)
      {
        playerY++;
      }
    }
    drawGameField();
  }
}
