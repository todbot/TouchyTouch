/*
  DESCRIPTION
  ====================
  Simple example of the TouchyTouch library showing the .pressed() and .released() methods.

  Set touch_pins to the pins to act as touch sensors.
  These pins must have a 1M pull-down resistor.

*/

#include "TouchyTouch.h"

const int touch_pins[] = {4, 5, 6, };
const int touch_count = sizeof(touch_pins) / sizeof(int);

TouchyTouch touches[touch_count];

void setup() {
  Serial.begin(115200);
  Serial.println("TouchyTouch simple_debounce");

  pinMode(LED_BUILTIN, OUTPUT);

  for (int i = 0; i < touch_count; i++) {
    touches[i].begin( touch_pins[i] );
  }

}

void loop() {
  for ( int i = 0; i < touch_count; i++) {
    touches[i].update();

    if ( touches[i].pressed() ) {
      Serial.print("Pin pressed ");
      Serial.println( touches[i].pin );
      digitalWrite(LED_BUILTIN, HIGH);
    }

    if ( touches[i].released() ) {
      Serial.print("Pin release ");
      Serial.println( touches[i].pin );
      digitalWrite(LED_BUILTIN, LOW);
    }

  }
}
