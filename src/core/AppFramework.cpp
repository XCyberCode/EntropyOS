// Header
#include <core/AppFramework.hpp>

// Libraries
#include <U8g2lib.h>

// Local dependencies
#include <core/HardwareManager.hpp>

// Get vertical position of the text
short getVerticalPosition(
  short positionY, 
  short height, 
  const char * text, 
  short mode,
  short offset = 0
)
{
  if(mode == 1) {return positionY + 7 + offset;}
  else if(mode == 2) {return positionY + floor(height / 2) + 4;}
  else if(mode == 3) {return positionY + height - offset;}
  return 0;
}

// Get horizontal position of the text
short getHorizontalPosition(
  short positionX, 
  short width, 
  const char * text, 
  short mode, 
  short textWidth,
  short offset = 0
)
{
  if(mode == 1) {return positionX + offset;}
  else if(mode == 2) {return positionX + width / 2 - textWidth / 2;}
  else if(mode == 3) {return positionX + width - textWidth - offset;}
  return 0;
}

// Draw Button widget
void Button::draw(const char * text)
{
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
void TextLabel::draw(const char * text)
{
  disp.setDrawColor(2);
  disp.drawStr(
    getHorizontalPosition(_positionX, _width, text, _textAnchorH, disp.getUTF8Width(text)), 
    getVerticalPosition(_positionY, _height, text, _textAnchorV),
    text
  );
  disp.setDrawColor(1);
}

// Draw Icon widget
void Icon::draw(unsigned char image[])
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

// Draw Checkbox widget
void Checkbox::draw()
{
  disp.drawRFrame(_positionX, _positionY, _width, _height, _cornerRadius);
  if(_isChecked)
  {
    disp.drawLine(_positionX + floor((_width - 1) / 2), _positionY + _height - 3, _positionX + floor((_width - 1) / 2) - 2, _positionY + _height - 5);
    disp.drawLine(_positionX + floor((_width - 1) / 2), _positionY + _height - 3, _positionX + floor((_width - 1) / 2) + 4, _positionY + _height - 7);
  }
}
