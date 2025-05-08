// expression_utils.cpp
// Functions to check parentheses validity, convert infix to postfix, and evaluate postfix

#include <iostream>
#include <cctype>
#include <string>
#include "node_stack.h"
using namespace std;

bool IsBalanced(const string& expr) {
    Stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[')
            s.Push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.IsEmpty()) return false;
            char top = s.Peek();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '['))
                s.Pop(top);
            else
                return false;
        }
    }
    return s.IsEmpty();
}

int Precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string InfixToPostfix(const string& infix) {
    Stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch))
            postfix += ch;
        else if (ch == '(')
            s.Push(ch);
        else if (ch == ')') {
            char temp;
            while (!s.IsEmpty() && s.Peek() != '(') {
                s.Pop(temp);
                postfix += temp;
            }
            s.Pop(temp); // remove '('
        }
        else {
            while (!s.IsEmpty() && Precedence(s.Peek()) >= Precedence(ch)) {
                char temp;
                s.Pop(temp);
                postfix += temp;
            }
            s.Push(ch);
        }
    }

    char temp;
    while (!s.IsEmpty()) {
        s.Pop(temp);
        postfix += temp;
    }

    return postfix;
}

int EvaluatePostfix(const string& postfix) {
    Stack<int> s;
    for (char ch : postfix) {
        if (isdigit(ch))
            s.Push(ch - '0');
        else {
            int op2, op1;
            s.Pop(op2);
            s.Pop(op1);
            switch (ch) {
            case '+': s.Push(op1 + op2); break;
            case '-': s.Push(op1 - op2); break;
            case '*': s.Push(op1 * op2); break;
            case '/': s.Push(op1 / op2); break;
            }
        }
    }
    return s.Peek();
}
