// Note: size[] = {width, height}
#include <U8g2lib.h>

// Include guard
#ifndef APP_FRAMEWORK_H
#define APP_FRAMEWORK_H
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp;
#endif

class AppFramework
{
  public:
    // Duplicate methods from olikraus' u8g2 library
    void begin(); // Begin display
    void sendBuffer(); // Send data to display
    void clearBuffer(); // Clear buffer
    int getStrWidth(String str); // Get string width (cyrillic or not)
};

class Button
{
  public:
    // Vars
    String text = "N";
    short sizeX, sizeY; // Width, height 
    short positionX, positionY; // X, y
    String anchor = "center"; // Can be: left, center, right
    String textAnchor = "up"; // Can be: up, center, down
    // String callback;
    bool isHighlighted = false;
    String frameType = "rectangle"; // Can be: none, rectangle, rounded
    bool isFramedOutside = false;

    // Methods
    void draw();
};

class TextLabel
{
  public:
    // Vars
    String text = "N";
    short size[2] = {2, 2}; // Width, height
    short position[2] = {0, 0}; // X, y
    String anchor = "center"; // Can be: left, center, right
    bool isCentered = false;
    String frameType = "none"; // Can be: none, rectangle, rounded, round
    bool isFramedOutside = false;
    
    // Methods
    void draw();
};

class Icon
{
  public:
    // Vars
    short size[2] = {8, 8}; // Width, height
    short position[2] = {0, 0}; // X, y
    String frameType = "none"; // Can be: none, rectangle, rounded, round
    bool isFramedOutside = false;

    // Methods
    void draw(unsigned char image[]);
};

