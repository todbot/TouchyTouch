
#include "TouchyTouch.h"

// all 29 GPIO of the Raspberry Pi Pico, even GPIO 25, aka LED_BUILTIN
const int touch_pins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8,
                          9, 10, 11, 12, 13, 14, 15,
                          16, 17, 18, 19, 20, 21, 22, 23,
                          24, 25, 26, 27, 28};
const int touch_count = sizeof(touch_pins) / sizeof(int);
const int touch_threshold_adjust = 100;

TouchyTouch touches[touch_count];

void setup() {
  Serial.begin(115200);
  Serial.println("TouchyTouch pico_all_pins");

  pinMode(LED_BUILTIN, OUTPUT);

  // configure touch buttons
  for (int i = 0; i < touch_count; i++) {
    touches[i].begin( touch_pins[i] );
    touches[i].threshold += touch_threshold_adjust;  // make a bit more noise-proof
  }

}

void loop() {
  for ( int i = 0; i < touch_count; i++) {
    touches[i].update();
    char t = touches[i].touched() ? '|':' ';  // indicates a touched value
    int touchval = touches[i].raw_value / 100;  // make a more printalbe value
    Serial.printf("%c%2d%c", t, touchval, t );
  }
  Serial.println();
  delay(50);
}
