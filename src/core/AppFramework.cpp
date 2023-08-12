// Header
#include <core/AppFramework.hpp>

// Libraries
#include <U8g2lib.h>

// Local dependencies
#include <core/HardwareManager.hpp>

// === Button methods
// Draw widget
void Button::draw()
{
  // Draw frame or field
  if(isHighlighted)
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
  else if(textAnchorV == "center") {textY = positionY + floor(height / 2) + floor(disp.getMaxCharHeight() / 2) - 2;}
  else if(textAnchorV == "bottom") {textY = positionY + height - 2;};

  // Horizontal positioning
  if(textAnchorH == "left") {textX = positionX + 2;}
  else if(textAnchorH == "center") {textX = positionX + width / 2 - disp.getStrWidth(text.c_str()) / 2;}
  else if(textAnchorH == "right") {textX = positionX + (positionX + width - disp.getStrWidth(text.c_str()) - 5);}

  disp.setDrawColor(2);
  disp.drawStr(textX, textY, text.c_str());
  disp.setDrawColor(1);
}

// === TextLabel methods
void TextLabel::draw()
{
  // Positioning of the text
  short textX, textY;

  // Vertical positioning
  // if(textAnchorV == "top") {textY = positionY + disp.getMaxCharHeight();}
  // else if(textAnchorV == "center") {}
}

// === Icon methods
// Draw widget
void Icon::draw(unsigned char image[])
{
  disp.drawXBMP(positionX, positionY, width, height, image);
  if(isFramed)
  {
    disp.drawFrame(positionX, positionY, width, height);
  }
}

