// Libraries
#include <Arduino.h>

// Local dependencies
#include <core/HardwareManager.hpp>

#ifndef APP_FRAMEWORK_H
#define APP_FRAMEWORK_H
class Button
{
  private:
    String text; // Text of the widget
    short width, height; // Size of the widget
    short positionX, positionY; // Position of the widget 
    String textAnchorV; // Vertical position of the widget text. Can be: up, center, down
    String textAnchorH; // Horizontal position ot the widget text. Can be: right, center, left
    bool isFocus; // If true, a button's content color will be inverted
    bool isFramed; // If true, a border will be drawn
    short cornerRadius; // Radius of the corners

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
        String _textAnchorH = "center",
        bool _isFocus = false,
        bool _isFramed = true
    )
    {
      setPosition(_positionX, _positionY);
      setSize(_width, _height);
      setCornerRadius(_cornerRadius);
      setText(_text);
      setTextAnchor(_textAnchorV, _textAnchorH);
      setFocus(_isFocus);
      setFrame(_isFramed);
    }
    
    // Draw configured widget
    void draw();
   
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

    // Set position of the widget
    void setPosition(short _positionX, short _positionY)
    {
      positionX = _positionX;
      positionY = _positionY;
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

    // Set frame state of the widget
    void setFrame(bool _isFramed)
    {
      isFramed = _isFramed;
    }
};

class TextLabel
{
  private:
    String text = "NONE"; // Text of the widget
    short width, height; // Size of the widget
    short positionX, positionY; // Position of the widget
    String textAnchorV = "center"; // Vertical position of the widget text. Can be: top, center, bottom
    String textAnchorH = "center"; // Horizontal position of the widget text. Can be right, center, left
       
  public:
    // Constructor
    TextLabel(
        short _positionX = 0, 
        short _positionY = 0,
        short _width = 0,
        short _height = 0,
        String _text = "NONE",
        String _textAnchorV = "center",
        String _textAnchorH = "center"
    )
    {
      setPosition(_positionX, _positionY);
      setSize(_width, _height);
      setText(_text);
      setTextAnchor(_textAnchorV, _textAnchorH);
    }
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
  private:
    short width, height; // Size of the widget
    short positionX, positionY; // Position of the widget
    bool isFramed; // If true, a border will be drawn

  public:
    // Constructor
    Icon(
        short _positionX = 0, 
        short _positionY = 0, 
        short _width = 0, 
        short _height = 0,
        bool _isFramed = false
    )
    {
      setPosition(_positionX, _positionX);
      setSize(_width, _height);
      setFrame(_isFramed);
    }
    // Draw configured widget. The target icon is excepted as an argument
    void draw(unsigned char image[]);

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

    // Set position of the widget
    void setPosition(short _positionX, short _positionY)
    {
      setPositionX(_positionX);
      setPositionY(_positionY);
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
      setHeight(_width);
    }

    // Set frame state of the widget
    void setFrame(bool _isFramed)
    {
      isFramed = _isFramed;
    }
};

class Timer
{
  private:
    uint32_t timerTime = 0; // Time, elapsed by timer
    uint32_t timerPeriod = 100; // Round time of the timer
    bool isRunning; // Current state of the timer 
    bool isTimer;  // If true, timer will be stopped after one round
  
  public:
    // Constructor
    Timer(uint32_t _timerPeriod = 100, bool _isRunning = 0, bool _isTimer = 0)
    {
      timerPeriod = _timerPeriod;
      isRunning = _isRunning;
      isTimer = _isTimer;
    }

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
