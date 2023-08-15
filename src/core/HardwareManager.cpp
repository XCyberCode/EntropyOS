// Header
#include <core/HardwareManager.hpp>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp(U8G2_R0);

EncButton<EB_TICK, LEFT_BTN_PIN> leftBtn;
EncButton<EB_TICK, UP_BTN_PIN> upBtn;
EncButton<EB_TICK, RIGHT_BTN_PIN> rightBtn;
EncButton<EB_TICK, DOWN_BTN_PIN> downBtn;
EncButton<EB_TICK, A_BTN_PIN> aBtn;
EncButton<EB_TICK, B_BTN_PIN> bBtn;

DS1307 clockModule;

Preferences storage;
