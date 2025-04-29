#include "blist.h"

Lista::Lista()
{
    head = nullptr;
}

BNode* searchBNode(uint8_t gpio){
  BNode* tmp = head;
  while(tmp != nullptr){
   if(tmp->gpio == gpio){
return tmp;
}
}
return nullptr;
}

BNode* addBNodeIfNotExists(uint8_t gpio){
BNode* tmp = searchBNode(gpio);
if(tmp == nullptr){
   tmp = createBNode(gpio);
}
return tmp;
}

BNode* BList::addBNode(uint8_t gpio)
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
return newbnode;
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

void BList::print() {
    Node* current = head;
    while (current != nullptr) {
// For embedded systems
Serial.print("gpio: ");    Serial.println(current->gpio);  

        current = current->next;
    }
}