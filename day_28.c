/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    int n,value;

    struct node *head=NULL,*new_node=NULL,*temp=NULL;

    //input number of nodes
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("enter the value of %d node:",i+1);
        scanf("%d",&value);
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=value;
        new_node->next=NULL;

        if(head==NULL){
            head=new_node;
            temp=new_node;
        }
        else{
            temp->next=new_node;
            temp=new_node;
        }

        
    }
    temp->next=head;

    struct node *ptr=head;
    while(ptr->next!=head){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);

    return 0;

}




