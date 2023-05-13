#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node{
    int info;
    struct node *next;  
};

struct node *continous_addition(){
    struct node *start = NULL, *p;
    int item;
    p = (struct node*)malloc(sizeof(struct node));
    printf("Enter your element unless its -999\n");
    scanf("%d", &item);
    while(item!=-999){
        if(start == NULL){
            p->info = item;
            p->next = NULL;
            start = p;
        }
        else{
            p->info =  item;
            p->next = start;
            start = p;
        }
        scanf("%d", &item);
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
    struct node *start = continous_addition();
    
    display(start);
    
}