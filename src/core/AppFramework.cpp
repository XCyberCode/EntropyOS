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
  String text, 
  String mode,
  short offset = 0
)
{
  if(mode == "top") {return positionY + 7 + offset;}
  else if(mode == "center") {return positionY + floor(height / 2) + 4;}
  else if(mode == "bottom") {return positionY + height - offset;}
  return 0;
}

// Get horizontal position of the text
short getHorizontalPosition(
  short positionX, 
  short width, 
  String text, 
  String mode, 
  short textWidth,
  short offset = 0
)
{
  if(mode == "left") {return positionX + offset;}
  else if(mode == "center") {return positionX + width / 2 - textWidth / 2;}
  else if(mode == "right") {return positionX + width - textWidth - offset;}
  return 0;
}

// Draw Button widget
void Button::draw()
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
    getHorizontalPosition(_positionX, _width, _text, _textAnchorH, disp.getUTF8Width(_text.c_str()), 2), 
    getVerticalPosition(_positionY, _height, _text, _textAnchorV, 2), 
    _text.c_str()
  );
  disp.setDrawColor(1);
}

// Draw TextLabel widget
void TextLabel::draw()
{
  disp.setDrawColor(2);
  disp.drawStr(
    getHorizontalPosition(_positionX, _width, _text, _textAnchorH, disp.getUTF8Width(_text.c_str())), 
    getVerticalPosition(_positionY, _height, _text, _textAnchorV),
    _text.c_str()
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
