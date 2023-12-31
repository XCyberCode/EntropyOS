// Libraries
#include <Arduino.h>

// Local dependencies
#include <core/HardwareManager.hpp>

// Include guard
#ifndef APP_FRAMEWORK_H
#define APP_FRAMEWORK_H

class WidgetTransform 
{
  protected:
    uint16_t _width, _height;
    uint16_t _positionX, _positionY;
  public:
    void setPositionX(uint16_t positionX)
    {
      if(positionX >= 0)
      {
        _positionX = positionX;
      }
    }

    void setPositionY(uint16_t positionY)
    {
      if(positionY >= 0)
      {
        _positionY = positionY;
      }
    }

    void setPosition(uint16_t positionX, uint16_t positionY)
    {
      setPositionX(positionX);
      setPositionY(positionY);
    }

    void setWidth(uint16_t width)
    {
      if(width >= 0)
      {
        _width = width;
      }
    }

    void setHeight(uint16_t height)
    {
      if(height >= 0)
      {
        _height = height;
      }
    }

    void setSize(uint16_t width, uint16_t height)
    {
      setWidth(width);
      setHeight(height);
    }

    uint16_t getWidth() {return _width;}
    uint16_t getHeight() {return _height;}
    uint16_t getPositionX() {return _positionX;}
    uint16_t getPositionY() {return _positionY;}
};

class ButtonWidget : public WidgetTransform
{
  private: 
    uint8_t _textAnchorV;
    uint8_t _textAnchorH;
    bool _isFocused; // If true, a button content color will be inverted
    bool _isBordered;
    uint16_t _cornerRadius;

  public:
    ButtonWidget(
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
      setBorder(isBordered);
    }
    
    void draw(const char *);
    void draw(const char *, const uint8_t *);

    // 1 - top, 2 - center, 3 - bottom
    void setTextAnchorV(uint8_t textAnchorV)
    {
      _textAnchorV = textAnchorV;
    }

    // 1 - left, 2 - center, 3 - right
    void setTextAnchorH(uint8_t textAnchorH)
    {
      _textAnchorH = textAnchorH;
    }

    void setTextAnchor(uint8_t textAnchorV, uint8_t textAnchorH)
    {
      setTextAnchorV(textAnchorV);
      setTextAnchorH(textAnchorH);
    }

    void setCornerRadius(uint16_t cornerRadius)
    {
      if(cornerRadius >= 0)
      {
        _cornerRadius = cornerRadius;
      }
    }

    void setFocus(bool isFocused) {_isFocused = isFocused;}

    void invertFocus() {_isFocused = !_isFocused;}

    void setBorder(bool isBordered)
    {
      _isBordered = isBordered;
    }

    bool getBorder() {return _isBordered;}
    bool getFocus() {return _isFocused;}
};

class TextLabelWidget : public WidgetTransform
{
  private:
    uint8_t _textAnchorV = 2;
    uint8_t _textAnchorH = 2;
       
  public:
    TextLabelWidget(
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

    void draw(const char *);
    void draw(const char *, const uint8_t *);

    // 1 - top, 2 - center, 3 - bottom
    void setTextAnchorV(uint8_t textAnchorV)
    {
      _textAnchorV = textAnchorV;
    }

    // 1 - left, 2 - center, 3 - right
    void setTextAnchorH(uint8_t textAnchorH)
    {
      _textAnchorH = textAnchorH;
    }

    void setTextAnchor(uint8_t textAnchorV, uint8_t textAnchorH)
    {
      setTextAnchorV(textAnchorV);
      setTextAnchorH(textAnchorH);
    }
};

class IconWidget : public WidgetTransform
{
  private:
    bool _isBordered;
    uint16_t _borderPadding;
    uint16_t _cornerRadius;

  public:
    IconWidget(
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
    void draw(unsigned char image[]);

    void setBorder(bool isBordered)
    {
      _isBordered = isBordered;
    }

    void setCornerRadius(uint16_t cornerRadius)
    {
      if(cornerRadius >= 0)
      {
        _cornerRadius = cornerRadius;
      }
    }

    // Set padding between the border and the content
    void setBorderPadding(uint16_t borderPadding)
    {
      if(borderPadding >= 0)
      {
        _borderPadding = borderPadding;
      }
    }

    // Get different widget data
    bool getBorder() {return _isBordered;}
};

class ProgressWidget : public WidgetTransform
{
  private:
    uint8_t _progress;
};
#endif
