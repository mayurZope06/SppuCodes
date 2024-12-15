// Implement C++ program for expression conversion as infix to postfix and its 
// evaluation using stack based on given conditions: 
// 1. Operands and operator, both must be single character. 
// 2. Input Postfix expression must be in a desired format. 
// 3. Only '+', '-', '*' and '/ ' operators are expected.
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

// Function to return the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to convert infix expression to postfix
string infixToPostfix(const string &infix) {
    stack<char> operators;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {  // If the character is an operand
            postfix += c;
        } else if (isOperator(c)) {  // If the character is an operator
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const string &postfix) {
    stack<int> operands;

    for (char c : postfix) {
        if (isdigit(c)) {  // If the character is an operand
            operands.push(c - '0');  // Convert char to int
        } else if (isOperator(c)) {  // If the character is an operator
            int right = operands.top(); operands.pop();
            int left = operands.top(); operands.pop();
            switch (c) {
                case '+': operands.push(left + right); break;
                case '-': operands.push(left - right); break;
                case '*': operands.push(left * right); break;
                case '/': 
                    if (right != 0) {
                        operands.push(left / right);
                    } else {
                        cerr << "Error: Division by zero." << endl;
                        return 0;
                    }
                    break;
            }
        }
    }

    return operands.top();  // The result is the last remaining item on the stack
}

int main() {
    string infix;

    cout << "Enter an infix expression (single-character operands and operators only): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation of Postfix expression: " << result << endl;

    return 0;
}

// OR

#include <iostream>
using namespace std;
class stack{
public:
    char stack_array[50];
    int top;
    stack(){
        top = -1;
    }
    void push(char symbol){
        if (full())
            cout << "\nStack overflow:\n";
        else{
            top = top + 1;
            stack_array[top] = symbol;
        }
    }
    char pop(){
        if (empty())
            return ('#'); // Return value '#' indicates stack is empty
        else
            return (stack_array[top--]);
    }
    int empty(){
        if (top == -1)
            return (1);
        else
            return (0);
    }
    int full(){
        if (top == 49)
            return (1);
        else
            return (0);
    }

private:
    char infix[50];
    char postfix[50];

public:
    void read(){
        cout << "\nEnter an infix expression:";
        cin >> infix;
    }
    int white_space(char symbol){
        if (symbol == ' ' || symbol == '\t' || symbol == '\0')
            return 1;
        else
            return 0;
    }
    void ConvertToPostfix(){
        int prev, p;
        char entry;
        p = 0;
        for (int i = 0; infix[i] != '\0'; i++){
            if (!white_space(infix[i])){
                switch (infix[i]){
                case '(':
                    push(infix[i]);
                    break;
                case ')':
                    while ((entry = pop()) != '(')
                        postfix[p++] = entry;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                    if (!empty()){
                        prev = prior(infix[i]);
                        entry = pop();
                        while (prev <= prior(entry)){
                            postfix[p++] = entry;
                            if (!empty())
                                entry = pop();
                            else
                                break;
                        }
                        if (prev > prior(entry))
                            push(entry);
                    }
                    push(infix[i]);
                    break;
                default:
                    postfix[p++] = infix[i];
                    break;
                }
            }
        }
        while (!empty()) // while stack is not empty
            postfix[p++] = pop();
        postfix[p] = '\0';
        cout << "\nThe postfix expression is: " << postfix << endl;
    }
    int prior(char symbol){
        switch (symbol){
        case '/':
            return (4); // Precedence of / is 4
        case '*':
            return (3); // Precedence of * is 3
        case '+':
            return (2); // Precedence of + is 2
        case '-':
            return (1); // Precedence of - is 1
        case '(':
            return (0); // Precedence of ( is 0
        default:
            return (-1);
        }
    }
};
int main()
{
    char choice = 'y';
    stack expr;
    while (choice == 'y')
    {
        expr.read();
        expr.ConvertToPostfix();
        cout << "\n\nDo you want to continue ? (y/n): ";
        cin >> choice;
    }
    return 0;
}
