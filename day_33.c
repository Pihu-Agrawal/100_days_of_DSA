/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    // Input infix expression
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {

        // If operand - add to postfix
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If '(' - push
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // If ')' - pop until '('
        else if (infix[i] == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        // If operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    // Output postfix expression
    printf("%s", postfix);

    return 0;
}