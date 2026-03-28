/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        newNode->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        return;
    }

    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

// Display queue
void display() {
    if (front == NULL) return;

    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}


