#include <Arduino.h>
#include <Ticker.h>
#include "blist.h"

#define GPIOOUT 5

Ticker timer;
BList list;

void setup() {
    Serial.begin(9600);
    pinMode(GPIOOUT, OUTPUT);
      timer.attach_ms(10, onTimer);  // Call onTimer every 10 ms
    list.configureBlink(GPIOOUT, 1000, 1000);
    list.startBlink(GPIOOUT);
}



void loop() {
    // Your loop logic here
}
