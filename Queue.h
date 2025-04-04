//#dvir.opa@gmail.com
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue {
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size = 4);

    ~Queue();


    void push(int x);

    void pop();

    int peek() const ;

    bool isEmpty() const;

    int size() const;

    void printQueue() const ;
};

#endif // QUEUE_H
