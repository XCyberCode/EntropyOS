// Libraries
#include <Arduino.h>

// Local dependencies
#include <core/HardwareManager.hpp>

#ifndef APPFRAMEWORKH
#define APPFRAMEWORKH
class Button
{
  private:
    String _text; // Text of the widget
    short _width, _height; // Size of the widget
    short _positionX, _positionY; // Position of the widget 
    String _textAnchorV; // Vertical position of the widget text. Can be: up, center, down
    String _textAnchorH; // Horizontal position ot the widget text. Can be: right, center, left
    bool _isFocused; // If true, a button content color will be inverted
    bool _isBordered; // If true, a border will be drawn
    short _cornerRadius; // Radius of the corners

  public:
    // Constructor
    Button(
        short positionX = 0, 
        short positionY = 0, 
        short width = 0, 
        short height = 0, 
        short cornerRadius = 0, 
        String text = "NONE", 
        String textAnchorV = "center", 
        String textAnchorH = "center",
        bool isFocused = false,
        bool isBordered = true
    )
    {
      setPosition(positionX, positionY);
      setSize(width, height);
      setCornerRadius(cornerRadius);
      setText(text);
      setTextAnchor(textAnchorV, textAnchorH);
      setFocus(isFocused);
      setFrame(isBordered);
    }
    
    // Draw configured widget
    void draw();
   
    // Set horizontal position of the widget
    void setPositionX(short positionX)
    {
      if(positionX >= 0)
      {
        _positionX = positionX;
      }
    }

    // Set vertical position of the widget
    void setPositionY(short positionY)
    {
      if(positionY >= 0)
      {
        _positionY = positionY;
      }
    }

    // Set position of the widget
    void setPosition(short positionX, short positionY)
    {
      _positionX = positionX;
      _positionY = positionY;
    }

    // Set width of the widget
    void setWidth(short width)
    {
      if(width >= 0)
      {
        _width = width;
      }
    }

    // Set height of the widget
    void setHeight(short height)
    {
      if(height >= 0)
      {
        _height = height;
      }
    }

    // Set size of the widget
    void setSize(short width, short height)
    {
      setWidth(width);
      setHeight(height);
    }

    // Set text of the widget
    void setText(String text) {_text = text;}

    // Set vertical text acnhor of the widget
    void setTextAnchorV(String textAnchorV)
    {
      _textAnchorV = textAnchorV;
    }

    // Set horizontal text anchor of the widget
    void setTextAnchorH(String textAnchorH)
    {
      _textAnchorH = textAnchorH;
    }

    // Set text anchor of the widget
    void setTextAnchor(String textAnchorV, String textAnchorH)
    {
      setTextAnchorV(textAnchorV);
      setTextAnchorH(textAnchorH);
    }

    // Set corner radius of the widget
    void setCornerRadius(short cornerRadius)
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
    String _text = "NONE"; // Text of the widget
    short _width, _height; // Size of the widget
    short _positionX, _positionY; // Position of the widget
    String _textAnchorV = "center"; // Vertical position of the widget text. Can be: top, center, bottom
    String _textAnchorH = "center"; // Horizontal position of the widget text. Can be right, center, left
       
  public:
    // Constructor
    TextLabel(
        short positionX = 0, 
        short positionY = 0,
        short width = 0,
        short height = 0,
        String text = "NONE",
        String textAnchorV = "center",
        String textAnchorH = "center"
    )
    {
      setPosition(positionX, positionY);
      setSize(width, height);
      setText(text);
      setTextAnchor(textAnchorV, textAnchorH);
    }
    // Draw configured widget
    void draw();

    // Set width of the widget
    void setWidth(short width)
    {
      if(width >= 0)
      {
        _width = width;
      }
    }

    // Set height of the widget
    void setHeight(short height)
    {
      if(height >= 0)
      {
        _height = height;
      }
    }

    // Set size of the widget
    void setSize(short width, short height)
    {
      setWidth(width);
      setHeight(height);
    }

    // Set vertical position of the widget
    void setPositionX(short positionX)
    {
      if(positionX >= 0)
      {
        _positionX = positionX;
      }
    }

