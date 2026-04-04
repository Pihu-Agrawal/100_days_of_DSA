/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

// Enqueue
void enqueue(int value) {
    if (rear == MAX - 1) return;
    queue[++rear] = value;
}

// Dequeue
int dequeue() {
    if (front > rear) return -1;
    return queue[front++];
}

// Push to stack
void push(int value) {
    if (top == MAX - 1) return;
    stack[++top] = value;
}

// Pop from stack
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    int n, x;

    // Input
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue -> stack
    while (front <= rear) {
        push(dequeue());
    }

    // Step 2: Move stack -> queue
    front = 0;
    rear = -1;
    while (top != -1) {
        enqueue(pop());
    }

    // Output
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}