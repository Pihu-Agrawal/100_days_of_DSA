/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    // BFS
    int front = 0, rear = 0;
    queue[rear++] = 1;
    visited[1] = 1;
    int count = 1;

    while (front < rear) {
        int node = queue[front++];

        for (int i = 1; i <= n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
                count++;
            }
        }
    }

    // Check connectivity
    if (count == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}