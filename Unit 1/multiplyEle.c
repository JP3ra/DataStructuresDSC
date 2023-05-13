// . Write a program to print the total number of 
// occurrences of a given item in the linked list

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

struct node *multiplyEle(struct node *head){
    if(head==NULL){
        printf("Empty list");
        return head;
    }
    else{
        struct node *temp = head;
        while(temp!=NULL){
            temp->data = temp->data*10;
            temp = temp->next;
        }

        return head;
    }
}


int main(){
    struct node *head = NULL;
    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertFront(head, 20);
    head = insertFront(head, 40);
    head = insertFront(head, 20);

    traversal(head);

    head = multiplyEle(head);
    traversal(head);

}