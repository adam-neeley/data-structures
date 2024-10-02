#ifndef SORTEDNUMBERLIST_H
#define SORTEDNUMBERLIST_H
#include "NumberList.h"
#include "NumberListNode.h"

class SortedNumberList : public NumberList {
private:
  void InsertAfter(NumberListNode *node, NumberListNode *newNode) {
    if (head == nullptr)
      head = tail = newNode;
    else if (node == tail) {
      tail->SetNext(newNode);
      newNode->SetPrevious(tail);
      tail = newNode;
    } else {
      newNode->SetNext(node->GetNext());
      newNode->SetPrevious(node);
      node->SetNext(newNode);
    }
  }

  NumberListNode *Find(double number) {
    NumberListNode *node = head;
    while (node) {
      if (node->GetData() == number)
        return node;
      node = node->GetNext();
    }
    return nullptr;
  }

  NumberListNode *FindLastLessThan(double number) {
    NumberListNode *node = tail;
    while (node) {
      if (node->GetData() < number)
        return node;
      node = node->GetPrevious();
    }
    return nullptr;
  }

public:
  SortedNumberList() {
    head = nullptr;
    tail = nullptr;
  }

  void Insert(double value) {
    NumberListNode *node = new NumberListNode(value);

    if (!head || value < head->GetData()) {
      node->SetNext(head);
      if (head)
        head->SetPrevious(node);
      head = node;
    } else {
      NumberListNode *current = head;
      while (current->GetNext() && current->GetNext()->GetData() < value) {
        current = current->GetNext();
      }
      node->SetNext(current->GetNext());
      if (current->GetNext())
        current->GetNext()->SetPrevious(node);
      current->SetNext(node);
      node->SetPrevious(current);
      if (current == tail)
        tail = node;
    }
  }

  bool Remove(double number) {
    NumberListNode *node = Find(number);
    if (node == nullptr)
      return false;

    NumberListNode *succ = node->GetNext();
    NumberListNode *pred = node->GetPrevious();

    if (succ)
      succ->SetPrevious(pred);
    if (pred)
      pred->SetNext(succ);
    if (node == head)
      head = succ;
    if (node == tail)
      tail = pred;

    delete node;
    return true;
  }
};

#endif
