// CS 211 Fall 2024 - Programming Assignment #1
//

#include <cstdlib>
#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

void listPlay() {

  Node *head = NULL;
  Node *nodePtr = head;

  int value;

  while (true) {
    std::cout << "Enter a numeric value (-1 to finish): ";
    std::cin >> value;

    if (value == -1)
      break; // -1 escapes loop

    Node *nextNodePtr;
    nextNodePtr = new Node(value); // create next node

    if (head == NULL)
      head = nextNodePtr;
    else
      nodePtr->setLink(nextNodePtr);

    nodePtr = nextNodePtr;
  }

  //

  std::cout << "Numbers entered:";

  double sum = 0;
  double product = 1;

  nodePtr = head;
  while (nodePtr != NULL) {
    double data = nodePtr->getData();
    sum += data;
    product *= data;
    std::cout << " " << nodePtr->getData();
    nodePtr = nodePtr->getLink();
  }

  if (head == NULL)
    return;

  std::cout << std::endl;
  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Product: " << product << std::endl;

  // delete list
  nodePtr = head;
  while (nodePtr != NULL) {
    Node *nextPtr = nodePtr->getLink();
    std::cout << "Deleting: " << nodePtr->getData() << std::endl;
    delete nodePtr;
    nodePtr = nextPtr;
  }
};
