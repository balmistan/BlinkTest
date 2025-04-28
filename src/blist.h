#ifndef BLIST_H
#define BLIST_H

#include "bnode.h"
#include <iostream>
using namespace std;

class BList {
private:
    BNode* head;
    BNode* last;
public:
    BList();
void print();  //only for debug

void configureBlink(uint8_t gpio, unsigned long ms_on, unsigned long ms_off);


    ~BList();

private:
BNode* searchBNode(uint8_t gpio);
BNode* addBNode(uint8_t gpio);
BNode* addBNodeIfNotExists(uint8_t gpio);
void removeBNode(uint8_t gpio);
    
};

#endif
