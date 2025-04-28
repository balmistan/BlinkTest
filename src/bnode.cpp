#include "bnode.h"

BNode::BNode(uint8_t gpio) {
    gpio = gpio;
    enabled = false;
    tact_on = 100;
    tact_off = 100;
    next = nullptr;
}



