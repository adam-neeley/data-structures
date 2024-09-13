// CS 211 Fall 2024 - Programming Assignment #1
// Modified by: Adam Neeley
// 9/12/24

#include <cstdlib>
#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

Node *inputList() {
  double value;

  cout << "Enter a numeric value (-1 to finish): ";
  cin >> value;

  if (value == -1)
    return NULL;

  Node *node;
  node = new Node(value);
  node->setLink(inputList());
  return node;
}

void printList(Node *node) {
  if (node == NULL)
    return;
  cout << " " << node->getData();
  printList(node->getLink());
}

double sumList(Node *node) {
  if (node == NULL)
    return 0;
  return node->getData() + sumList(node->getLink());
}

double productList(Node *node) {
  if (node == NULL)
    return 1;
  return node->getData() * productList(node->getLink());
}

void deleteList(Node *node) {
  if (node == NULL)
    return;
  deleteList(node->getLink());
  delete node;
}

void listPlay() {
  Node *head = inputList();

  cout << "Numbers entered:";
  printList(head);
  cout << endl;

  if (head == NULL)
    return;

  cout << "Sum: " << sumList(head) << endl;
  cout << "Product: " << productList(head) << endl;

  deleteList(head);
};
