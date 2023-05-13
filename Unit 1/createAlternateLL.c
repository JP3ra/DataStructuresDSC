//  Write a program to create a linked list from an 
// already given list. The new linked list must contain 
// every alternate element of the existing linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

void traversal(struct node *head){
    if(head==NULL){
        printf("The linked list is empty \n");
    }
    else{
        struct node *temp = head;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");


    }
}

struct node *insertFront(struct node *head, int info){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = info;
    p->next = NULL;


    if(head==NULL){
        head = p;
    }
    else{
        p->next = head;
        head = p;
        
    }

    return head;

}

struct node *createAlternateLL(struct node *head){
    if(head==NULL){
        printf("The linked list is empty\n");
    }

    struct node *head3 = NULL;

    struct node *temp = head;
    while(temp!=NULL){
        head3 = insertFront(head3, temp->data);

        temp = temp->next->next; 
    }
    return head3;
}

int main(){
    struct node *head1 = NULL;
    head1 = insertFront(head1, 10);
    head1 = insertFront(head1, 20);
    head1 = insertFront(head1, 30);
    head1 = insertFront(head1, 40);
    head1 = insertFront(head1, 50);
    head1 = insertFront(head1, 60);
    traversal(head1);

    struct node *head3 = NULL;
    head3 = createAlternateLL(head1);
    traversal(head3);

}