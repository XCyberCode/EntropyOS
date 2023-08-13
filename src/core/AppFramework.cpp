// Header
#include <core/AppFramework.hpp>

// Libraries
#include <U8g2lib.h>

// Local dependencies
#include <core/HardwareManager.hpp>

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

  // Positioning of the text 
  short textX, textY;

  // Vertical positioning
  if(_textAnchorV == "top") {textY = _positionY + disp.getMaxCharHeight() + 2;}
  else if(_textAnchorV == "center") {textY = _positionY + floor(_height / 2) + 3;}
  else if(_textAnchorV == "bottom") {textY = _positionY + _height - 2;}

  // Horizontal positioning
  if(_textAnchorH == "left") {textX = _positionX + 2;}
  else if(_textAnchorH == "center") {textX = _positionX + _width / 2 - disp.getStrWidth(_text.c_str()) / 2;}
  else if(_textAnchorH == "right") {textX = _positionX + (_positionX + _width - disp.getStrWidth(_text.c_str()) - 5);}

  disp.setDrawColor(2);
  disp.drawStr(textX, textY, _text.c_str());
  disp.setDrawColor(1);
}

// Draw TextLabel widget
void TextLabel::draw()
{
  // Positioning of the text
  short textX, textY;

  // Vertical positioning
  if(_textAnchorV == "top") {textY = _positionY + 7;}
  else if(_textAnchorV == "center") {textY = _positionY + floor(_height / 2) + 4;}
  else if(_textAnchorV == "bottom") {textY = _positionY + _height;}

  // Horizontal positioning
  if(_textAnchorH == "left") {textX = _positionX;}
  else if(_textAnchorH == "center") {textX = _positionX + _width / 2 - disp.getStrWidth(_text.c_str()) / 2;}
  else if(_textAnchorH == "right") {textX = _positionX + _width - disp.getStrWidth(_text.c_str());}

  disp.setDrawColor(2);
  disp.drawStr(textX, textY, _text.c_str());
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
      _width + _borderPadding * 2,
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
