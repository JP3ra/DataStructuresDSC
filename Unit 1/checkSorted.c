//  Write a program that prints whether the given 
// linked list is sorted (in ascending order) or not.

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

int checkSorted(struct node *head){

    int res = 1;
    if(head==NULL){
        printf("The list is empty\n");
        return 0;
    }
    else{
        struct node *temp = head;
        while(temp->next!=NULL){
            if(temp->data > temp->next->data){
                res = 0;
                return 0;
            }
            temp = temp->next;
        }
    }
    return 1;
}
int main(){
    struct node *head = NULL;
    head = insertFront(head, 50);
    head = insertFront(head, 40);
    head = insertFront(head, 30);
    head = insertFront(head, 20);
    head = insertFront(head, 60);

    int res = checkSorted(head);
    if(res==1){
        printf("The list is sorted");
    }
    else{
        printf("The lsit isnt sorted");
    }
}