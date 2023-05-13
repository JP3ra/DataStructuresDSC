//  Write a program to merge two linked lists.

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

struct node *mergeTwo(struct node *head1, struct node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1==NULL && head2 == NULL){
        printf("Empty LL");
        return head2;
    }


    struct node *temp = head2;
    while(temp!=NULL){

        head1 = insertFront(head1, temp->data);
        temp = temp->next;
    }

    return head1;
}

int main(){
    // First linked list 
    struct node *head1 = NULL;
    head1 = insertFront(head1, 10);
    head1 = insertFront(head1, 20);
    head1 = insertFront(head1, 30);
    head1 = insertFront(head1, 40);

    // Second linked list 
    struct node *head2 = NULL;
    head2 = insertFront(head2, 50);
    head2 = insertFront(head2, 60);

    
    head1 = mergeTwo(head1, head2);
    traversal(head1);


    

}