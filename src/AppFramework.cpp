#include <AppFramework.hpp>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C disp(U8G2_R0);

int AppFramework::getStrWidth(String str)
{
  return disp.getUTF8Width(str.c_str());
}

void AppFramework::begin()
{
  disp.begin();
  disp.setFont(u8g2_font_5x7_tr);
}

void AppFramework::clearBuffer()
{
  disp.clearBuffer();
}

void AppFramework::sendBuffer()
{
  disp.sendBuffer();
}

void Button::draw()
{
  // Draw Frame
  if(frameType == "rectangle")
  {
    disp.drawFrame(
      positionX, 
      positionY, 
      sizeX,
      sizeY
    );
  }
  
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
      positionY + floor(sizeY / 2) + 3, 
      text.c_str()
    );
  }
  else if(textAnchor == "bottom")
  {
    disp.drawStr(
      positionX + 2, 
      positionY + sizeY - 2, 
      text.c_str()
    );
  }

  if(isHighlighted)
  {
    disp.setDrawColor(2);
    disp.drawBox(
      positionX + 1, 
      positionY + 1, 
      sizeX - 2, 
      sizeY - 2
    );
    disp.setDrawColor(1);
  }
}

void TextLabel::draw()
{
  disp.drawStr((isCentered) ? 64 - disp.getUTF8Width(text.c_str()) / 2 : position[0], position[1], text.c_str()); 
}

void Icon::draw(unsigned char image[])
{
  disp.drawXBMP(position[0], position[1], size[0], size[1], image);
}
