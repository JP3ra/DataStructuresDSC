#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node{
    int info;
    struct node *next;  
};

struct node *delete_front(struct node *start){
    struct node *temp;
    temp = start;
    if(start==NULL){
        printf("The list is already empty");
        return start;
    }
    else{
        start = start->next;
        printf("The deleted item is%d\n", temp->info);
        free(temp);
        return start;
    }
    
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
    
    
    
   start = delete_front(start);
   display(start);
}