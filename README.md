# EntropyOS
Minimalistic operating system for embedded devices

## Content
- [Apps](#apps)
- [Libraries](#libraries)

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
### App Framework 🔋
Core component of the operating system. Contains user interface abstractions called "widgets"

- Button
```cpp
#include <AppFramework.hpp>
// Initialization
Button btn(positionX, positionY, width, height, cornerRadius, textAnchorV, textAnchorH)

// Widget positioning
btn.setPosition(positionX, positionY); // Set position of the widget
btn.setPositionX(positionX); // Set horizontal position of the widget
btn.setPositionY(positionY); // Set vertical position of the widget

// Widget size configuration
btn.setSize(width, height); // Set size of the widget
btn.setWidth(width); // Set width of the widget
btn.setHeight(height); // Set height of the widget

// Widget text positioning
btn.setTextAnchor(textAnchorV, textAnchorH); // Set text position of the widget (vertical: 1 - top, 2 - center, 3 - bottom; horizontal: 1 - left, 2 - center, 3 - right)
btn.setTextAnchorV(textAnchorV); // Set vertical text position of the widget
btn.setTextAnchorH(textAnchorH); // Set horizontal text position of the widget

// Widget state
btn.setFocus(state); // Set focus state (if true, content color of the widget will be inverted)
btn.setCornerRadius(number); // Set corner radius of the widget border
```

- TextLabel
```cpp
#include <AppFramework.hpp>
// Initialization
TextLabel label(positionX, positionY, width, height, textAnchorV, textAnchorH)

// Widget positioning
label.setPosition(positionX, positionY); // Set position of the widget
label.setPositionX(positionX); // Set horizontal position of the widget
label.setPositionY(positionY); // Set vertical position of the widget

// Widget size configuration
label.setSize(width, height); // Set size of the widget
label.setWidth(width); // Set width of the widget
label.setHeight(height); // Set height of the widget

// Widget text positioning
label.setTextAnchor(textAnchorV, textAnchorH); // Set text position of the widget (vertical: 1 - top, 2 - center, 3 - bottom; horizontal: 1 - left, 2 - center, 3 - right)
label.setTextAnchorV(textAnchorV); // Set vertical text position of the widget
label.setTextAnchorH(textAnchorH); // Set horizontal text position of the widget
```

- Icon
```cpp
#include <AppFramework.hpp>
```

### DS1307 ⏰
### FastString ⚡





