// CS 211 Fall 2024 - Week 08 Lab
// Adam Neeley

//---------------------------------------------------------------
// File: ArrayStack.cpp
// Purpose: Implementation file for a demonstration of a stack  
//          implemented as an array.    Data type: Double
//
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include "ArrayStack.h"

//--------------------------------------------
// Function: ArrayStack()
// Purpose: Class constructor
// Returns: void
//--------------------------------------------

ArrayStack::ArrayStack() {
    // top is the index of the array where the top
    // of the stack is; a value of -1 means the
    // stack is empty
    top = -1;
    theStack = new T[capacity];
}

//--------------------------------------------
// Function: clearStack()
// Purpose: Remove all items from the stack
// Returns: void
//--------------------------------------------

void ArrayStack::clearStack() {
    top = -1; // Reset count to start over
              // NOTE: There's no need to reset
              // array values!  Just reset index
    capacity = CAPACITY;
}

//--------------------------------------------
// Function: push()
// Purpose: Push an item onto the stack.
// Returns: true if push was successful
//          or false if the push failed.
//--------------------------------------------

bool ArrayStack::push(T el) {
    // Check to see if the stack if full
    if (isFull())
        this->reallocate();

    // Increment array index of top of stack
    top++;
    // Add the item to the stack
    theStack[top] = el;
    return true;
}

int ArrayStack::getSize() {
    return size;
}
int ArrayStack::getCapacity() {
    return capacity;
}

void ArrayStack::reallocate() {
    T *tmp = new T[capacity*2];
    for(int i = 0; i < top; i++ )
        tmp[i] = theStack[i];
    delete[] this->theStack;
    theStack = tmp;
    capacity *= 2;
}


//--------------------------------------------
// Function: pop()
// Purpose: Pop an item from the Stack.
// Returns: value of item popped if pop was successful
//  or -99999.0 if the pop failed (stack empty)
//--------------------------------------------

T ArrayStack::pop() {
    T el;

    // Check for empty stack
    if (isEmpty()) return ERROR_VALUE;
    else {
        el = theStack[top]; // Get value to return
        top--;     // Decrement top index
        return el; // Return popped value
    }
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: Return true if the stack is empty
// Returns: true if empty, otherwise false
//--------------------------------------------

bool ArrayStack::isEmpty() {
    // top value is -1 if the stack is empty
    return (this->top == -1);
}

//--------------------------------------------
// Function: isFull()
// Purpose: Return true if the stack is full
// Returns: true if full, otherwise false
//--------------------------------------------

bool ArrayStack::isFull() {
    return (this->top >= capacity-1);
}
