//#dvir.opa@gmail.com

#ifndef STACK_H
#define STACK_H
#include <stdexcept>

class Stack {
private:
    struct Node {
        int num;
        Node* next;
    };

    Node* head;

public:
    Stack() : head(nullptr) {}

    ~Stack();

    void push(int val);

    int pop();

    int top()const;

    bool isEmpty() const;
};

#endif //STACK_H
