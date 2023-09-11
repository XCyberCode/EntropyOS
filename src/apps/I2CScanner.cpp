// Header
#include <apps/I2CScanner.hpp>

// Libraries
#include <Wire.h>
#include <Arduino.h>

// Local dependencies
#include <core/AppFramework.hpp>
#include <core/HardwareManager.hpp>
#include <core/Timer.hpp>

void I2CScannerApp::draw()
{
  Timer rescanTimer(3000, 0, 0);
  TextLabelWidget infoLabel(0, 15, 128, 16);
  TextLabelWidget speedInfoLabel(0, 31, 128, 16);

  Serial.begin(115200);

  uint8_t error, address;
  uint8_t numOfDevices;

  disp.clearBuffer();
  infoLabel.draw("=== Serial Mode ===");
  speedInfoLabel.draw("Boudrate: 115200");
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
          if(address < 16)
          {
            Serial.print("0");
          }

          Serial.print(address, HEX);
          Serial.println(" !");

          numOfDevices++;
        }
        else if(error == 4) 
        {
          Serial.print("Unknow error at address 0x");
          if (address < 16)
          {
            Serial.print("0");
          }
          Serial.println(address, HEX);
        } 
      }
      if (numOfDevices == 0)
      {
        Serial.println("No I2C devices found");
      }
      else
      {
        Serial.println("done");
      }
    }

    if(bBtn.click())
    {
      return;
    }
  }
}
