/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void traverse(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

struct node* deleteKey(struct node *head,int key){
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=key){
        p=p->next;
        q=q->next;

    }
    p->next=q->next;
    free(q);
    return head;

}
int main(){
    int n,value,key;

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
    printf("enter key to delete:");
    scanf("%d",&key);
    head=deleteKey(head,key);
    traverse(head);


    return 0;

}




