// Local dependencies
#include <core/Icons.hpp>

class I2CScanner
{
  public: 
    void draw();
    const char * appName = "Scanner";
    unsigned char * appIcon = scannerIcon;
};
