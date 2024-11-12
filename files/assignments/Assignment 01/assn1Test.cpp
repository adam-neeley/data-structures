// CS 211 Fall 2024 - Programming Assignment #1
//

#include <cstdlib>
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

// When main() is run, the following should be printed
// to the screen:

// testing class Node - true means test passed:
// --------------------------------------------
// testing constructors and getters:
// true true true true true true true true

// testing setters:
// true true true

// walking through little 4-node proto-list:
// -----------------------------------------
// next is pointing to node w/data: 100
// next is pointing to node w/data: 200
// next is pointing to node w/data: 300
// next is pointing to node w/data: 400

int main() {
    cout << boolalpha << endl;

    // Calling all four Node constructors
    // Note that the list is NOT fully built here!

    Node newNode4;
    Node newNode3(&newNode4);
    Node newNode2(200);
    Node newNode1(100, &newNode2);

    cout << "Testing class Node - true means test passed:" << endl;
    cout << "--------------------------------------------" << endl;

    cout << "*** Testing constructors and accessors:" << endl;

    cout << (newNode4.getData() == 0) << " ";
    cout << (newNode3.getData() == 0) << " ";
    cout << (newNode2.getData() == 200) << " ";
    cout << (newNode1.getData() == 100) <<  " ";

    cout << (newNode4.getLink() == NULL) << " ";
    cout << (newNode3.getLink() == &newNode4) << " ";
    cout << (newNode2.getLink() == NULL) << " ";
    cout << (newNode1.getLink() == &newNode2) << " ";
    cout << endl << endl;

    // HERE is where we manually construct the linked list!

    cout << "*** Testing setters:" << endl;

    newNode4.setData(400);
    cout << (newNode4.getData() == 400) << " ";

    newNode3.setData(300);
    cout << (newNode3.getData() == 300) << " ";

    newNode2.setLink(&newNode3);
    cout << (newNode2.getLink() == &newNode3) << " ";
    cout << endl << endl;

    // Now we should have a fully constructed linked list:
    // 100 --> 200 --> 300 --> 400 --> NULL

    cout << "Walking through the linked list:" << endl;
    cout << "----------------------------------" << endl;

    Node *nextPtr;
    nextPtr = &newNode1;  // Set pointer to "head" of list

    while (nextPtr != NULL) {
        cout << "nextPtr is pointing to node with value: "
                  << nextPtr->getData() << endl;
        nextPtr = nextPtr->getLink();
    }

    cout << endl;
    return EXIT_SUCCESS;
}
