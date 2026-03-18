/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Create list
struct node* create(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Merge lists
struct node* merge(struct node* a, struct node* b) {
    struct node dummy;
    struct node* temp = &dummy;

    dummy.next = NULL;

    while(a && b) {
        if(a->data < b->data) {
            temp->next = a;
            a = a->next;
        } else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }

    if(a) temp->next = a;
    else temp->next = b;

    return dummy.next;
}

// Print list
void print(struct node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct node* list1 = create(n);

    scanf("%d", &m);
    struct node* list2 = create(m);

    struct node* result = merge(list1, list2);

    print(result);

    return 0;
}