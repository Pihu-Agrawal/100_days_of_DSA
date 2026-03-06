/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>

int main() {
    int n, k;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read k
    scanf("%d", &k);

    k = k % n;  // Handle k greater than n

    int result[n];

    // Copy last k elements to beginning
    for(int i = 0; i < k; i++) {
        result[i] = arr[n - k + i];
    }
    // Copy remaining elements
    for(int i = k; i < n; i++) {
        result[i] = arr[i - k];
    }
    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}