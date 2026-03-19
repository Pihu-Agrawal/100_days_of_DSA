/*problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
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
        new_node->prev=NULL;

        if(head==NULL){
            head=new_node;
            temp=new_node;
        }
        else{
            temp->next=new_node;
            new_node->prev=temp;
            temp=new_node;
        }

        
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;

}