    // Set horizontal position of the widget
    void setPositionY(short positionY)
    {
      if(positionY >= 0)
      {
        _positionY = positionY;
      }
    }

    // Set position of the widget
    void setPosition(short positionX, short positionY)
    {
      setPositionX(positionX);
      setPositionY(positionY);
    }

    // Set text of the widget
    void setText(String text)
    {
      _text = text;
    }

    // Set vertical text anchor of the widget
    void setTextAnchorV(String textAnchorV)
    {
      _textAnchorV = textAnchorV;
    }

    // Set horizontal text anchor of the widget
    void setTextAnchorH(String textAnchorH)
    {
      _textAnchorH = textAnchorH;
    }

    // Set text anchors of the widget
    void setTextAnchor(String textAnchorV, String textAnchorH)
    {
      setTextAnchorV(textAnchorV);
      setTextAnchorH(textAnchorH);
    }
};

class Icon
{
  private:
    short _width, _height; // Size of the widget
    short _positionX, _positionY; // Position of the widget
    bool _isBordered; // If true, a border will be drawn
    short _borderPadding; // Padding between border and content
    short _cornerRadius; // Radius of the border corners

  public:
    // Constructor
    Icon(
        short positionX = 0, 
        short positionY = 0, 
        short width = 0, 
        short height = 0,
        bool isBordered = false,
        short cornerRadius = 0,
        short borderPadding = 0
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
    void setPositionX(short positionX)
    {
      if(positionX >= 0)
      {
        _positionX = positionX;
      }
    }

    // Set vertical position of the widget
    void setPositionY(short positionY)
    {
      if(positionY >= 0)
      {
        _positionY = positionY;
      }
    }

    // Set position of the widget
    void setPosition(short positionX, short positionY)
    {
      setPositionX(positionX);
      setPositionY(positionY);
    }

    // Set width of the widget
    void setWidth(short width)
    {
      if(width >= 0)
      {
        _width = width;
      }
    }

    // Set height of the widget
    void setHeight(short height)
    {
      if(height >= 0)
      {
        _height = height;
      }
    }

    // Set size of the widget
    void setSize(short width, short height)
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
    void setCornerRadius(short cornerRadius)
    {
      if(cornerRadius >= 0)
      {
        _cornerRadius = cornerRadius;
      }
    }

    // Set padding between border and content
    void setBorderPadding(short borderPadding)
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

class Checkbox
{
  private:
    short _positionX, _positionY;
    short _width, _height;
    String _text;
    bool _isChecked;
    short _cornerRadius;

  public:
    // Constructor
    Checkbox(
      short positionX, 
      short positionY, 
      short width, 
      short height, 
      bool isChecked, 
      short cornerRadius, 
      String text
    )
    {
      setPosition(positionX, positionY);
      setSize(width, height);
      setText(text);
      setCheck(isChecked);
      setCornerRadius(cornerRadius);
    }
    
    // Draw configured widget
    void draw();

    // Set horizontal position of the widget
    void setPositionX(short positionX)
    {
      if(positionX >= 0)
      {
        _positionX = positionX;
      }
    }

    // Set vertical position of the widget
    void setPositionY(short positionY)
    {
      if(positionY >= 0)
      {
        _positionY = positionY;
      }
    }

    // Set position of the widget
    void setPosition(short positionX, short positionY)
    {
      setPositionX(positionX);
      setPositionY(positionY);
    }

    // Set width of the widget
    void setWidth(short width)
    {
      if(width >= 0)
      {
        _width = width;
      }
    }

    // Set height of the widget
    void setHeight(short height)
    {
      if(height >= 0)
      {
        _height = height;
      }
    }

    // Set size of the widget
    void setSize(short width, short height)
    {
      setWidth(width);
      setHeight(width);
    }

    // Set radius of the border corners
    void setCornerRadius(short cornerRadius)
    {
      if(cornerRadius >= 0)
      {
        _cornerRadius = cornerRadius;
      }
    }
    // Set text of the widget
    void setText(String text)
    {
      _text = text;
    }

    // Set widget state
    void setCheck(bool isChecked)
    {
      _isChecked = isChecked;
    }
};

#endif
