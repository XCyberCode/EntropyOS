// Libraries
#include <U8g2lib.h>
#include <EncButton.h>
#include <Preferences.h>
#include <WiFi.h>

// Local dependencies
#include <core/Pins.h>

// Drivers
#include <lib/DS1307.h>

// Include guard
#ifndef HARDWARE_MANAGER_H
#define HARDWARE_MANAGER_H

extern Button leftBtn;
extern Button upBtn;
extern Button rightBtn;
extern Button downBtn;
extern Button aBtn;
extern Button bBtn;

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp;

extern DS1307 clockModule;

extern Preferences storage;

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
  // Set Modem-sleep mode for ESP32
  WiFi.setSleep(true);
  // setCpuFrequencyMhz(80);

  // Begin NVM Storage
  storage.begin("settings", false);

  // Begin I2C peripheral
  Wire.begin();

  // Begin display and configure font
  disp.begin();
  disp.setFont(u8g2_font_6x10_tf);
  disp.setFontMode(1);
}

#endif
