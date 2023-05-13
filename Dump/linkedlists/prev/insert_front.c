#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node{
    int info;
    struct node *next;  
};

struct node *insert_front(int item, struct node *start){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    
    p->info = item;
    if(start==NULL){
        p->next = NULL;
        start = p;
    }
    else{
        p->next =  start;
        start = p;
    }
    
    return start;
}

void display(struct node *start){
    struct node *temp;
    if(start==NULL){
        printf("List is empty");
    }
    temp =  start;
    while(temp!=NULL){
        printf("%d\n", temp->info);
        temp =  temp->next;
    }
}


int main(){
    struct node *p, *q, *start = NULL;
    p = (struct node*)malloc(sizeof(struct node));
    p->info = 10;
    p->next = NULL;
    
    q = (struct node*)malloc(sizeof(struct node));
    q->info = 20;
    q->next = NULL;
    
    p->next = q;
    start = p;
    
    start = insert_front(30, start);
    display(start);
}