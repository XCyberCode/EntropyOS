template <short BUFFER_SIZE>
class FastString
{
  private:
    char _strBuffer[BUFFER_SIZE + 1];
    short _length = 0;

  public:
    FastString();

    short getCapacity()
    {
      return BUFFER_SIZE;
    }

    short getLength()
    {
      _length = strlen(_strBuffer);
    }

    short clearBuffer()
    {
      _strBuffer[0] = '\0';
      _length = 0;
    }
};
