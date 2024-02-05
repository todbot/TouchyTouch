# TouchyTouch

Capacitive sense touch Arduino library that mimics how CircuitPython `touchio` works.

This library emulates how the CircuitPython touchio library implements capacitive touch sensing.
It also includes basic button debouncing.

It is based on the CircuitPython "touchio" code at: https://github.com/adafruit/circuitpython/blob/main/shared-module/touchio/TouchIn.c
The `touchio` code is not platform-specific, but does require a 1M pull-down resistor.

Thus the `TouchyTouch` Arduino library is also not platform-specific and also requires a pull-down resistor.

### How it works:

From the `touchio` C code:
```
// This is a capacitive touch sensing routine using a single digital
// pin.  The pin should be connected to the sensing pad, and to ground
// via a 1Mohm or thereabout drain resistor.  When a reading is taken,
// the pin's capacitance is charged by setting it to a digital output
// 'high' for a few microseconds, and then it is changed to a high
// impedance input.  We measure how long it takes to discharge through
// the resistor (around 50us), using a busy-waiting loop, and average
// over N_SAMPLES cycles to reduce the effects of noise.
```
