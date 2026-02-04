/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays*/
#include <stdio.h>

void reverseArray(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        // Swap arr[left] and arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int n;
    //input number of element
    scanf("%d",&n);

    int arr[n];//declaring array

    //input array elements
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    reverseArray(arr, n);

    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}