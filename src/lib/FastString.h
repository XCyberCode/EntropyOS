// Libraries
#include <Arduino.h>

template <short BUFFER_SIZE = 64>
class FastString
{
  private:
    short _length = 0;

  public:
    char _strBuffer[BUFFER_SIZE + 1];

    FastString()
    {
      clearBuffer();
    };

    short getCapacity()
    {
      return BUFFER_SIZE;
    }

    short getLength()
    {
      _length = strlen(_strBuffer);
      return _length;
    }

    void clearBuffer()
    {
      _strBuffer[0] = '\0';
      _length = 0;
    }

    // Add
    FastString& add(const char addStr)
    {
      if(_length + 1 >= BUFFER_SIZE)
      {
        return *this;
      }
      _strBuffer[_length] = addStr;
      _strBuffer[_length + 1] = '\0';
      return *this;
    }

    FastString& add(const char * addStr)
    {
      return add((char*)addStr, strlen(addStr));
    }

    FastString& add(char * addStr, short addLength)
    {
      if(_length + addLength >= BUFFER_SIZE)
      {
        return *this;
      }
      memcpy(_strBuffer + _length, addStr, addLength);
      _length += addLength;
      _strBuffer[_length] = '\0';
      return *this;
    }
};
