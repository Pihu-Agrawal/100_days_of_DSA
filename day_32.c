/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        // Stack overflow (not needed here but good practice)
        return;
    }
    stack[++top] = value;
}

// Pop function
void pop() {
    if (top == -1) {
        // Stack underflow
        return;
    }
    top--;
}

//dispaly
void display(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }

    }
}

int main() {
    int n, m, x;

    // Input number of elements
    printf("number of elements to push:\n");
    scanf("%d", &n);

    // Push elements
    printf("enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    // Input number of pops
    printf("number of elements to pop:\n");
    scanf("%d", &m);

    // Perform pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}