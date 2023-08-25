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
    short _second;
    short _minute;
    short _hour;
    short _dayOfWeek;
    short _dayOfMonth;
    short _month;
    short _year;

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

    void set(short second, short minute, short hour, short dayOfWeek, short dayOfMonth, short month, short year)
    {
      Wire.beginTransmission(DS1307_I2C_ADDRESS);
      Wire.write(0);
      Wire.write(decToBcd(second));
      Wire.write(decToBcd(minute));
      Wire.write(decToBcd(hour));
      Wire.write(decToBcd(dayOfWeek)); 
      Wire.write(decToBcd(dayOfMonth));
      Wire.write(decToBcd(month));
      Wire.write(decToBcd(year));
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
