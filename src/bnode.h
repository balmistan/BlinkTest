#ifndef BNODE_H
#define BNODE_H
#include <Arduino.h>

class BNode
{
public:
    uint8_t gpio;
    bool enabled;
    bool state;
    unsigned long tact_on;
    unsigned long tact_off;
    unsigned long tact_counter;
    BNode *next;

    BNode(uint8_t gpio);
};

#endif
