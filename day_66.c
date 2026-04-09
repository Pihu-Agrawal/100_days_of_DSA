/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// DFS function to detect cycle
bool dfs(int node, int V, int adj[MAX][MAX], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) { // edge exists
            if (!visited[i]) {
                if (dfs(i, V, adj, visited, recStack))
                    return true;
            }
            else if (recStack[i]) {
                return true; // cycle detected
            }
        }
    }

    recStack[node] = false; // backtrack
    return false;
}

// Function to check cycle in graph
bool hasCycle(int V, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 4;
    int adj[MAX][MAX] = {0};

    // Directed edges
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1; // creates cycle

    if (hasCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}