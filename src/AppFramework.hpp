#include <U8g2lib.h>

// Include guard
#ifndef APP_FRAMEWORK_H
#define APP_FRAMEWORK_H
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp;
#endif

class AppFramework
{
  public:
    // void begin(); // Begin display
    // void sendBuffer(); // Send data to display
    // void clearBuffer(); // Clear buffer
};

class Button
{
  public:
    // Vars
    String text = "NONE"; // Widget text
    short width, height; // Widget size 
    short positionX, positionY; // Widget position 
    String textAnchorV = "center"; // Widget vertical text position. Can be: up, center, down
    String textAnchorH = "center"; // Widget horizontal text position. Can be: right, center, left
    bool isHighlighted = false; // If true, a button's content color will be inverted
    // REPLACED. String frameType = "rectangle"; // Button border style. Can be: none, rectangle, rounded, round
    bool isFramed = true; // If true, a border will be drawn
    short cornerRadius = 0; // Corner radius
    // bool isFramedOutside = false; // If true, a border will be drawn around widget

    // Methods
    void draw(); // Draw configured widget
};

class TextLabel
{
  public:
    // Vars
    String text = "N"; // Widget text
    short width, height; // Widget size
    short positionX, positionY; // Widget position
    String textAnchor = "center"; // Widget text position. Can be: left, center, right
    String frameType = "none"; // Widget border type. Can be: none, rectangle, rounded, round
    bool isFramedOutside = false; // If true, a border will be drawn around the widget
    
    // Methods
    void draw(); // Draw configured widget
};

class Icon
{
  public:
    // Vars
    short width, height; // Widget size
    short positionX, positionY; // Widget position
    String frameType = "none"; // Widget border type. Can be: none, rectangle, rounded, round
    bool isFramedOutside = false; // If true, a border will be drawn around the widget

    // Methods
    void draw(unsigned char image[]); // Draw configured widget. The target icon is excepted as an argument
};

