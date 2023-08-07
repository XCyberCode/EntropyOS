#include <AppFramework.hpp>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp(U8G2_R0);

void AppFramework::begin()
{
  disp.begin();
  disp.setFontMode(1);
}

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

  // Text positioning 
  disp.setFont(u8g2_font_6x10_tf);
  short textX, textY;

  // Vertical positioning
  if(textAnchorV == "top") {textY = positionY + 8;}
  else if(textAnchorV == "center") {textY = positionY + floor(height / 2) + 3;}
  else if(textAnchorV == "bottom") {textY = positionY + height - 2;};

  // Horizontal positioning
  if(textAnchorH == "left") {textX = positionX + 2;}
  else if(textAnchorH == "center") {textX = positionX + (width / 2 - disp.getStrWidth(text.c_str()) / 2);}
  else if(textAnchorH == "right") {textX = positionX + (positionX + width - disp.getStrWidth(text.c_str()) - 5);}

  disp.setDrawColor(2);
  disp.drawStr(textX, textY, text.c_str());
  disp.setDrawColor(1);
}

void TextLabel::draw()
{
  disp.drawStr((textAnchor == "center") ? 64 - disp.getUTF8Width(text.c_str()) / 2 : positionX, positionY, text.c_str()); 
}

void Icon::draw(unsigned char image[])
{
  disp.drawXBMP(positionX, positionY, width, height, image);
}
