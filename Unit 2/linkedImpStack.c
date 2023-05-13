#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int isFull(struct node* top){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}


struct node* push(struct node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct node* n = (struct node*) malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

struct node *pop(struct node *top){
    if(isEmpty(top)){
        printf("Stack Underflow \n");
    }
    else{
        int x = top->data;
        top = top->next;
        printf("%d\n", x);
        return top;
    }
}


void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}


int main(){
    struct node *top = NULL;
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 50);

    linkedListTraversal(top);
    top = pop(top);
    top = pop(top);

    linkedListTraversal(top);
}