/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>
#include <stdlib.h>

// Simple hash map structure
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define SIZE 1000

Node* hashTable[SIZE];

// Hash function
int hash(int key) {
    return abs(key) % SIZE;
}

// Insert into hash table
void insert(int key, int value) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

// Search in hash table
int search(int key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];
    while (temp) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1;
}

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int prevIndex = search(sum);

        if (prevIndex != -1) {
            int len = i - prevIndex;
            if (len > maxLen)
                maxLen = len;
        } else {
            insert(sum, i);
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLenZeroSum(arr, n));

    return 0;
}