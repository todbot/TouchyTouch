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

    if ( touches[i].rose() ) {
      Serial.print("Pin pressed ");
      Serial.println( touches[i].pin );
      digitalWrite(LED_BUILTIN, HIGH);
    }

    if ( touches[i].fell() ) {
      Serial.print("Pin release ");
      Serial.println( touches[i].pin );
      digitalWrite(LED_BUILTIN, LOW);
    }

  }
}
