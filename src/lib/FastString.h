// Libraries
#include <Arduino.h>

template <short BUFFER_SIZE = 64>
class FastString
{
  private:
    short _bufferLength = 0;
    char _strBuffer[BUFFER_SIZE + 1];

  public:
    FastString()
    {
      clearBuffer();
    };

    char * getBuffer()
    {
      return _strBuffer;
    }

    short getCapacity()
    {
      return BUFFER_SIZE;
    }

    short getLength()
    {
      _bufferLength = strlen(_strBuffer);
      return _bufferLength;
    }

    void clearBuffer()
    {
      _strBuffer[0] = '\0';
      _bufferLength = 0;
    }

    // Add
    FastString& add(const char value)
    {
      if(_bufferLength + 1 >= BUFFER_SIZE)
      {
        return *this;
      }
      _strBuffer[_bufferLength] = value;
      _strBuffer[_bufferLength + 1] = '\0';
      return *this;
    }

    FastString& add(const char * value)
    {
      return add((char*)value, strlen(value));
    }

    FastString& add(char * value, short valueLength)
    {
      if(_bufferLength + valueLength >= BUFFER_SIZE)
      {
        return *this;
      }
      memcpy(_strBuffer + _bufferLength, value, valueLength);
      _bufferLength += valueLength;
      _strBuffer[_bufferLength] = '\0';
      return *this;
    }

    FastString& add(uint32_t value)
    {
      char numberBuffer[11];
      ultoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    FastString& add(uint16_t value)
    {
      char numberBuffer[6];
      utoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    FastString& add(uint8_t value)
    {
      return add((uint16_t)value);
    }

    FastString& add(int32_t value)
    {
      char numberBuffer[12];
      ltoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    FastString& add(int16_t value)
    {
      char numberBuffer[7];
      itoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    FastString& add(int8_t value)
    {
      return add((int16_t)value);
    }

    FastString& add(FastString value)
    {
      return add(value.getBuffer());
    }
};
