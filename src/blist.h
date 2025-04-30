#ifndef BLIST_H
#define BLIST_H

#include "bnode.h"
#include <iostream>
using namespace std;

class BList
{
private:
    BNode *head;
    BNode *last;

public:
    BList();
    void print(); // only for debug

    void configureBlink(uint8_t gpio, unsigned long ms_on, unsigned long ms_off);

void startBlink(uint8_t gpio);
void stopBlink(uint8_t gpio, bool endstate);
void stopBlink(uint8_t gpio);
void removeBlink(uint8_t gpio, bool endstate);
void removeBlink(uint8_t gpio);

    ~BList();

private:
    BNode* searchBNode(uint8_t gpio);
    BNode* addBNode(uint8_t gpio);
    BNode* addBNodeIfNotExists(uint8_t gpio);
    bool removeBNode(uint8_t gpio);
};

#endif
