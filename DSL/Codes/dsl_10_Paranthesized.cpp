// In any language program mostly syntax error occurs due to unbalancing 
// delimiter such as (),{},[]. Write C++ program using stack to check whether 
// given expression is well parenthesized or not. 

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// Function to check if the given expression is well-parenthesized
bool isWellParenthesized(const string& expression) {
    stack<char> s;
    // Map to hold matching pairs of brackets
    unordered_map<char, char> brackets = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : expression) {
        // If it's an opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If it's a closing bracket, check for matching opening bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || s.top() != brackets[ch]) {
                return false; // Unmatched or incorrectly ordered
            }
            s.pop(); // Pop the matching opening bracket
        }
    }

    // If the stack is empty, all brackets are matched
    return s.empty();
}

int main() {
    string expression;

    // Input expression
    cout << "Enter an expression: ";
    getline(cin, expression);

    // Check if the expression is well-parenthesized
    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is not well-parenthesized." << endl;
    }

    return 0;
}
