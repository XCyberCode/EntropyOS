// Libraries
#include <Arduino.h>

template <uint16_t BUFFER_SIZE>
class FastString
{
  private:
    uint16_t _bufferLength = 0;
    char _strBuffer[BUFFER_SIZE + 1];

  public:
    FastString()
    {
      clearBuffer();
    }

    FastString(const char * value)
    {
      clearBuffer();
      add(value);
    }

    char * getBuffer()
    {
      return _strBuffer;
    }

    // Get maximum capacity
    short getCapacity()
    {
      return BUFFER_SIZE;
    }

    // Get string length
    short getLength()
    {
      return _bufferLength;
    }

    // Clear string buffer
    void clearBuffer()
    {
      _strBuffer[0] = '\0';
      _bufferLength = 0;
    }

    // "Add" methods
    FastString& add(const char value)
    {
      if(_bufferLength + 1 > BUFFER_SIZE)
      {
        return *this;
      }
      _strBuffer[_bufferLength] = value;
      _strBuffer[++_bufferLength] = '\0';
      return *this;
    }

    // Add string (const char *)
    FastString& add(const char * value)
    {
      return add((char*)value);
    }

    // Add string (char *)
    FastString& add(char * value)
    {
      if(_bufferLength + strlen(value) > BUFFER_SIZE)
      {
        return *this;
      }
      strcat(_strBuffer, value);
      _bufferLength += strlen(value);
      return *this;
    }
    // Add uint64_t (unsigned long long)
    FastString& add(uint64_t value)
    {
      char numberBuffer[21];
      ulltoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    // Add uint32_t (unsigned long)
    FastString& add(uint32_t value)
    {
      char numberBuffer[11];
      ultoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    // Add uint16_t (unsigned short)
    FastString& add(uint16_t value)
    {
      char numberBuffer[6];
      utoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    // Add uint8_t
    FastString& add(uint8_t value)
    {
      return add((uint16_t)value);
    }

    // Add int64_t (long long)
    FastString& add(int64_t value)
    {
      char numberBuffer[21];
      lltoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    // Add int32_t (long)
    FastString& add(int32_t value)
    {
      char numberBuffer[12];
      ltoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    // Add int16_t (short)
    FastString& add(int16_t value)
    {
      char numberBuffer[7];
      itoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    // Add int8_t
    FastString& add(int8_t value)
    {
      return add((int16_t)value);
    }

    // Add another FastString
    template <uint16_t bufferSize>
    FastString& add(FastString<bufferSize> value)
    {
      return add(value.getBuffer());
    }

    // Operators overloading
    // Add ("+") operator
    FastString operator + (const char value)
    {
      return (*this).add(value);
    }
    FastString operator + (const char* value) 
    {
      return (*this).add(value);
    }
    FastString operator + (uint64_t value)
    {
      return (*this).add(value);
    }
    FastString operator + (uint32_t value) 
    {
      return (*this).add(value);
    }
    FastString operator + (uint16_t value) 
    {
      return (*this).add(value);
    }
    FastString operator + (uint8_t value) 
    {
      return (*this).add(value);
    }
    FastString operator + (int64_t value)
    {
      return (*this).add(value);
    }
    FastString operator + (int32_t value) 
    {
      return (*this).add(value);
    }
    FastString operator + (int16_t value) 
    {
      return (*this).add(value);
    }
    FastString operator + (int8_t value) 
    {
      return (*this).add(value);
    }
    template <uint16_t bufferSize>
    FastString operator + (FastString<bufferSize> value) {
      return (*this).add(value.getBuffer());
    }

    // Add assign ("+=") operator
    FastString& operator += (const char value)
    {
      return add(value);
    }
    FastString& operator += (const char* data) {
      return add(data);
    }
    FastString& operator += (uint64_t value)
    {
      return add(value);
    }
    FastString& operator += (uint32_t value) 
    {
      return add(value);
    }
    FastString& operator += (uint16_t value) 
    {
      return add(value);
    }
    FastString& operator += (uint8_t value) 
    {
      return add(value);
    }
    FastString& operator += (int64_t value)
    {
      return add(value);
    }
    FastString& operator += (int32_t value) 
    {
      return add(value);
    }
    FastString& operator += (int16_t value) 
    {
      return add(value);
    }
    FastString& operator += (int8_t value) 
    {
      return add(value);
    }
    template <uint16_t bufferSize>
    FastString& operator += (FastString<bufferSize> value) {
      return add(value.getBuffer());
    }

    // Assign ("=") operator
    FastString& operator = (char * value)
    {
      clearBuffer();
      return add(value);
    }
    FastString& operator = (const char * value) 
    {
      clearBuffer();
      return add(value);
    }
    FastString& operator = (uint64_t value)
    {
      clearBuffer();
      return add(value);
    }
    FastString& operator = (uint32_t value) 
    {
      clearBuffer();
      return add(value);
    }
    FastString& operator = (uint16_t value) 
    {
      clearBuffer();
      return add(value);
    }
    FastString& operator = (uint8_t value) 
    {
      clearBuffer();
      return add(value);
    }
    FastString& operator = (int64_t value)
    {
      clearBuffer();
      return add(value);
    }
    FastString& operator = (int32_t value) 
    {
      clearBuffer();
      return add(value);
    }
    FastString& operator = (int16_t value) 
    {
      clearBuffer();
      return add(value);
    }
    FastString& operator = (int8_t value) 
    {
      clearBuffer();
      return add(value);
    }
    template <uint16_t bufferSize>
    FastString& operator = (FastString<bufferSize> value) {
      clearBuffer();  
      return add(value.getBuffer());
    }

    // Equal ("==") operator
    template <uint16_t bufferSize>
    bool operator == (FastString<bufferSize> value)
    {
      return !strcmp(_strBuffer, value.getBuffer());
    }
    bool operator == (const char * value)
    {
      return !strcmp(_strBuffer, value);
    }
    bool operator == (char * value)
    {
      return !strcmp(_strBuffer, value);
    }
    bool operator == (uint64_t value)
    {
      char numberBuffer[21];
      ulltoa(value, numberBuffer, DEC);
      return !strcmp(_strBuffer, numberBuffer);
    }
    bool operator == (uint32_t value)
    {
      char numberBuffer[11];
      ultoa(value, numberBuffer, DEC);
      return !strcmp(_strBuffer, numberBuffer);
    }
    bool operator == (uint16_t value)
    {
      char numberBuffer[6];
      utoa(value, numberBuffer, DEC);
      return !strcmp(_strBuffer, numberBuffer);
    }
    bool operator == (int64_t value)
    {
      char numberBuffer[21];
      lltoa(value, numberBuffer, DEC);
      return !strcmp(_strBuffer, numberBuffer);
    }
    bool operator == (int32_t value)
    {
      char numberBuffer[12];
      ltoa(value, numberBuffer, DEC);
      return !strcmp(_strBuffer, numberBuffer);
    }
    bool operator == (int16_t value)
    {
      char numberBuffer[7];
      itoa(value, numberBuffer, DEC);
      return !strcmp(_strBuffer, numberBuffer);
    }

    // Other operators
    char operator [] (uint16_t index)
    const {
      return _strBuffer[index];
    }

    char& operator [] (uint16_t index)
    {
      return _strBuffer[index];
    }

    // Methods
    // Return buffer as const char * (string)
    const char * c_str()
    {
      return _strBuffer;
    }

    // Set a char from the buffer by index
    void setCharAt(uint16_t index, char value)
    {
      if(index > BUFFER_SIZE)
      {
        return;
      }
      _strBuffer[index] = value;
    }

    // Get a char from the buffer by index
    char getCharAt(uint16_t index)
    {
      if(index > BUFFER_SIZE)
      {
        return _strBuffer[_bufferLength];
      }
      return _strBuffer[index];
    }

    // Convert all chars to lower case
    void toLowerCase()
    {
      // If buffer is empty
      if(!_bufferLength)
      {
        return;
      }
      for(
        uint32_t currentIndex = 0;
        currentIndex < _bufferLength; 
        currentIndex++
      )
      {
        _strBuffer[currentIndex] = tolower(_strBuffer[currentIndex]);
      }
    }

    // Convert all chars to upper case
    void toUpperCase()
    {
      // If buffer is empty
      if(!_bufferLength)
      {
        return;
      }
      for(
        uint32_t currentIndex = 0;
        currentIndex < _bufferLength; 
        currentIndex++
      )
      {
        _strBuffer[currentIndex] = toupper(_strBuffer[currentIndex]);
      }
    }

    // Remove char with a shift
    void erase(uint16_t index)
    {
      if(index > _bufferLength)
      {
        return;
      }
      memmove(&_strBuffer[index], &_strBuffer[index + 1], _bufferLength - index);
      _bufferLength--;
    }

    // Remove string (char *) with a shift
    void erase(uint16_t index, uint16_t valueLength)
    {
      if(index > _bufferLength)
      {
        return;
      }
      memmove(&_strBuffer[index], &_strBuffer[index + valueLength], _bufferLength - index - (valueLength - 1));
      _bufferLength -= valueLength;
    }

    // Insert a char in the buffer with a shift
    void insert(uint16_t index, char value)
    {
      if(_bufferLength + 1 > BUFFER_SIZE || index > BUFFER_SIZE)
      {
        return;
      }
      memmove(&_strBuffer[index + 1], &_strBuffer[index], _bufferLength - index + 1);
      _strBuffer[index] = value;
      _bufferLength++;
    }

    // Convert and insert
    void insert(uint16_t index, const char * value)
    {
      insert(index, (char*)value);
    }

    // Insert a string (char *) in the buffer with a shift
    void insert(uint16_t index, char * value)
    {
      if(_bufferLength + strlen(value) > BUFFER_SIZE || index > BUFFER_SIZE)
      {
        return;
      }
      memmove(&_strBuffer[index + strlen(value)], &_strBuffer[index], _bufferLength - index + 1);
      memcpy(&_strBuffer[index], value, strlen(value));
      _bufferLength += strlen(value);
    }

    // Replace buffer data with a single char
    void replace(uint16_t index, char value)
    {
      if(_bufferLength + 1 > BUFFER_SIZE || index > BUFFER_SIZE)
      {
        return;
      }
      _strBuffer[index] = value;
      _bufferLength++;
    }

    // Replace buffer data with a string (char *)
    void replace(uint16_t index, char * value)
    {
      short valueLength = strlen(value);
      if(_bufferLength + valueLength > BUFFER_SIZE || index > BUFFER_SIZE)
      {
        return;
      }
      memcpy(&_strBuffer[index], value, valueLength);
      _bufferLength += valueLength;
    }

    // Convert and replace
    void replace(uint16_t index, const char * value)
    {
      replace(index, (char *)value);
    }

    // Convert and replace
    void replace(uint16_t index, uint16_t value)
    {
      char valueStr[6];
      utoa(value, valueStr, DEC);
      replace(index, valueStr);
    }
};
