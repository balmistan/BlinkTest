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

void BlinkList::add(int value) {
    Node* newNode = new Node{value, nullptr};

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

bool BlinkList::search(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool BlinkList::remove(int value) {
    if (head == nullptr) return false;

    if (head->value == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->value != value) {
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
