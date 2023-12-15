#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform the operation based on the operator
int performOperation(char op, int operand1, int operand2) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;  // Invalid operator
    }
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;  // Operand, append to postfix
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Pop '('
        } else if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(' && (c != '+' && c != '-') && (operators.top() == '*' || operators.top() == '/')) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> operands;

    for (char c : postfix) {
        if (isalnum(c)) {
            operands.push(c - '0');  // Convert char to int and push to stack
        } else if (isOperator(c)) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = performOperation(c, operand1, operand2);
            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    string infixExpression;
    
    // Input infix expression
    cout << "Enter infix expression: ";
    cin >> infixExpression;

    // Convert infix to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    // Evaluate postfix expression
    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
