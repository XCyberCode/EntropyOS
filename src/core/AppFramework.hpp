// Libraries
#include <Arduino.h>

// Local dependencies
#include <core/HardwareManager.hpp>

#ifndef APP_FRAMEWORK_H
#define APP_FRAMEWORK_H
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
    bool isFramed = true; // If true, a border will be drawn
    short cornerRadius = 0; // Corner radius
    
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
    bool isFramed = true; // If true, a border will be drawn
    short cornerRadius = 0; // Corner radius
    // DEPRECATED. String frameType = "none"; // Widget border type. Can be: none, rectangle, rounded, round
    // UNUSED. bool isFramedOutside = false; // If true, a border will be drawn around the widget
    
    // Methods
    void draw(); // Draw configured widget
};

class Icon
{
  public:
    // Vars
    short width, height; // Widget size
    short positionX, positionY; // Widget position
    bool isFramed = true; // If true, a border will be drawn

    // Methods
    void draw(unsigned char image[]); // Draw configured widget. The target icon is excepted as an argument
};

class Timer
{
  private:
    // Vars
    uint32_t timerTime = 0, timerPeriod = 100;
    bool isRunning, isTimer; 
  
  public:
    // Constructor
    Timer(uint32_t _timerPeriod = 100, bool _isRunning = 0, bool _isTimer = 0)
    {
      timerPeriod = _timerPeriod;
      isRunning = _isRunning;
      isTimer = _isTimer;
    }

    // Methods
    void start();
    void stop();
    void setMode(bool _isTimer);
    bool tick();
};
#endif
