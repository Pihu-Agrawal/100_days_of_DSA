/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph structure
struct Graph {
    struct Node* head[MAX];
};

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = graph->head[u];
    graph->head[u] = node;

    node = createNode(u, w);
    node->next = graph->head[v];
    graph->head[v] = node;
}

// Min Heap structure
struct MinHeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    struct MinHeapNode heap[MAX];
};

// Swap heap nodes
void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(struct MinHeap* h, int idx) {
    while (idx && h->heap[(idx - 1) / 2].dist > h->heap[idx].dist) {
        swap(&h->heap[idx], &h->heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

// Heapify down
void heapifyDown(struct MinHeap* h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&h->heap[idx], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

// Insert into heap
void push(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;
    heapifyUp(h, i);
}

// Extract min
struct MinHeapNode pop(struct MinHeap* h) {
    struct MinHeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapifyDown(h, 0);
    return root;
}

// Dijkstra function
void dijkstra(struct Graph* graph, int V, int src) {
    int dist[MAX];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        struct MinHeapNode minNode = pop(&heap);
        int u = minNode.vertex;

        struct Node* temp = graph->head[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Main function
int main() {
    int V = 5;
    struct Graph graph;

    for (int i = 0; i < V; i++)
        graph.head[i] = NULL;

    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 4, 5);
    addEdge(&graph, 1, 2, 1);
    addEdge(&graph, 1, 4, 2);
    addEdge(&graph, 2, 3, 4);
    addEdge(&graph, 3, 0, 7);
    addEdge(&graph, 4, 2, 9);
    addEdge(&graph, 4, 3, 2);

    dijkstra(&graph, V, 0);

    return 0;
}