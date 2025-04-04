//#dvir.opa@gmail.com

#include <stdexcept>

#include "Queue.h"
Queue::Queue(int size ) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue:: push(int x) {
    if (count == capacity) {
        // הכפלת הגודל
        int* newArr = new int[capacity * 2];
        for (int i = 0; i < count; ++i) {
            newArr[i] = arr[(front + i) % capacity];
        }
        delete[] arr;
        arr = newArr;
        front = 0;
        rear = count - 1;
        capacity *= 2;
    }

    rear = (rear + 1) % capacity;
    arr[rear] = x;
    count++;
}

void Queue:: pop() {
    if (isEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }

    front = (front + 1) % capacity;
    count--;
}

int Queue:: peek() const {
    if (isEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }
    return arr[front];
}

bool Queue:: isEmpty() const {
    return count == 0;
}

int Queue:: size() const {
    return count;
}

void Queue:: printQueue() const {
    std::cout << "Queue: ";
    for (int i = 0; i < count; ++i) {
        std::cout << arr[(front + i) % capacity] << " ";
    }
    std::cout << "\n";
}
