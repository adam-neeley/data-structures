// CS 211 Fall 2024 - Week 09 Lab
// ArrayQueue class

//---------------------------------------------------------------
// File: testQueue.cpp
// Purpose: Main file with tests for a demonstration of a queue.
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "ArrayQueue.h"

using namespace std;

int main() {
    cout << boolalpha;

    // "el" is short for "element"
    int el;

    cout << "Simple Queue Demonstration -- Creating a queue\n";

    ArrayQueue *theQueue = new ArrayQueue(); // Create a queue object

    cout << "Queue created...\n";

    cout << "(Should be true) ";
    cout << "Is the queue empty to start? " << theQueue->isEmpty() << endl;
    cout << "(Should be false) ";
    cout << "Is the queue full to start? " << theQueue->isFull() << endl;

    for (int i=1; i<10; i++) {
        cout << "(Should be true) ";
        cout << "Adding " << i << " to queue: " << theQueue->enQueue(i) << endl;
    }

    cout << "Element at front is " << theQueue->firstEl() << endl;

    cout << "(Should be false) ";
    cout << "Is the queue full? " << theQueue->isFull() << endl;

    cout << "(Should be true) ";
    cout << "Adding 10 to queue: " << theQueue->enQueue(10) << endl;

    cout << "(Should be true) ";
    cout << "Is the queue full? " << theQueue->isFull() << endl;

    theQueue->printArray();

    cout << "(Should be false) ";
    cout << "Trying to add 11 to queue: " << theQueue->enQueue(11) << endl;

    cout << "(Should be true) ";
    cout << "Is the queue full? " << theQueue->isFull() << endl;

    cout << "(Should be false) ";
    cout << "Is the queue empty? " << theQueue->isEmpty() << endl;

    for (int i=1; i<10; i++) {
        cout << "Element at front is " << theQueue->firstEl() << endl;
        cout << "Removing " << theQueue->deQueue() << " from queue " << endl;
    }

    cout << "(Should be false) ";
    cout << "Is the queue full? " << theQueue->isFull() << endl;

    cout << "(Should be false) ";
    cout << "Is the queue empty? " << theQueue->isEmpty() << endl;

    cout << "Element at front is " << theQueue->firstEl() << endl;

    theQueue->printArray();

    cout << "Removing " << theQueue->deQueue() << " from queue " << endl;

    cout << "(Should be false) ";
    cout << "Is the queue full? " << theQueue->isFull() << endl;

    cout << "(Should be true) ";
    cout << "Is the queue empty? " << theQueue->isEmpty() << endl;

    for (int i=1; i<10; i++) {
        cout << "(Should be true) ";
        cout << "Adding " << i*100 << " to queue: "
             << theQueue->enQueue(i*100) << endl;
    }

    theQueue->printArray();

    for (int i=1; i<7; i++) {
        cout << "Removing " << theQueue->deQueue() << " from queue " << endl;
    }

    cout << "Element at front is " << theQueue->firstEl() << endl;

    theQueue->printArray();

    for (int i=10; i<12; i++) {
        cout << "(Should be true) ";
        cout << "Adding " << i*1000 << " to queue: "
        << theQueue->enQueue(i*1000) << endl;
    }

    theQueue->printArray();

    while (! theQueue->isEmpty()) {
        cout << "Element at front is " << theQueue->firstEl() << endl;
        cout << "Removing " << theQueue->deQueue() << " from queue " << endl;
    }

    cout << "(Should be true) ";
    cout << "Is the queue empty? " << theQueue->isEmpty() << endl;

    theQueue->printArray();

    for (int i=12; i<17; i++) {
        cout << "(Should be true) ";
        cout << "Adding " << i*10 << " to queue: " << theQueue->enQueue(i*10)
             << endl;
    }

    cout << "Element at front is " << theQueue->firstEl() << endl;

    theQueue->printArray();

    cout << "Clearing queue " << endl;
    theQueue->clearQueue();
    cout << endl;

    cout << "(Should be true) ";
    cout << "Is the queue empty? " << theQueue->isEmpty() << endl;

    return EXIT_SUCCESS;
}
