#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int info;
    struct node *next;
};

void checksorted(struct node *start){
    struct node *temp, *prev_temp;
    if(start==NULL){
        printf("List is empty");
        return ;
    }
    if(start->next==NULL){
        printf("List is already sorted");
        return ;
    }
    int res = 1;
    temp = start;
    prev_temp =  temp;
    while(temp->next!=NULL){
        prev_temp = temp;
        temp = temp->next;
        if(temp->info < prev_temp->info){
            res = 0;
            break;
            
        }
    }
    
    if(res){
        printf("List is sorted");
    }else{
        printf("List is not sorted");
    }
}


struct node *insert_rear(int item, struct node *start){
    struct node *p, *temp;
    p = (struct node*)malloc(sizeof(struct node));
    
    p->info = item;
    p->next = NULL;
    if(start == NULL){
        start = p;
    }
    else{
        temp =  start;
        while(temp->next!=NULL){
            temp =  temp->next;
        }
        
        temp->next = p;
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
    
    start = insert_rear(30, start);
    start = insert_rear(40, start);
    start = insert_rear(35, start);
    display(start);
    
    checksorted(start);
    
}