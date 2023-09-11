// Libraries
#include <Arduino.h>

// Local dependencies
#include <core/Icons.h>

class DebugApp
{
  public:
    void draw();
    const char * appName = "Debug";
    unsigned char * appIcon = clockIcon;
};
