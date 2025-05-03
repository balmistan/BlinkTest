#include "bnode.h"

BNode::BNode(uint8_t gpio) {
    this->gpio = gpio;
    this->enabled = false;
    this->tact_on = 100;
    this->tact_off = 100;
    this->next = nullptr;
}



