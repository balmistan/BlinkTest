#ifndef BLINKLIST_H
#define BLINKLIST_H

class BlinkList {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* head;

public:
    BlinkList();                 // Constructor
    ~BlinkList();                // Destructor

    void add(int value);         // Add a value to the end
    bool search(int value);      // Search for a value
    bool remove(int value);      // Remove a node by value
    void print();                // Print all elements (for debug)
};

#endif
