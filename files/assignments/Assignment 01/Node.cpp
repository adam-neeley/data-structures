// CS 211 Fall 2024 - Programming Assignment #1
//


//    Implements the methods for the Node class
//
//    written by: Sharon Tuttle
//    modified by: David Tuttle
//    last modified: 11 Sep 2024

#include <cstdlib>
#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

// constructors

// Zero-argument constructor: expects nothing, and creates
//     a new Node instance whose data field is the default
// for the valueType, and whose link field is NULL

Node::Node() {
    dataField = valueType();
    linkPtr = NULL;
}

// One-argument constructor: expects a pointer to a Node, and
// creates a new Node instance whose data field is the default
// for the valueType, and whose link field is set to the given
// pointer

Node::Node(Node *initLink) {
    dataField = valueType();
    linkPtr = initLink;
}

// One-argument constructor: expects a valueType value, and
// creates a new Node instance whose data field is the given
// value, and whose link field is set to NULL

Node::Node(const valueType& initData) {
    dataField = initData;
    linkPtr = NULL;
}

// Two-argument constructor: expects a valueType value and a pointer
// to a Node, and creates a new Node instance whose data field is
// the given valueType value and whose link field is set to the
// given pointer

Node::Node(const valueType& initData, Node *initLink) {
    dataField = initData;
    linkPtr = initLink;
}

// accessors

// getData: void -> valueType
// Expects nothing
// Returns the value of the calling Node's data field

valueType Node::getData() const {
    return dataField;
}

// getLink: void -> Node*
// Expects nothing
// Returns the value of the calling Node's link field
// TWO VERSIONS provided:
//     One returns a const version of the Node*, and one does not
//     Compiler allegedly uses the "correct" one for a given call.

Node* Node::getLink() const {
    return linkPtr;
}

Node* Node::getLink() {
    return linkPtr;
}

// setters

// setData: valueType -> void
// Expects data to be stored in a Node
// Returns nothing
// Side Effects: sets the calling Node's data field to the value

void Node::setData(const valueType& newData) {
    dataField = newData;
}

// setLink: Node* -> void
// Expects a pointer to a Node
// Returns nothing
// Side Effects: sets the calling Node's link field to the given Node*

void Node::setLink(Node *newLinkPtr) {
    linkPtr = newLinkPtr;
}
