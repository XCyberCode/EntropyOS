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
    byte _second;
    byte _minute;
    byte _hour;
    byte _dayOfWeek;
    byte _dayOfMonth;
    byte _month;
    byte _year;

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

    void setAll(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
    {
      Wire.beginTransmission(DS1307_I2C_ADDRESS);
      // выставляем регистр указателей DS3231 на регистр «00h»,
      // т.е. на регистр, в котором хранятся данные о секундах:
      Wire.write(0);
      Wire.write(decToBcd(second)); // задаем секунды
      Wire.write(decToBcd(minute)); // задаем минуты
      Wire.write(decToBcd(hour)); // задаем часы
      Wire.write(decToBcd(dayOfWeek));
      // задаем день недели (1 – это воскресенье, 7 – это суббота)
      Wire.write(decToBcd(dayOfMonth)); // задаем дату (от 1 до 31)
      Wire.write(decToBcd(month)); // задаем месяц
      Wire.write(decToBcd(year)); // задаем год (от 0 до 99)
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
