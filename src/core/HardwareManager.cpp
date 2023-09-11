// Header
#include <core/HardwareManager.hpp>

// Libraries
#include <U8g2lib.h>
#include <EncButton.h>
#include <Preferences.h>

// Local dependencies
#include <core/Pins.h>

// Drivers
#include <lib/DS1307.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp(U8G2_R0);

Button leftBtn(LEFT_BTN_PIN);
Button upBtn(UP_BTN_PIN);
Button rightBtn(RIGHT_BTN_PIN);
Button downBtn(DOWN_BTN_PIN);
Button aBtn(A_BTN_PIN);
Button bBtn(B_BTN_PIN);

DS1307 clockModule;

Preferences storage;
