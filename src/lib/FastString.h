// Libraries
#include <Arduino.h>

template <uint16_t BUFFER_SIZE>
class FastString
{
  private:
    short _bufferLength = 0;
    char _strBuffer[BUFFER_SIZE + 1];

  public:
    // Constructor
    FastString()
    {
      clearBuffer();
    }

    FastString(const char * value)
    {
      clearBuffer();
      add(value);
    }

    // Get string buffer
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
      _bufferLength = strlen(_strBuffer);
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
      if(_bufferLength + 1 >= BUFFER_SIZE)
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
      return add((char*)value, strlen(value));
    }

    // Add string (char *). String length is required
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

    // Add uint32_t (unsigned long / unsigned 32-bit int)
    FastString& add(uint32_t value)
    {
      char numberBuffer[11];
      ultoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    // Add uint16_t (unsigned 16-bit int)
    FastString& add(uint16_t value)
    {
      char numberBuffer[6];
      utoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    // Add uint8_t (unsigned short / unsigned 8-bit int)
    FastString& add(uint8_t value)
    {
      return add((uint16_t)value);
    }

    // Add int32_t (long / 32-bit int)
    FastString& add(int32_t value)
    {
      char numberBuffer[12];
      ltoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    // Add int16_t (16-bit int)
    FastString& add(int16_t value)
    {
      char numberBuffer[7];
      itoa(value, numberBuffer, DEC);
      return add(numberBuffer);
    }

    // Add int8_t (short / 8-bit int)
    FastString& add(int8_t value)
    {
      return add((int16_t)value);
    }

    // Add another FastString
    FastString& add(FastString value)
    {
      return add(value.getBuffer());
    }

    // Operators overloading
    // Add ("+") operator
    FastString operator + (const char value)
    {
      return (*this).add(value);
    }
    FastString operator + (const char* value) {
      return (*this).add(value);
    }
    FastString operator + (uint32_t value) {
      return (*this).add(value);
    }
    FastString operator + (int32_t value) {
      return (*this).add(value);
    }
    FastString operator + (uint16_t value) {
      return (*this).add(value);
    }
    FastString operator + (int16_t value) {
      return (*this).add(value);
    }
    FastString operator + (uint8_t value) {
      return (*this).add(value);
    }
    FastString operator + (int8_t value) {
      return (*this).add(value);
    }
    FastString operator + (FastString value) {
      return (*this).add(value);
    }

    // Add assign ("+=") operator
    FastString& operator += (const char value)
    {
      return (*this).add(value);
    }
    FastString& operator += (const char* data) {
      return (*this).add(data);
    }
    FastString& operator += (uint32_t value) {
      return (*this).add(value);
    }
    FastString& operator += (int32_t value) {
      return (*this).add(value);
    }
    FastString& operator += (uint16_t value) {
      return (*this).add(value);
    }
    FastString& operator += (int16_t value) {
      return (*this).add(value);
    }
    FastString& operator += (uint8_t value) {
      return (*this).add(value);
    }
    FastString& operator += (int8_t value) {
      return (*this).add(value);
    }
    FastString& operator += (FastString value) {
      return (*this).add(value);
    }

    // Assign ("=") operator
    FastString operator = (const char value)
    {
      clearBuffer();
      return (*this).add(value);
    }
    FastString operator = (const char* data) {
      clearBuffer();
      return (*this).add(data);
    }
    FastString operator = (uint32_t value) {
      clearBuffer();
      return (*this).add(value);
    }
    FastString operator = (int32_t value) {
      clearBuffer();
      return (*this).add(value);
    }
    FastString operator = (uint16_t value) {
      clearBuffer();
      return (*this).add(value);
    }
    FastString operator = (int16_t value) {
      clearBuffer();
      return (*this).add(value);
    }
    FastString operator = (uint8_t value) {
      clearBuffer();
      return (*this).add(value);
    }
    FastString operator = (int8_t value) {
      clearBuffer();
      return (*this).add(value);
    }
    FastString operator = (FastString value) {
      clearBuffer();  
      return (*this).add(value);
    }

    // Other operators
    char operator [] (short index)
    const {
      return _strBuffer[index];
    }

    char& operator [] (short index)
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
    void setCharAt(short index, char value)
    {
      if(index > BUFFER_SIZE)
      {
        return;
      }
      _strBuffer[index] = value;
    }

    // Get a char from the buffer by index
    char getCharAt(short index)
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
        char *charPointer = _strBuffer; 
        charPointer <= &_strBuffer[_bufferLength]; 
        charPointer++
      )
      {
        *charPointer = tolower(*charPointer);
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
        char *charPointer = _strBuffer; 
        charPointer < &_strBuffer[_bufferLength]; 
        charPointer++
      )
      {
        *charPointer = toupper(*charPointer);
      }
    }

    // Remove char with a shift
    void remove(short index)
    {
      if(index > _bufferLength)
      {
        return;
      }
      memmove(&_strBuffer[index], &_strBuffer[index + 1], _bufferLength - index);
      _bufferLength--;
    }

    // Remove string (char *) with a shift
    void remove(short index, short valueLength)
    {
      if(index > _bufferLength)
      {
        return;
      }
      memmove(&_strBuffer[index], &_strBuffer[index + valueLength], _bufferLength - index - (valueLength - 1));
      _bufferLength -= valueLength;
    }

    // Insert a char in the buffer with a shift
    void insert(short index, char value)
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
    void insert(short index, const char * value)
    {
      insert(index, (char*)value);
    }

    // Insert a string (char *) in the buffer with a shift
    void insert(short index, char * value)
    {
      short valueLength = strlen(value);
      if(_bufferLength + valueLength > BUFFER_SIZE || index > BUFFER_SIZE)
      {
        return;
      }
      memmove(&_strBuffer[index + valueLength], &_strBuffer[index], _bufferLength - index + 1);
      memcpy(&_strBuffer[index], value, valueLength);
      _bufferLength += valueLength;
    }

    // Replace buffer data with a single char
    void replace(short index, char value)
    {
      if(_bufferLength + 1 > BUFFER_SIZE || index > BUFFER_SIZE)
      {
        return;
      }
      _strBuffer[index] = value;
      _bufferLength++;
    }

    // Replace buffer data with a string (char *)
    void replace(short index, char * value)
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
    void replace(short index, const char * value)
    {
      replace(index, (char *)value);
    }
};
