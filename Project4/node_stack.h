// node_stack.h
// Stack implementation using linked list for characters and integers

#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
};

template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    Stack() { top = nullptr; }

    bool IsEmpty() { return top == nullptr; }

    void Push(T val) {
        Node<T>* temp = new Node<T>;
        temp->data = val;
        temp->next = top;
        top = temp;
    }

    void Pop(T& val) {
        if (IsEmpty()) {
            cout << "Stack Underflow\n";
            exit(1);
        }
        Node<T>* temp = top;
        val = top->data;
        top = top->next;
        delete temp;
    }

    T Peek() {
        if (IsEmpty()) {
            cout << "Stack is empty\n";
            exit(1);
        }
        return top->data;
    }

    ~Stack() {
        T val;
        while (!IsEmpty()) Pop(val);
    }
};

