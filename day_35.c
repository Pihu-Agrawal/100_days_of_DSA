/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/
#include<stdio.h>
#define MAX 100
int front=-1;
int rear=-1;
int queue[MAX];

void enqueue(){
    int value;
    scanf("%d",&value);
    if(rear==MAX-1){
        printf("stack is full\n");
        return;
    }
    if(front==-1){
        front++;

    }
        rear++;
        queue[rear]=value;
}

void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}
int main(){
    int n;
    printf("enter number of elements:\n");
    scanf("%d",&n);
    printf("enter the elements:\n");
    for(int i=0;i<n;i++){
        enqueue();
    }

    display();

    return 0;
}