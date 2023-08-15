// Header
#include <apps/I2CScanner.hpp>

// Libraries
#include <Wire.h>
#include <Arduino.h>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>

Timer rescanTimer(3000, 0, 0);
TextLabel infoLabel(0, 15, 128, 16, "=== Serial Mode ===");
TextLabel speedInfoLabel(0, 31, 128, 16, "Boudrate: 115200");

byte error, address;
short numOfDevices;

void I2CScanner::draw()
{
  Serial.begin(115200);

  disp.clearBuffer();
  infoLabel.draw();
  speedInfoLabel.draw();
  disp.sendBuffer();

  rescanTimer.start();
  while(1)
  {
    tickAll();
    if(rescanTimer.tick())
    {
      Serial.println("Scanning...");

      numOfDevices = 0;
      for(address = 8; address < 127; address++ )
      {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if(error == 0)
        {
          Serial.print("I2C device found at address 0x");
          if(address<16)
          {
            Serial.print("0");
          }

          Serial.print(address,HEX);
          Serial.println(" !");

          numOfDevices++;
        }
        else if(error==4) 
        {
          Serial.print("Unknow error at address 0x");
          if (address<16)
          {
            Serial.print("0");
          }
          Serial.println(address,HEX);
        } 
      }
      if (numOfDevices == 0)
      {
        Serial.println("No I2C devices found\n");
      }
      else
      {
        Serial.println("done\n");
      }
    }

    if(bBtn.click())
    {
      return;
    }
  }
}
