#ifndef BLINKLIST_H
#define BLINKLIST_H
#include <arduino.h>



class BlinkList {
private:
    struct Node {
        uint8_t gpio;
bool enabled;
bool state;
unsigned long on_tact;
unsigned long off_tact;
unsigned long tact_counter:
        Node* next;
    };

    Node* head;
Node* last;

public:
    BlinkList();                 // Constructor
    ~BlinkList();                // Destructor

      Node* configure(uint8_t gpio, unsigned long t_on_ms, unsigned long t_off_ms     // Add a new node to the end and configure  it
    Node* search(uint8_t gpio);      // Search for a value
    bool remove(uint8_t gpio);      // Remove a node by value
    void print();                // Print all elements (for debug)
};

#endif
