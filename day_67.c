/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation
int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node, int visited[], int adj[MAX][MAX], int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, visited, adj, V);
        }
    }

    // Push after visiting all neighbors
    push(node);
}

// Topological Sort function
void topoSort(int V, int adj[MAX][MAX]) {
    int visited[MAX] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, V);
        }
    }

    // Print stack (topological order)
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int V = 6;

    // Adjacency matrix representation
    int adj[MAX][MAX] = {0};

    // Example DAG edges
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topoSort(V, adj);

    return 0;
}