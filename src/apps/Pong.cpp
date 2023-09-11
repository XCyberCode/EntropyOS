// Header
#include <apps/Pong.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/Timer.hpp>
#include <core/HardwareManager.hpp>

// Libraries
#include <Arduino.h>

// pps - Pixels Per Second
uint8_t ballSpeed = 20;
uint8_t playerSpeed = 12;
uint8_t enemySpeed = 12;

uint8_t ballX = 64;
uint8_t ballY = 32;
int8_t ballVectorX = 1;
int8_t ballVectorY = 1;
uint16_t playerY = 24;
uint16_t enemyY = 24;
uint8_t playerLength = 16;
uint16_t playerScore = 0;

Timer playerUpdateTimer(1000 / playerSpeed, 0, 0);
Timer enemyUpdateTimer(1000 / enemySpeed, 0, 0);
Timer ballUpdateTimer(1000 / ballSpeed);

TextLabelWidget scoreLabel(0, 0, 128, 16);

void resetGame()
{
  ballX = 64;
  ballY = 32;
  ballVectorX = 1;
  ballVectorY = 1;
  playerY = 24;
  enemyY = 24;
  ballSpeed = 6;
  playerScore = 0;
}

void drawField()
{
  disp.clearBuffer();
  disp.drawPixel(ballX, ballY);
  disp.drawBox(124, playerY, 2, playerLength);
  disp.drawBox(4, enemyY, 2, playerLength);
  scoreLabel.draw(String(playerScore).c_str());
  disp.sendBuffer();
}

void updateBall()
{
  if(ballY == 63)
  {
    ballVectorY = -1;
  }
  else if(ballY == 0)
  {
    ballVectorY = 1;
  }

  if(ballX == 123 && ballVectorX == 1)
  {
    
  }

  if(ballX == 123 && ballVectorX == 1)
  {
    if(ballY + ballVectorY > playerY && ballY + ballVectorY < playerY + playerLength - 1)
    {
      ballVectorX = -1;
      playerScore++;
    }

    else if(ballVectorY == 1 && ballY + 1 == playerY)
    {
      ballVectorX = -1;
      ballVectorY = -1;
      playerScore++;
    }

    else if(ballVectorY == -1 && ballY - 1 == playerY + playerLength - 1)
    {
      ballVectorX = -1;
      ballVectorY = 1;
      playerScore++;
    }
  }

  if(ballX == 6 && ballVectorX == -1)
  {
    if(ballY + 1 > enemyY && ballY + ballVectorY < enemyY + playerLength - 1)
    {
      ballVectorX = 1;
    }

    else if(ballVectorY == 1 && ballY + 1 == enemyY)
    {
      ballVectorX = 1;
      ballVectorY = -1;
    }

    else if(ballVectorY == -1 && ballY - 1 == enemyY + playerLength - 1)
    {
      ballVectorX = 1;
      ballVectorY = 1;
    }
  }
    
  if(ballX == 127)
  {
    resetGame();
  }

  else if(ballX == 0)
  {
    playerScore += 3;
    ballX = 64;
    ballY = 32;
    ballVectorX = 1;
    ballVectorY = 1;
    playerY = 24;
    enemyY = 24;
  }

  ballSpeed = 16 + floor(playerScore / 2);
  ballUpdateTimer.setPeriod(1000 / ballSpeed);

  ballX += ballVectorX;
  ballY += ballVectorY;
}

void PongApp::draw()
{
  resetGame();
  playerUpdateTimer.start();
  enemyUpdateTimer.start();
  ballUpdateTimer.start();

  while(1)
  {
    tickAll();
    if(bBtn.click())
    {
      return;
    }

    if(aBtn.click())
    {
      resetGame();
    }
    if(playerUpdateTimer.tick())
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

    if(enemyUpdateTimer.tick())
    {
      if(ballY < enemyY + playerLength / 2 && enemyY > 0)
      {
        enemyY--;
      }
      else if(ballY > enemyY + playerLength / 2 && enemyY + playerLength - 1 < 63)
      {
        enemyY++;
      }
    }

    if(ballUpdateTimer.tick())
    {
      updateBall();
    }

    drawField();
  }
}
