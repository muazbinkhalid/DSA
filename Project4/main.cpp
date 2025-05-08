// main.cpp
// Driver to test stack-based expression utilities

#include <iostream>
#include "expression_utils.cpp"
using namespace std;

int main() {
    // a) Validity of parenthesized expression
    string expr1 = "{(a+b)*[c-d]}";
    cout << "Expression: " << expr1 << "\n";
    cout << "Is Balanced: " << (IsBalanced(expr1) ? "Yes" : "No") << "\n\n";

    // b) Infix to Postfix conversion
    string expr2 = "a+b*c-(d/e)";
    cout << "Infix: " << expr2 << "\n";
    cout << "Postfix: " << InfixToPostfix(expr2) << "\n\n";

    // c) Postfix evaluation (only for digits)
    string expr3 = "53+82-*"; // equivalent to (5+3)*(8-2) = 48
    cout << "Postfix: " << expr3 << "\n";
    cout << "Evaluated Result: " << EvaluatePostfix(expr3) << "\n";

    return 0;
}
