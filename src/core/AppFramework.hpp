// Libraries
#include <Arduino.h>

// Local dependencies
#include <core/HardwareManager.hpp>

#ifndef APP_FRAMEWORK_H
#define APP_FRAMEWORK_H
class Button
{
  private:
    // Vars
    String text = "NONE"; // Text of the widget
    short width, height; // Size of the widget
    short positionX, positionY; // Position of the widget 
    String textAnchorV = "center"; // Vertical position of the widget text. Can be: up, center, down
    String textAnchorH = "center"; // Horizontal position ot the widget text. Can be: right, center, left
    bool isFocus = false; // If true, a button's content color will be inverted
    bool isFramed = true; // If true, a border will be drawn
    short cornerRadius = 0; // Radius of the corners

  public:
    // Constructor
    Button(
        short _positionX = 0, 
        short _positionY = 0, 
        short _width = 0, 
        short _height = 0, 
        short _cornerRadius = 0, 
        String _text = "NONE", 
        String _textAnchorV = "center", 
        String _textAnchorH = "center"
    )
    {
      setPosition(_positionX, _positionY);
      setSize(_width, _height);
      setCornerRadius(_cornerRadius);
      setText(_text);
      setTextAnchor(_textAnchorV, _textAnchorH);
    }
    
    // Methods
    void draw(); // Draw configured widget
    
    void setPosition(short _positionX, short _positionY)
    {
      positionX = _positionX;
      positionY = _positionY;
    }

    // Set horizontal position of the widget
    void setPositionX(short _positionX)
    {
      if(_positionX >= 0)
      {
        positionX = _positionX;
      }
    }

    // Set vertical position of the widget
    void setPositionY(short _positionY)
    {
      if(_positionY >= 0)
      {
        positionY = _positionY;
      }
    }

    // Set text of the widget
    void setText(String _text) {text = _text;}

    // Set vertical text acnhor of the widget
    void setTextAnchorV(String _textAnchorV)
    {
      textAnchorV = _textAnchorV;
    }

    // Set horizontal text anchor of the widget
    void setTextAnchorH(String _textAnchorH)
    {
      textAnchorH = _textAnchorH;
    }

    // Set text anchor of the widget
    void setTextAnchor(String _textAnchorV, String _textAnchorH)
    {
      setTextAnchorV(_textAnchorV);
      setTextAnchorH(_textAnchorH);
    }

    // Set width of the widget
    void setWidth(short _width)
    {
      if(_width >= 0)
      {
        width = _width;
      }
    }

    // Set height of the widget
    void setHeight(short _height)
    {
      if(_height >= 0)
      {
        height = _height;
      }
    }

    // Set size of the widget
    void setSize(short _width, short _height)
    {
      setWidth(_width);
      setHeight(_height);
    }

    // Set corner radius of the widget
    void setCornerRadius(short _radius)
    {
      if(_radius >= 0)
      {
        cornerRadius = _radius;
      }
    }

    // Set content highlight state of the widget
    void setFocus(bool _isFocus) {isFocus = _isFocus;}

    // Invert content highlight state of the widget
    void invertFocus() {isFocus = !isFocus;}
};

class TextLabel
{
  private:
    // Vars
    String text = "NONE"; // Text of the widget
    short width, height; // Size of the widget
    short positionX, positionY; // Position of the widget
    String textAnchorV = "center"; // Vertical position of the widget text. Can be: top, center, bottom
    String textAnchorH = "center"; // Horizontal position of the widget text. Can be right, center, left
       
  public:
    // Methods
    // Draw configured widget
    void draw();

    // Set width of the widget
    void setWidth(short _width)
    {
      if(_width >= 0)
      {
        width = _width;
      }
    }

    // Set height of the widget
    void setHeight(short _height)
    {
      if(_height >= 0)
      {
        height = _height;
      }
    }

    // Set size of the widget
    void setSize(short _width, short _height)
    {
      setWidth(_width);
      setHeight(_height);
    }

    // Set vertical position of the widget
    void setPositionX(short _positionX)
    {
      if(_positionX >= 0)
      {
        positionX = _positionX;
      }
    }

    // Set horizontal position of the widget
    void setPositionY(short _positionY)
    {
      if(_positionY >= 0)
      {
        positionY = _positionY;
      }
    }

    // Set position of the widget
    void setPosition(short _positionX, short _positionY)
    {
      setPositionX(_positionX);
      setPositionY(_positionY);
    }

    // Set text of the widget
    void setText(String _text)
    {
      text = _text;
    }

    // Set vertical text anchor of the widget
    void setTextAnchorV(String _textAnchorV)
    {
      textAnchorV = _textAnchorV;
    }

    // Set horizontal text anchor of the widget
    void setTextAnchorH(String _textAnchorH)
    {
      textAnchorH = _textAnchorH;
    }

    // Set text anchors of the widget
    void setTextAnchor(String _textAnchorV, String _textAnchorH)
    {
      setTextAnchorV(_textAnchorV);
      setTextAnchorH(_textAnchorH);
    }
};

class Icon
{
  public:
    // Vars
    short width, height; // Size of the widget
    short positionX, positionY; // Position of the widget
    bool isFramed = false; // If true, a border will be drawn

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
    // Start timer
    void start() {
      isRunning = true;
      timerTime = millis();
    };

    // Stop timer
    void stop() {isRunning = false;};
    
    // Set timer mode
    void setMode(bool _isTimer) {isTimer = _isTimer;};
    
    // Check timer state
    bool tick()
    {
      if(isRunning && millis() - timerTime >= timerPeriod)
      {
        if(isTimer)
        {
          isRunning = false;
          return true;
        }
        timerTime = millis();
        return true;
      }
      return false;
    };
};
#endif
