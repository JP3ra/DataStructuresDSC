//  Write a program to input an n digit number. Now, 
// break this number into its individual digits and 
// then store every single digit in a separate node 
// thereby forming a linked list. For example, if 
// you enter 12345, then there will 5 nodes in the 
// list containing nodes with values 1, 2, 3, 4, 5.

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

int main(){
    int n;
    scanf("%d", &n);
    int digit = 0;

    struct node *head = NULL;

    while(n!=0){
        digit = n%10;

        head = insertFront(head, digit);

        n = n/10;
    }

    traversal(head);
}