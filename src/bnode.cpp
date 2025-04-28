#include "bnode.h"

BNode::BNode(uint8_t gpio) {
    gpio = gpio;
    next = nullptr;
}
