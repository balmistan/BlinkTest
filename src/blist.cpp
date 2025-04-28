#include "blist.h"

Lista::Lista()
{
    testa = nullptr;
}

void BList::addBNode(uint8_t gpio)
{
    BNode *newbnode = new BNode(gpio);
    if (head == nullptr)
    {
        head = newbnode;
    }
    else
    {
        last = newbnode;
    }
}

BList::~BList()
{
    BNode *current = head;
    while (current != nullptr)
    {
        BNode *temp = current;
        current = current->next;
        delete temp;
    }
}

BList::removeBNode(uint8_t gpio){
BNode* pt = head;
while(pt != nullptr){
  if(pt->gpio == gpio){
    BNode* pt2 = pt;
    free(pt);
    pt = pt2->next;
}
}
}