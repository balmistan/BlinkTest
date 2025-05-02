#include <Arduino.h>
#include "blist.h"

#define GPIOOUT 5

BList list;

void setup() {
    Serial.begin(9600);
    pinMode(GPIOOUT, OUTPUT);

    list.configureBlink(GPIOOUT, 1000, 1000);
    list.startBlink(GPIOOUT);
}

void loop() {
    // Your loop logic here
}
