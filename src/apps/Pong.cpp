// Header
#include <apps/Pong.hpp>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/Timer.hpp>
#include <core/HardwareManager.hpp>

// Libraries
#include <Arduino.h>

// Defines
// Set speed in pps (Pixels Per Second)
uint8_t playerLength = 16;
uint8_t initialBallSpeed = 30;
uint8_t initialPlayerSpeed = 16;
uint8_t initialEnemySpeed = 18;

uint16_t playerY, enemyY;
uint8_t ballX, ballY;
int8_t ballVectorX;
int8_t ballVectorY;
uint16_t playerScore;

Timer playerUpdateTimer(1000 / initialPlayerSpeed, 0, 0);
Timer enemyUpdateTimer(1000 / initialEnemySpeed, 0, 0);
Timer ballUpdateTimer(1000 / initialBallSpeed, 0, 0);

TextLabelWidget scoreLabel(0, 0, 128, 16);

void resetGame(bool resetScore = true)
{
  // Initial players position
  playerY = 24;
  enemyY = 24;

  // Initial ball position
  ballX = 56 + random(0, 16);
  ballY = 25 + random(0, 16);

  // Initial ball acceleration
  ballVectorX = 1;
  int8_t accelerationVectors[2] = {-1, 1};
  ballVectorY = accelerationVectors[random(0, 2)];

  if(resetScore)
  {
    playerScore = 0;
  }
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
  // Bottom wall
  if(ballY == 63)
  {
    ballVectorY = -1;
  }
  // Top wall
  else if(ballY == 0)
  {
    ballVectorY = 1;
  }

  if(ballX == 123 && ballVectorX == 1)
  {
    if(ballVectorY == 1)
    {
      if(ballY + 1 > playerY && ballY + 1 < playerY + playerLength)
      {
        ballVectorX = -1;
      }
      else if(ballY + 1 == playerY)
      {
        ballVectorX = -1;
        ballVectorY = -1;
      }
    }

    else if(ballVectorY == -1)
    {
      if(ballY - 1 > playerY && ballY - 1 < playerY + playerLength - 1)
      {
        ballVectorX = -1;
      }
      else if(ballY - 1 == playerY + playerLength - 1)
      {
        ballVectorX = -1;
        ballVectorY = 1;
      }
    }
  }

  if(ballX == 6 && ballVectorX == -1)
  {
    if(ballVectorY == 1)
    {
      if(ballY + 1 > enemyY && ballY + 1 < enemyY + playerLength)
      {
        ballVectorX = 1;
      }
      else if(ballY + 1 == enemyY)
      {
        ballVectorX = 1;
        ballVectorY = -1;
      }
    }

    else if(ballVectorY == -1)
    {
      if(ballY - 1 > enemyY && ballY - 1 < enemyY + playerLength - 1)
      {
        ballVectorX = 1;
      }
      else if(ballY - 1 == enemyY + playerLength - 1)
      {
        ballVectorX = 1;
        ballVectorY = 1;
      }
    }
  }
   
  // Right wall
  if(ballX == 127)
  {
    resetGame();
  }

  // Left wall
  else if(ballX == 0)
  {
    playerScore += 2;
    resetGame(false);
  }

  // Update ball and players speed
  ballUpdateTimer.setPeriod(1000 / (initialBallSpeed + floor(playerScore / 2)));
  playerUpdateTimer.setPeriod(1000 / (initialPlayerSpeed + floor(playerScore / 4)));
  enemyUpdateTimer.setPeriod(1000 / (initialEnemySpeed + floor(playerScore / 4)));

  // Update ball position
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
    if(bBtn.click()) {return;}
    if(aBtn.click()) {resetGame();}

    if(playerUpdateTimer.tick())
    {
      if(upBtn.read() && playerY > 0)
      {
        playerY--;
      }
      
      if(downBtn.read() && playerY < 64 - playerLength)
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
      else if(ballY > enemyY + playerLength / 2 && enemyY + playerLength < 64)
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
