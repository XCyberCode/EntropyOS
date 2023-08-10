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
    String text = "NONE"; // Text of the widget
    short width, height; // Size of the widget
    short positionX, positionY; // Position of the widget 
    String textAnchorV = "center"; // Vertical position of the widget text. Can be: up, center, down
    String textAnchorH = "center"; // Horizontal position ot the widget text. Can be: right, center, left
    bool isHighlighted = false; // If true, a button's content color will be inverted
    bool isFramed = true; // If true, a border will be drawn
    short cornerRadius = 0; // Radius of the corners
    
    // Methods
    void draw(); // Draw configured widget
};

class TextLabel
{
  public:
    // Vars
    String text = "NONE"; // Text of the widget
    short width, height; // Size of the widget
    short positionX, positionY; // Position of the widget
    String textAnchorV = "center"; // Vertical position of the widget text. Can be: top, center, bottom
    String textAnchorH = "center"; // Horizontal position of the widget text. Can be right, center, left
    // DEPRECATED. Use Button instead. bool isFramed = true; // If true, a border will be drawn
    // DEPRECATED. Use Button instead. short cornerRadius = 0; // Corner radius
    
    // Methods
    void draw(); // Draw configured widget
};

class Icon
{
  public:
    // Vars
    short width, height; // Size of the widget
    short positionX, positionY; // Position of the widget
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
