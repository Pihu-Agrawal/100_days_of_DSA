/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

// Driver code
int main() {
    int n;
    scanf("%d", &n);

    struct Queue* q = createQueue();
    char operation[10];

    for (int i = 0; i < n; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "enqueue") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(q, x);
        } else if (strcmp(operation, "dequeue") == 0) {
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}