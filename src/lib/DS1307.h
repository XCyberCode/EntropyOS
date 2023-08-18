// Libraries 
#include <Wire.h>
#include <Arduino.h>

// Defines
#define DS1307_I2C_ADDRESS 0x68

// Include guard
#ifndef DS1307_LIB_H
#define DS1307_LIB_H

class DS1307
{
  private:
    byte _second; // Seconds
    byte _minute; // Minutes
    byte _hour; // Hours
    byte _dayOfWeek; // Day of the week
    byte _dayOfMonth; // Day of the month
    byte _month; // Month
    byte _year; // Year

    // Convert from decimal to binary-decimal
    byte decToBcd(byte value)
    {
      return (value / 10 * 16) + (value % 10);
    }

    // Convert from binary-decimal to decimal
    byte bcdToDec(byte value)
    {
      return (value / 16 * 10) + (value % 16);
    }

  public:
    // Read time and date
    void read()
    {
      Wire.beginTransmission(DS1307_I2C_ADDRESS);
      Wire.write(0);
      Wire.endTransmission();
      
      Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
      _second = bcdToDec(Wire.read() & 0x7f);
      _minute = bcdToDec(Wire.read());
      _hour = bcdToDec(Wire.read() & 0x3f);
      _dayOfWeek = bcdToDec(Wire.read());
      _dayOfMonth = bcdToDec(Wire.read());
      _month = bcdToDec(Wire.read());
      _year = bcdToDec(Wire.read());
    }

    // Set time and date
    void set(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
    {
      Wire.beginTransmission(DS1307_I2C_ADDRESS);
      // Set DS1307 register value
      Wire.write(0);
      Wire.write(decToBcd(second)); // Set seconds
      Wire.write(decToBcd(minute)); // Set minutes
      Wire.write(decToBcd(hour)); // Set hours
      Wire.write(decToBcd(dayOfWeek)); 
      // Set day of the week (1 – Sunday, 7 – Saturday)
      Wire.write(decToBcd(dayOfMonth)); // Set day (from 1 to 31)
      Wire.write(decToBcd(month)); // Set months
      Wire.write(decToBcd(year)); // Set years (from 0 to 99)
      Wire.endTransmission();
    }

    byte getSecond() {return _second;}
    byte getMinute() {return _minute;}
    byte getHour() {return _hour;}
    byte getDayOfWeek() {return _dayOfWeek;}
    byte getDayOfMonth() {return _dayOfMonth;}
    byte getMonth() {return _month;}
    byte getYear() {return _year;}
};

#endif
