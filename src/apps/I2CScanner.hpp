// Local dependencies
#include <core/Icons.hpp>

class I2CScanner
{
  public: 
    void draw();
    const char * name = "Scanner";
    unsigned char * icon = scannerIcon;
};
