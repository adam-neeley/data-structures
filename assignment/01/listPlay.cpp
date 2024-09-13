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
      break;

    Node *nextNode;
    nextNode = new Node(value);

    if (head == NULL) {
      head = nextNode;
      nodePtr = head;
    } else {
      nodePtr->setLink(nextNode);
      nodePtr = nextNode;
    }
  }

  std::cout << "Numbers entered:";

  while (head != NULL) {
    std::cout << " " << head->getData();
    head = head->getLink();
  }
  std::cout << std::endl;
};

int main() {
  listPlay();
  return 0;
}
