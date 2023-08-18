// Libraries
#include <Arduino.h>

template <uint16_t BUFFER_SIZE>
class FastString
{
  private:
    short _bufferLength = 0;
    char _strBuffer[BUFFER_SIZE + 1];

  public:
    FastString()
    {
      clearBuffer();
    }

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
    FastString operator += (const char value)
    {
      return (*this).add(value);
    }
    FastString operator += (const char* data) {
      return (*this).add(data);
    }
    FastString operator += (uint32_t value) {
      return (*this).add(value);
    }
    FastString operator += (int32_t value) {
      return (*this).add(value);
    }
    FastString operator += (uint16_t value) {
      return (*this).add(value);
    }
    FastString operator += (int16_t value) {
      return (*this).add(value);
    }
    FastString operator += (uint8_t value) {
      return (*this).add(value);
    }
    FastString operator += (int8_t value) {
      return (*this).add(value);
    }
    FastString operator += (FastString value) {
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

    // Methods
    // Return buffer as const char * (string)
    const char * c_str()
    {
      return _strBuffer;
    }

    // Set char of the buffer by index
    void setCharAt(short index, char value)
    {
      _strBuffer[index] = value;
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
        char *addressPointer = _strBuffer; 
        addressPointer <= &_strBuffer[_bufferLength]; 
        addressPointer++
      )
      {
        *addressPointer = tolower(*addressPointer);
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
        char *addressPointer = _strBuffer; 
        addressPointer < &_strBuffer[_bufferLength]; 
        addressPointer++
      )
      {
        *addressPointer = toupper(*addressPointer);
      }
    }
};
