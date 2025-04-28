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
BNode* searchBNode(uint8_t gpio);
BNode* addBNode(uint8_t gpio);
BNode* addBNodeIfNotExists(uint8_t gpio);
void removeBNode(uint8_t gpio);
    void print();  //only for debug
    ~BList();
};

#endif
