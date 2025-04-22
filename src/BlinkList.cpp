#include "BlinkList.h"
#include <Arduino.h>  // Only needed for Serial printing

BlinkList::BlinkList() {
    head = nullptr;
}

BlinkList::~BlinkList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void BlinkList::add(uint8_t gpio) {
    Node* newNode = new Node{gpio, nullptr};

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool BlinkList::search(uint8_t gpio) {
    Node* current = head;
    while (current != nullptr) {
        if (current->gpio == gpio) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool BlinkList::remove(uint8_t gpio) {
    if (head == nullptr) return false;

    if (head->gpio == gpio) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->gpio != gpio) {
        current = current->next;
    }

    if (current->next == nullptr) return false;

    Node* toDelete = current->next;
    current->next = current->next->next;
    delete toDelete;
    return true;
}

void BlinkList::print() {
    Node* current = head;
    while (current != nullptr) {
        Serial.println(current->value);  // For embedded systems
        current = current->next;
    }
}
