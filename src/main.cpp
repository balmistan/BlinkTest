#include <Arduino.h>
#include "BlinkList.h"

BlinkList list;

void setup() {
    Serial.begin(9600);

    list.add(42);
    list.add(7);
    list.add(13);

    Serial.println("BlinkList contents:");
    list.print();

    if (list.search(7)) {
        Serial.println("Found 7!");
    }

    list.remove(42);
    Serial.println("After removing 42:");
    list.print();
}

void loop() {
    // Your loop logic here
}
