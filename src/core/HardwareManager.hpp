// Libraries
#include <U8g2lib.h>
#include <EncButton.h>

// Local dependencies
#include <core/Pins.hpp>

// Include guard
#ifndef HARDWARE_MANAGER_H
#define HARDWARE_MANAGER_H

extern EncButton<EB_TICK, LEFT_BTN_PIN> leftBtn;
extern EncButton<EB_TICK, UP_BTN_PIN> upBtn;
extern EncButton<EB_TICK, RIGHT_BTN_PIN> rightBtn;
extern EncButton<EB_TICK, DOWN_BTN_PIN> downBtn;
extern EncButton<EB_TICK, A_BTN_PIN> aBtn;
extern EncButton<EB_TICK, B_BTN_PIN> bBtn;

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp;

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
