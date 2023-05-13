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

// Count Occurence of one element 
int countOccurence(struct node *head, int item){
    int count = 0;

    struct node *temp = head;
    while(temp!=NULL){
        if(temp->data == item){
            count++;
        }
        temp = temp->next;
    }

    return count;
}


int main(){
    struct node *head = NULL;
    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertFront(head, 20);
    head = insertFront(head, 0);
    head = insertFront(head, 40);
    head = insertFront(head, 0);
    head = insertFront(head, 20);
    head = insertFront(head, 0);


    int res = countOccurence(head, 20);
    printf("%d\n", res);
    traversal(head);

}