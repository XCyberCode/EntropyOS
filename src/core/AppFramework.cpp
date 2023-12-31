// Header
#include <core/AppFramework.hpp>

// Libraries
#include <U8g2lib.h>

// Local dependencies
#include <core/HardwareManager.hpp>

// Get vertical position of the text
uint16_t getVerticalPosition(
  uint16_t positionY, 
  uint16_t height, 
  const char * text, 
  uint8_t mode,
  uint16_t offset = 0
)
{
  if(mode == 1) {return positionY + 7 + offset;}
  else if(mode == 2) {return positionY + floor(height / 2) + 4;}
  else if(mode == 3) {return positionY + height - offset;}
  return 0;
}

// Get horizontal position of the text
uint16_t getHorizontalPosition(
  uint16_t positionX, 
  uint16_t width, 
  const char * text, 
  uint8_t mode, 
  uint16_t textWidth,
  uint16_t offset = 0
)
{
  if(mode == 1) {return positionX + offset;}
  else if(mode == 2) {return positionX + width / 2 - textWidth / 2;}
  else if(mode == 3) {return positionX + width - textWidth - offset;}
  return 0;
}

// Draw Button widget
void ButtonWidget::draw(const char * text)
{
  disp.setFont(u8g2_font_6x10_tf);
  // Draw frame or field
  if(_isFocused)
  {
    disp.drawRBox(_positionX, _positionY, _width, _height, _cornerRadius);
  }
  else if(_isBordered)
  {
    disp.drawRFrame(_positionX, _positionY, _width, _height, _cornerRadius);
  }

  disp.setDrawColor(2);
  disp.drawStr(
    getHorizontalPosition(_positionX, _width, text, _textAnchorH, disp.getUTF8Width(text), 2), 
    getVerticalPosition(_positionY, _height, text, _textAnchorV, 2), 
    text
  );
  disp.setDrawColor(1);
}

void ButtonWidget::draw(const char * text, const uint8_t * font)
{
  disp.setFont(font);
  // Draw frame or field
  if(_isFocused)
  {
    disp.drawRBox(_positionX, _positionY, _width, _height, _cornerRadius);
  }
  else if(_isBordered)
  {
    disp.drawRFrame(_positionX, _positionY, _width, _height, _cornerRadius);
  }

  disp.setDrawColor(2);
  disp.drawStr(
    getHorizontalPosition(_positionX, _width, text, _textAnchorH, disp.getUTF8Width(text), 2), 
    getVerticalPosition(_positionY, _height, text, _textAnchorV, 2), 
    text
  );
  disp.setDrawColor(1);
}

// Draw TextLabel widget
void TextLabelWidget::draw(const char * text)
{
  disp.setFont(u8g2_font_6x10_tf);
  disp.setDrawColor(2);
  disp.drawStr(
    getHorizontalPosition(_positionX, _width, text, _textAnchorH, disp.getUTF8Width(text)), 
    getVerticalPosition(_positionY, _height, text, _textAnchorV),
    text
  );
  disp.setDrawColor(1);
}

void TextLabelWidget::draw(const char * text, const uint8_t * font)
{
  disp.setFont(font);
  disp.setDrawColor(2);
  disp.drawStr(
    getHorizontalPosition(_positionX, _width, text, _textAnchorH, disp.getUTF8Width(text)), 
    getVerticalPosition(_positionY, _height, text, _textAnchorV),
    text
  );
  disp.setDrawColor(1);
}

// Draw Icon widget
void IconWidget::draw(unsigned char image[])
{
  disp.drawXBMP(_positionX, _positionY, _width, _height, image);
  if(_isBordered)
  {
    disp.drawRFrame(
      _positionX - _borderPadding, 
      _positionY - _borderPadding, 
      _width + _borderPadding * 2 + 1,
      _height + _borderPadding * 2, 
      _cornerRadius
    );
  }
}
