//
// Created by דביר on 3/23/2025.
//

#include "Stack.h"
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}


void Stack:: push(int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
}

int Stack:: pop() {
    if (isEmpty()) throw std::runtime_error("Stack is empty");

    int val = head->num;
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
    return val;
}


int Stack::top() const {
    if (isEmpty()) throw std::runtime_error("Stack is empty");
    return head->num;
}

bool Stack:: isEmpty() const {
    return head == nullptr;
}