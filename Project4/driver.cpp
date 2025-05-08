// driver.cpp
// Driver program to test Peek() and reverse a string using Stack class

#include <iostream>
#include "stack.cpp"
using namespace std;

// Function to reverse a string using Stack
void ReverseString(const string& input) {
    Stack s;
    for (char ch : input) {
        s.Push(ch);
    }

    cout << "Reversed string: ";
    while (!s.IsEmpty()) {
        char ch;
        s.Pop(ch);
        cout << ch;
    }
    cout << endl;
}

int main() {
    Stack s;
    ItemType item;

    // Test Push and Peek
    for (int i = 0; i < 5; i++) {
        s.Push(i);
        cout << "Pushed: " << i << ", Top is: " << s.Peek() << endl;
    }

    // Test Pop
    cout << "\nPopping all elements:\n";
    while (!s.IsEmpty()) {
        s.Pop(item);
        cout << item << " ";
    }
    cout << endl;

    // Test string reversal
    string str = "OpenAI";
    cout << "\nOriginal string: " << str << endl;
    ReverseString(str);

    return 0;
}
