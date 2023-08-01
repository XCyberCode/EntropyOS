#include <AppFramework.hpp>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp(U8G2_R0);

void Button::draw()
{
  // Draw Frame
  if(frameType == "rectangle")
  {
    disp.drawFrame(
      positionX, 
      positionY, 
      width,
      height
    );
  }
  
  /*
  // Text Positioning
  if(textAnchor == "top")
  {
    disp.drawStr(
      positionX + 2, 
      positionY + 8, 
      text.c_str()
    );
  }
  else if(textAnchor == "center")
  {
    disp.drawStr(
      positionX + 2, 
      positionY + height / 2 + 3, 
      text.c_str()
    );
  }
  else if(textAnchor == "bottom")
  {
    disp.drawStr(
      positionX + 2, 
      positionY + height - 2, 
      text.c_str()
    );
  }*/

  disp.setFont(u8g2_font_6x10_tf);
  short textX, textY;
  if(textAnchorV == "top")
  {
    textY = positionY + 8;
  }
  else if(textAnchorV == "center")
  {
    textY = positionY + floor(height / 2) + 3;
  }
  else if(textAnchorV == "bottom")
  {
    textY = positionY + height - 2;
  };

  if(textAnchorH == "left")
  {
    textX = positionX + 2;
  }
  else if(textAnchorH == "center")
  {
    textX = positionX + (width / 2 - disp.getStrWidth(text.c_str()) / 2);
  }
  else if(textAnchorH == "right")
  {
    textX = positionX + (positionX + width - disp.getStrWidth(text.c_str()) - 5);
  }

  disp.drawStr(textX, textY, text.c_str());

  if(isHighlighted)
  {
    disp.setDrawColor(2);
    disp.drawBox(
      positionX + 1, 
      positionY + 1, 
      width - 2, 
      height - 2
    );
    disp.setDrawColor(1);
  }
}

void TextLabel::draw()
{
  disp.drawStr((textAnchor == "center") ? 64 - disp.getUTF8Width(text.c_str()) / 2 : positionX, positionY, text.c_str()); 
}

void Icon::draw(unsigned char image[])
{
  disp.drawXBMP(positionX, positionY, width, height, image);
}
