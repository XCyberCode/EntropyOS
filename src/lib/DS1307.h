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
    short _second; // Seconds
    short _minute; // Minutes
    short _hour; // Hours
    short _dayOfWeek; // Day of the week
    short _dayOfMonth; // Day of the month
    short _month; // Month
    short _year; // Year

    // Convert from decimal to binary-decimal
    short decToBcd(short value)
    {
      return (value / 10 * 16) + (value % 10);
    }

    // Convert from binary-decimal to decimal
    short bcdToDec(short value)
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
    void set(short second, short minute, short hour, short dayOfWeek, short dayOfMonth, short month, short year)
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

    short getSecond() {return _second;}
    short getMinute() {return _minute;}
    short getHour() {return _hour;}
    short getDayOfWeek() {return _dayOfWeek;}
    short getDayOfMonth() {return _dayOfMonth;}
    short getMonth() {return _month;}
    short getYear() {return _year;}
};

#endif
