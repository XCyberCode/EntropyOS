// Header
#include <core/HardwareManager.hpp>

// Libraries
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp(U8G2_R0);

EncButton<EB_TICK, 27> leftBtn;
EncButton<EB_TICK, 26> upBtn;
EncButton<EB_TICK, 25> rightBtn;
EncButton<EB_TICK, 16> downBtn;
EncButton<EB_TICK, 32> aBtn;
EncButton<EB_TICK, 33> bBtn;
