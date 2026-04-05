/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1)
        return -1;
    int x = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return x;
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// BFS function
void BFS(int n, int adj[MAX][MAX], int s) {
    int visited[MAX] = {0};

    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                enqueue(v);
                visited[v] = 1;
            }
        }
    }
}

int main() {
    int n, s;
    int adj[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(n, adj, s);

    return 0;
}