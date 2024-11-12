// CS 211 Fall 2024 - Week 09 Lab
// ArrayQueue class

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

typedef int T;

const int QUEUE_SIZE = 10;

//   class: ArrayQueue
//
//   purpose: To implement a queue using an Array
//
//   constructors: has 1 method:
//            *   Queue is a constructor for a new queue object
//
//   getters: isFull() - returns true if queue is empty
//            isEmpty() - return true if queue is empty
//            firstEl() - return element at front of queue
//
//   setters: clearQueue() - clears queue
//            enQueue(int) - adds element to back of queue
//            deQueue() - removes element from front of queue

class ArrayQueue {
public:
    // CONSTRUCTOR
    ArrayQueue();

    // DESTRUCTOR
    ~ArrayQueue();

    // ACCESSORS
    bool isFull();
    bool isEmpty();
    T firstEl();

    // MUTATORS
    void clearQueue();
    bool enQueue(T);
    T deQueue();

    // OTHER METHODS
    void printArray();

private:

    T *queueArray;
    int frontIndex;
    int backIndex;
    bool queueEmpty;
};

#endif /* ARRAYQUEUE_H */

