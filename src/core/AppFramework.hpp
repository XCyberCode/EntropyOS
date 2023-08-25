// Libraries
#include <Arduino.h>

// Local dependencies
#include <core/HardwareManager.hpp>

// Include guard
#ifndef APP_FRAMEWORK_H
#define APP_FRAMEWORK_H

class Button
{
  private:
    uint16_t _width, _height; // Size of the widget
    uint16_t _positionX, _positionY; // Position of the widget 
    uint8_t _textAnchorV; // Vertical position of the widget text. Can be: 1 - up, 2 - center, 3 - down
    uint8_t _textAnchorH; // Horizontal position ot the widget text. Can be: 1 - right, 2 - center, 3 - left
    bool _isFocused; // If true, a button content color will be inverted
    bool _isBordered; // If true, a border will be drawn
    uint16_t _cornerRadius; // Radius of the corners

  public:
    // Constructor
    Button(
        uint16_t positionX = 0, 
        uint16_t positionY = 0, 
        uint16_t width = 0, 
        uint16_t height = 0, 
        uint16_t cornerRadius = 0,  
        uint8_t textAnchorV = 2, 
        uint8_t textAnchorH = 2,
        bool isFocused = false,
        bool isBordered = true
    )
    {
      setPosition(positionX, positionY);
      setSize(width, height);
      setCornerRadius(cornerRadius);
      setTextAnchor(textAnchorV, textAnchorH);
      setFocus(isFocused);
      setFrame(isBordered);
    }
    
    // Draw configured widget
    void draw(const char *);
   
    // Set horizontal position of the widget
    void setPositionX(uint16_t positionX)
    {
      if(positionX >= 0)
      {
        _positionX = positionX;
      }
    }

    // Set vertical position of the widget
    void setPositionY(uint16_t positionY)
    {
      if(positionY >= 0)
      {
        _positionY = positionY;
      }
    }

    // Set position of the widget
    void setPosition(uint16_t positionX, uint16_t positionY)
    {
      _positionX = positionX;
      _positionY = positionY;
    }

    // Set width of the widget
    void setWidth(uint16_t width)
    {
      if(width >= 0)
      {
        _width = width;
      }
    }

    // Set height of the widget
    void setHeight(uint16_t height)
    {
      if(height >= 0)
      {
        _height = height;
      }
    }

    // Set size of the widget
    void setSize(uint16_t width, uint16_t height)
    {
      setWidth(width);
      setHeight(height);
    }

    // Set vertical text acnhor of the widget
    void setTextAnchorV(uint8_t textAnchorV)
    {
      _textAnchorV = textAnchorV;
    }

    // Set horizontal text anchor of the widget
    void setTextAnchorH(uint8_t textAnchorH)
    {
      _textAnchorH = textAnchorH;
    }

    // Set text anchor of the widget
    void setTextAnchor(uint8_t textAnchorV, uint8_t textAnchorH)
    {
      setTextAnchorV(textAnchorV);
      setTextAnchorH(textAnchorH);
    }

    // Set corner radius of the widget
    void setCornerRadius(uint16_t cornerRadius)
    {
      if(cornerRadius >= 0)
      {
        _cornerRadius = cornerRadius;
      }
    }

    // Set content highlight state of the widget
    void setFocus(bool isFocused) {_isFocused = isFocused;}

    // Invert content highlight state of the widget
    void invertFocus() {_isFocused = !_isFocused;}

    // Set frame state of the widget
    void setFrame(bool isBordered)
    {
      _isBordered = isBordered;
    }
};

class TextLabel
{
  private:
    uint16_t _width, _height; // Size of the widget
    uint16_t _positionX, _positionY; // Position of the widget
    // Vertical position of the widget text. Can be: 1 - top, 2 - center, 3 - bottom
    uint8_t _textAnchorV = 2;
    // Horizontal position of the widget text. Can be 1 - right, 2 - center, 3 - left
    uint8_t _textAnchorH = 2; 
       
  public:
    // Constructor
    TextLabel(
        uint16_t positionX = 0, 
        uint16_t positionY = 0,
        uint16_t width = 0,
        uint16_t height = 0,
        uint8_t textAnchorV = 2,
        uint8_t textAnchorH = 2
    )
    {
      setPosition(positionX, positionY);
      setSize(width, height);
      setTextAnchor(textAnchorV, textAnchorH);
    }
    // Draw configured widget
    void draw(const char *);

    // Set width of the widget
    void setWidth(uint16_t width)
    {
      if(width >= 0)
      {
        _width = width;
      }
    }

    // Set height of the widget
    void setHeight(uint16_t height)
    {
      if(height >= 0)
      {
        _height = height;
      }
    }

