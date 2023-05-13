//  Write a program that prints minimum and maximum values in a linked list that stores integer 
// values


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

int finMax(struct node *head){
    if(head==NULL){
        printf("List is empty");
        return -1;
    }
    else{
        int max = head->data;
        struct node *temp = head;
        while(temp!=NULL){
            if(temp->data > max){
                max = temp->data;
            }
            temp = temp->next;
        }
        return max;

        
    }
}

int main(){
    struct node *head = NULL;
    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertFront(head, 30);
    head = insertFront(head, 40);
    head = insertFront(head, 50);
    head = insertFront(head, 60);
    
    int max = finMax(head);
    printf("%d", max);
}