
#include "TouchyTouch.h"

const int touch_pins[] = {4, 5, 6, };
const int touch_count = sizeof(touch_pins) / sizeof(int);

TouchyTouch touches[touch_count];

void setup() {
  Serial.begin(115200);
  Serial.println("TouchyTouch simpletest");

  pinMode(LED_BUILTIN, OUTPUT);

  // Touch buttons
  for (int i = 0; i < touch_count; i++) {
    touches[i].begin( touch_pins[i] );
  }

}

void loop() {
  for ( int i = 0; i < touch_count; i++) {
    touches[i].update();

    if ( touches[i].isTouched() ) {
      Serial.print("Pin touched ");
      Serial.println(i);
    }
  }
  delay(10);
}
