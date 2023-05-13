#include<stdio.h>
#include<stdlib.h>


struct node{
    int info;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    
    if(temp==NULL){
        printf("Queue is full");
    }
    else{
        temp->info = item;
        temp->next = NULL;
        if(f==NULL){
            f = r = temp;
        }
        else{
            r->next = temp;
            r = temp;
        } 
    }
    
}

int dequeue(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(f==NULL){
        printf("Queue is Empty");
    }
    else{
        temp = f;
        f = f->next;
        int x = temp->info;
        free(temp);
        return x;
    }
}
void display(struct node *f){
    struct node *temp = f;
    while(temp!=NULL){
        printf("%d\n", temp->info);
        temp = temp->next;
    }
}
int main(){

    for(int i=0;i<5;i++){
        enqueue(i);
    }
    
    dequeue();
    
    display(f);
}