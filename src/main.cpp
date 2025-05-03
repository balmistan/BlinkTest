#include <Arduino.h>
#include <Ticker.h>
#include "blist.h"

#define GPIOOUT 5

Ticker timer;
BList list;

void IRAM_ATTR onTimer();

void setup() {
    Serial.begin(9600);
    pinMode(GPIOOUT, OUTPUT);
      timer.attach_ms(10, onTimer);  // Call onTimer every 10 ms
    list.configureBlink(GPIOOUT, 1000, 1000);
    list.startBlink(GPIOOUT);
    list.print();
}

void IRAM_ATTR onTimer() {
  list.interruptCheck();  //update interrupt management list
}


void loop() {
    delay(2000);
    delay(2000);
    delay(2000);
    delay(2000);
    for(int i=0; i<100; i++){
    list.changeGpioState();
    list.print();
    delay(20);
    }
   // list.print();
    //delay(25);
    //list.print();

}
