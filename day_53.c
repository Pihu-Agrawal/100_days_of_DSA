/**/
#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create node
Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for BFS (store node + HD)
typedef struct {
    Node* node;
    int hd;
} QNode;

typedef struct {
    QNode arr[1000];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

void push(Queue* q, Node* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

QNode pop(Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Build Tree
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Queue q;
    initQueue(&q);

    Node* root = createNode(arr[0]);
    push(&q, root, 0);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        Node* curr = pop(&q).node;

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            push(&q, curr->left, 0);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            push(&q, curr->right, 0);
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(Node* root) {
    if (!root) return;

    Queue q;
    initQueue(&q);

    // Store results (HD range: -1000 to +1000)
    int map[2001][100];
    int count[2001] = {0};

    int offset = 1000;

    push(&q, root, 0);

    while (!isEmpty(&q)) {
        QNode temp = pop(&q);
        Node* curr = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = curr->data;

        if (curr->left)
            push(&q, curr->left, hd - 1);

        if (curr->right)
            push(&q, curr->right, hd + 1);
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < 2001; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}