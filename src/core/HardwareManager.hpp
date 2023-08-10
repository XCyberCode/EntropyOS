// Libraries
#include <U8g2lib.h>
#include <EncButton.h>

// Include guard
#ifndef HARDWARE_MANAGER_H
#define HARDWARE_MANAGER_H

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp;
extern EncButton<EB_TICK, 27> leftBtn;
extern EncButton<EB_TICK, 26> upBtn;
extern EncButton<EB_TICK, 25> rightBtn;
extern EncButton<EB_TICK, 19> downBtn;
extern EncButton<EB_TICK, 32> aBtn;
extern EncButton<EB_TICK, 33> bBtn; 

static void tickAll()
{
  leftBtn.tick();
  upBtn.tick();
  rightBtn.tick();
  downBtn.tick();
  aBtn.tick();
  bBtn.tick();
}

static void beginHardware()
{
  disp.begin();
  disp.setFontMode(1);
}

#endif
