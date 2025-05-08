// stack.h
// Header file for Stack implementation using static array
// Includes definition of Stack class with Peek() function added

#pragma once

#define MAX_ITEMS 100
typedef int ItemType;

class Stack {
public:
    Stack();                    // Default constructor
    int IsEmpty() const;
    int IsFull() const;
    void Push(ItemType newItem);
    void Pop(ItemType& item);
    ItemType Peek() const;      // New function to return top item without removing

private:
    int top;
    ItemType items[MAX_ITEMS];
};

