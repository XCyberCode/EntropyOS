# EntropyOS 🌐
_Minimalistic OS for embedded devices_

## Content 📋
- [Apps](#apps)
- [Libraries](#libraries)
  - [AppFramework](#appframework) 
  - [DS1307](#ds1307)
  - [FastString](#faststring)

<a id="apps"></a>
## Apps 🔮
- [ ] Clock ⏰
- [ ] Calendar 📅
- [ ] Calculator 📱
- [ ] Notes 📝
- [ ] Tasks 📑
- [ ] Game Center 🕹️
- [ ] Welcome 🎩
- [ ] Settings ⚙️

<a id="libraries"></a>
## Libraries ⚒️
<a id="appframework"></a>
### App Framework 🔋
Core component of the operating system. Contains user interface abstractions called "widgets" and other useful components.

#### Button
```cpp
#include <AppFramework.hpp>
// Initialization
Button btn(
  uint16_t positionX,    // Horizontal position of the widget
  uint16_t positionY,    // Vertical position of the widget
  uint16_t width,        // Width of the widget
  uint16_t height,       // Height of the widget
  uint16_t cornerRadius, // Radius of the widget border corners
  uint8_t textAnchorV,   // Vertical postion of the text (1 - top, 2 - center, 3 - bottom)
  uint8_t textAnchorH    // Horizontal position of the text (1 - left, 2 - center, 3 - right)
);

// Widget positioning
btn.setPosition(positionX, positionY); // Set position of the widget
btn.setPositionX(positionX); // Set horizontal position of the widget
btn.setPositionY(positionY); // Set vertical position of the widget

// Widget size configuration
btn.setSize(width, height); // Set size of the widget
btn.setWidth(width);        // Set width of the widget
btn.setHeight(height);      // Set height of the widget

// Widget text positioning
btn.setTextAnchor(textAnchorV, textAnchorH);
btn.setTextAnchorV(textAnchorV); // Set vertical text position of the widget
btn.setTextAnchorH(textAnchorH); // Set horizontal text position of the widget

// Widget state
btn.setFocus(state);         // Set focus state (if true, content color of the widget will be inverted)
btn.setCornerRadius(number); // Set corner radius of the widget border

// Draw widget
btn.draw(const char * text);
```

#### TextLabel
```cpp
#include <AppFramework.hpp>
// Initialization
TextLabel label(
  uint16_t positionX,  // Horizontal position of the widget 
  uint16_t positionY,  // Vertical position of the widget
  uint16_t width,      // Width of the widget
  uint16_t height,     // Height of the widget 
  uint8_t textAnchorV, // Vertical postion of the text (1 - top, 2 - center, 3 - bottom)
  uint8_t textAnchorH  // Horizontal position of the text (1 - left, 2 - center, 3 - right)
);

// Widget positioning
label.setPosition(positionX, positionY); // Set position of the widget
label.setPositionX(positionX); // Set horizontal position of the widget
label.setPositionY(positionY); // Set vertical position of the widget

// Widget size configuration
label.setSize(width, height); // Set size of the widget
label.setWidth(width);        // Set width of the widget
label.setHeight(height);      // Set height of the widget

// Widget text positioning
label.setTextAnchor(textAnchorV, textAnchorH); // Set text position of the widget 
label.setTextAnchorV(textAnchorV); // Set vertical text position of the widget
label.setTextAnchorH(textAnchorH); // Set horizontal text position of the widget

// Draw widget
label.draw(const char * text);
```

#### Icon
```cpp
#include <AppFramework.hpp>
// Initialization
Icon icon(
  uint16_t positionX,    // Horizontal position of the widget
  uint16_t positionY,    // Vertical position of the widget
  uint16_t width,        // Width of the widget
  uint16_t height,       // Height of the widget
  bool isBordered,       // Border state. If true, a border will be drawn
  uint16_t cornerRadius, // Radius of the widget border corners
  uint16_t borderPadding // Padding between the border and the widget content
);

// Widget positioning
btn.setPosition(positionX, positionY); // Set position of the widget
btn.setPositionX(positionX); // Set horizontal position of the widget
btn.setPositionY(positionY); // Set vertical position of the widget

// Widget size configuration
btn.setSize(width, height); // Set size of the widget
btn.setWidth(width);        // Set width of the widget
btn.setHeight(height);      // Set height of the widget

// Widget border
btn.setBorder(state);         // Set border state (if true, a border will be drawn)
btn.setCornerRadius(number);  // Set corner radius of the widget border
btn.setBorderPadding(number); // Set the padding between the border and the widget content

// Draw widget
btn.draw(unsigned char xbmImage[]);
```

#### Timer
```cpp
// Initialization
Timer tmr(
  uint32_t periodMs, // Timer period in milliseconds
  bool isTimer,      // Timer mode. If true, the timer will stop after one round
  bool isRunning     // Timer state. If true, the timer will start after initialization 
);

// Timer methods
tmr.start();   // Start timer
tmr.stop();    // Stop timer
tmr.setMode(); // Set timer mode
tmr.tick();    // Get the timer status
```

<a id="ds1307"></a>
### DS1307 ⏰
Dallas Semiconductor DS1307 chip control library.

#### Usage
```cpp
#include <DS1307.h>
// Initialization
DS1307 clockChip;

clockChip.read(); // Read data from the chip

clockChip.getSecond();     // Get current second value
clockChip.getMinute();     // Get current minute value
clockChip.getHour();       // Get current hour value
clockChip.getDayOfWeek();  // Get current dayOfWeek value
clockChip.getDayOfMonth(); // Get current dayOfMonth value
clockChip.getMonth();      // Get current month value
clockChip.getYear();       // Get current year value

// Set current time and date data
clockChip.set(
  uint8_t second,     // Seconds (0 - 59)
  uint8_t minute,     // Minutes (0 - 59)
  uint8_t hour,       // Hours (0 - 23)
  uint8_t dayOfWeek,  // Day of week (0 - Sunday, 6 - Saturday)
  uint8_t dayOfMonth, // Day of month (0 - 28/29/30/31)
  uint8_t month,      // Month (1 - 12)
  uint8_t year        // Year (xx00 - xx99);
);
```

<a id="faststring"></a>
### FastString ⚡
Static alternative for Arduino String.

#### Usage
```cpp
#include <FastString.h>
// Initialization
FastString<BUFFER_SIZE> str;

// Initialization with a value (const char * only)
FastString<BUFFER_SIZE> strValue = "Nothing";

// Buffer operations
str.clearBuffer(); // Clear the buffer
str.getLength();   // Get the string length
str.getCapacity(); // Get the maximum string length (buffer size)
str.getBuffer();   // Get the buffer (char[])

// Addition
str.add(char / char * / const char * / (unsigned) (short, long) int / FastString);
str += char / char * / const char * / (unsigned) (short, long)  int/ FastString;
str = char / char * / const char * / (unsigned) (short, long) int / FastString;
str = str + char / char * / const char * / (unsigned) (short, long) int / FastString;

// Buffer access
// Set a char
str[index] = '1';
str.setCharAt(index, '1');

// Get a char
char chr = str[index];
char chr = str.getCharAt(index, '1');

// Buffer modification
// Remove data with a shift
str.remove(index, '1')
str.remove(index, "value");

// Insert data with a shift
str.insert(index, '1');
str.insert(index, "value");

// Replace data
str.replace(index, '1');
str.replace(index, "value");
```
