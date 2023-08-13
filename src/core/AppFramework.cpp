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
  if(isFocus)
  {
    disp.drawRBox(positionX, positionY, width, height, cornerRadius);
  }
  else if(isFramed)
  {
    disp.drawRFrame(positionX, positionY, width, height, cornerRadius);
  }

  // Positioning of the text 
  short textX, textY;

  // Vertical positioning
  if(textAnchorV == "top") {textY = positionY + disp.getMaxCharHeight() + 2;}
  else if(textAnchorV == "center") {textY = positionY + floor(height / 2) + 3;}
  else if(textAnchorV == "bottom") {textY = positionY + height - 2;}

  // Horizontal positioning
  if(textAnchorH == "left") {textX = positionX + 2;}
  else if(textAnchorH == "center") {textX = positionX + width / 2 - disp.getStrWidth(text.c_str()) / 2;}
  else if(textAnchorH == "right") {textX = positionX + (positionX + width - disp.getStrWidth(text.c_str()) - 5);}

  disp.setDrawColor(2);
  disp.drawStr(textX, textY, text.c_str());
  disp.setDrawColor(1);
}

// Draw TextLabel widget
void TextLabel::draw()
{
  // Positioning of the text
  short textX, textY;

  // Vertical positioning
  if(textAnchorV == "top") {textY = positionY + 7;}
  else if(textAnchorV == "center") {textY = positionY + floor(height / 2) + 4;}
  else if(textAnchorV == "bottom") {textY = positionY + height;}

  // Horizontal positioning
  if(textAnchorH == "left") {textX = positionX;}
  else if(textAnchorH == "center") {textX = positionX + width / 2 - disp.getStrWidth(text.c_str()) / 2;}
  else if(textAnchorH == "right") {textX = positionX + width - disp.getStrWidth(text.c_str());}

  disp.setDrawColor(2);
  disp.drawStr(textX, textY, text.c_str());
  disp.setDrawColor(1);
}

// Draw Icon widget
void Icon::draw(unsigned char image[])
{
  disp.drawXBMP(positionX, positionY, width, height, image);
  if(isFramed)
  {
    disp.drawFrame(positionX, positionY, width, height);
  }
}
