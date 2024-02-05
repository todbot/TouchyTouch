# TouchyTouch

Capacitive sense touch Arduino library that mimics how CircuitPython `touchio` works.

This library emulates how the CircuitPython touchio library implements capacitive touch sensing.
It also includes basic button debouncing.

It is based on the CircuitPython "touchio" code at: https://github.com/adafruit/circuitpython/blob/main/shared-module/touchio/TouchIn.c
The `touchio` code is not platform-specific, but does require a 1M pull-down resistor.

Thus the `TouchyTouch` Arduino library is also not platform-specific and also requires a pull-down resistor.
