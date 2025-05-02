#ifndef BNODE_H
#define BNODE_H
#include <Arduino.h>

class BNode
{
public:
    uint8_t gpio;
    bool enabled;
    bool state;
    unsigned int tact_on;
    unsigned int tact_off;
    unsigned int tact_counter;
    BNode *next;

    BNode(uint8_t gpio);
};

#endif
