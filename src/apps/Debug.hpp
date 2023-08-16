// Libraries
#include <Arduino.h>

// Local dependencies
#include <core/Icons.hpp>

class Debug
{
  public:
    void draw();
    const char * name = "Debug";
    unsigned char * icon = clockIcon;
};
