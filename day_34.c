/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push operation
struct Node* push(struct Node* top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

// Pop operation
struct Node* pop(struct Node* top, int* value) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = top;
    *value = temp->data;
    top = top->next;
    free(temp);
    return top;
}

// Function to evaluate postfix expression
int evaluatePostfix(char* expr) {
    struct Node* stack = NULL;
    int i = 0;

    while (expr[i] != '\0') {
        // Skip spaces
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        // If operand
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            stack = push(stack, num);
        }
        else {
            int val1, val2;
            stack = pop(stack, &val2);
            stack = pop(stack, &val1);

            int result;
            switch (expr[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            stack = push(stack, result);
            i++;
        }
    }

    int finalResult;
    stack = pop(stack, &finalResult);
    return finalResult;
}

// Main function
int main() {
    char expr[100];

    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);

    int result = evaluatePostfix(expr);
    printf("Result = %d\n", result);

    return 0;
}