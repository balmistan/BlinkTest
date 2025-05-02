#ifndef BLINKLIST_H
#define BLINKLIST_H
#include <arduino.h>



class BlinkList {
private:
    struct Node {
        uint8_t gpio;
bool enabled;
bool state;
unsigned int on_tact;
unsigned int off_tact;
unsigned int tact_counter:
        Node* next;
    };

    Node* head;
Node* last;

public:
    BlinkList();                 // Constructor
    ~BlinkList();                // Destructor

      Node* configure(uint8_t gpio, unsigned int t_on_ms, unsigned int t_off_ms     // Add a new node to the end and configure  it
    Node* search(uint8_t gpio);      // Search for a value
    bool remove(uint8_t gpio);      // Remove a node by value
    void print();                // Print all elements (for debug)
};

#endif
