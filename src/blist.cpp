#include "blist.h"

BList::BList()
{
    head = nullptr;
    last = nullptr;
}

BNode *BList::addBNode(uint8_t gpio)
{
    BNode *newbnode = new BNode(gpio);
    if (head == nullptr)
    {
        head = newbnode;
        last = newbnode;
    }
    else
    {
        last->next = newbnode;
        last = newbnode;
    }
    return newbnode;
}

BNode *BList::searchBNode(uint8_t gpio)
{
    BNode *current = head;
    while (current != nullptr)
    {
        if (current->gpio == gpio)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

BNode *BList::addBNodeIfNotExists(uint8_t gpio)
{
    BNode *pt = searchBNode(gpio);
    if (pt == nullptr)
    {
        pt = addBNode(gpio);
    }
    return pt;
}

bool BList::removeBNode(uint8_t gpio)
{
    BNode *current = head;
    BNode *prev = head;
    bool deleted = false;
    while (current != nullptr)
    {
        if (current->gpio == gpio)
        {
            prev->next = current->next;
            free(current);
            current = nullptr;
            deleted = true;
            break;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    return deleted;
}

void BList::configureBlink(uint8_t gpio, unsigned int ms_on, unsigned int ms_off)
{
    BNode *pt = addBNodeIfNotExists(gpio);
    pt->tact_on = ms_on / 10;
    pt->tact_off = ms_off / 10;
}

void BList::startBlink(uint8_t gpio)
{
    BNode *pt = addBNodeIfNotExists(gpio);
    pt->state = digitalRead(gpio);
    pt->tact_counter = pt->state ? pt->tact_on : pt->tact_off;
    pt->enabled = true;
}

void BList::stopBlink(uint8_t gpio, bool endstate)
{
    BNode *pt = addBNodeIfNotExists(gpio);
    pt->enabled = false;
    digitalWrite(gpio, endstate);
}

void BList::stopBlink(uint8_t gpio)
{
    BNode *pt = addBNodeIfNotExists(gpio);
    pt->enabled = false;
}

void BList::clearBlink(uint8_t gpio, bool endstate)
{
    digitalWrite(gpio, endstate);
    removeBNode(gpio);
}

void BList::clearBlink(uint8_t gpio)
{
    removeBNode(gpio);
}

void BList::print()
{
    BNode *current = head;
    while (current != nullptr)
    {
        Serial.println(current->gpio); // For embedded systems
        current = current->next;
    }
}

void BList::interruptCheck()
{
    BNode *current = head;
    while (current != nullptr)
    {
        current->tact_counter = !current->tact_counter ? 0 : (current->tact_counter - 1);
        current = current->next;
    }
}

void BList::changeGpioState()
{
    BNode *current = head;
    while (current != nullptr)
    {
        if (current->enabled && !current->tact_counter)
        {
            current->state = !current->state;
            digitalWrite(current->enabled, current->state);
            if (current->state)
                current->tact_counter = current->tact_on;
        }
        else
        {
            current->tact_counter = current->tact_off;
        }
        current = current->next;
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