    // Set size of the widget
    void setSize(uint16_t width, uint16_t height)
    {
      setWidth(width);
      setHeight(height);
    }

    // Set vertical position of the widget
    void setPositionX(uint16_t positionX)
    {
      if(positionX >= 0)
      {
        _positionX = positionX;
      }
    }

    // Set horizontal position of the widget
    void setPositionY(uint16_t positionY)
    {
      if(positionY >= 0)
      {
        _positionY = positionY;
      }
    }

    // Set position of the widget
    void setPosition(uint16_t positionX, uint16_t positionY)
    {
      setPositionX(positionX);
      setPositionY(positionY);
    }

    // Set vertical text anchor of the widget
    void setTextAnchorV(uint8_t textAnchorV)
    {
      _textAnchorV = textAnchorV;
    }

    // Set horizontal text anchor of the widget
    void setTextAnchorH(uint8_t textAnchorH)
    {
      _textAnchorH = textAnchorH;
    }

    // Set text anchors of the widget
    void setTextAnchor(uint8_t textAnchorV, uint8_t textAnchorH)
    {
      setTextAnchorV(textAnchorV);
      setTextAnchorH(textAnchorH);
    }
};

class Icon
{
  private:
    uint16_t _width, _height; // Size of the widget
    uint16_t _positionX, _positionY; // Position of the widget
    bool _isBordered; // If true, a border will be drawn
    uint16_t _borderPadding; // Padding between border and content
    uint16_t _cornerRadius; // Radius of the border corners

  public:
    // Constructor
    Icon(
        uint16_t positionX = 0, 
        uint16_t positionY = 0, 
        uint16_t width = 0, 
        uint16_t height = 0,
        bool isBordered = false,
        uint16_t cornerRadius = 0,
        uint16_t borderPadding = 0
    )
    {
      setPosition(positionX, positionY);
      setSize(width, height);
      setBorder(isBordered);
      setCornerRadius(cornerRadius);
      setBorderPadding(borderPadding);
    }
    // Draw configured widget. The target icon is excepted as an argument
    void draw(unsigned char image[]);

    // Set horizontal position of the widget
    void setPositionX(uint16_t positionX)
    {
      if(positionX >= 0)
      {
        _positionX = positionX;
      }
    }

    // Set vertical position of the widget
    void setPositionY(uint16_t positionY)
    {
      if(positionY >= 0)
      {
        _positionY = positionY;
      }
    }

    // Set position of the widget
    void setPosition(uint16_t positionX, uint16_t positionY)
    {
      setPositionX(positionX);
      setPositionY(positionY);
    }

    // Set width of the widget
    void setWidth(uint16_t width)
    {
      if(width >= 0)
      {
        _width = width;
      }
    }

    // Set height of the widget
    void setHeight(uint16_t height)
    {
      if(height >= 0)
      {
        _height = height;
      }
    }

    // Set size of the widget
    void setSize(uint16_t width, uint16_t height)
    {
      setWidth(width);
      setHeight(width);
    }

    // Set frame state of the widget
    void setBorder(bool isBordered)
    {
      _isBordered = isBordered;
    }

    // Set radius of the border corners
    void setCornerRadius(uint16_t cornerRadius)
    {
      if(cornerRadius >= 0)
      {
        _cornerRadius = cornerRadius;
      }
    }

    // Set padding between border and content
    void setBorderPadding(uint16_t borderPadding)
    {
      if(borderPadding >= 0)
      {
        _borderPadding = borderPadding;
      }
    }
};

class Timer
{
  private:
    uint32_t _timerTime = 0; // Time, elapsed by timer
    uint32_t _timerPeriod = 100; // Round time of the timer
    bool _isRunning; // Current state of the timer 
    bool _isTimer;  // If true, timer will be stopped after one round
  
  public:
    // Constructor
    Timer(uint32_t timerPeriod = 100, bool isRunning = 0, bool isTimer = 0)
    {
      _timerPeriod = timerPeriod;
      _isRunning = isRunning;
      _isTimer = isTimer;
    }

    // Start timer
    void start() {
      _isRunning = true;
      _timerTime = millis();
    };

    // Stop timer
    void stop() {_isRunning = false;};
    
    // Set timer mode
    void setMode(bool isTimer) {_isTimer = isTimer;};
    
    // Check timer state
    bool tick()
    {
      if(_isRunning && millis() - _timerTime >= _timerPeriod)
      {
        if(_isTimer)
        {
          _isRunning = false;
          return true;
        }
        _timerTime = millis();
        return true;
      }
      return false;
    };
};
#endif
