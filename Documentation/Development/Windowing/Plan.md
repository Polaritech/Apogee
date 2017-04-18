# Windowing Milestone ~ Plan

## Classes
1. [Window](#Window-Class)

### Window Class
A Window allows the use of the operating system's user interface. The operating
system provides functionality to both show intformation to the user as well as
recieve input from the user. The Window interface allows for this by internally
storing a render surface and a list of input devices.

##### Functions
```cpp
virtual auto Show() -> bool
```
The `Show` function sets the visibility of the window to visible and
notifies the operating system that it should display the window on the
output device.

```cpp
virtual auto Hide() -> bool = 0
```
The `Hide` function sets the visibility of the window to hidden and
notifies the operating system that it should remove the window from the
output device.