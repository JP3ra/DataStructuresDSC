#include<stdio.h>
#include<stdlib.h>


struct node{
    int info;
    struct node *next;
};

int isEmpty(struct node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
    
}

int isFull(struct node *top){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        return 1;
    }
    else{
        return 0;
    }
}


struct node *push(struct node *top, int item){
    if(isFull(top)){
        printf("The stack is empty");
    }
    else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->info = item;
        temp->next = top;
        top = temp;
        return top;
    }
}

int pop(struct node **top){
    if(isEmpty(*top)){
        printf("The stack is underflow");
    }
    else{
        struct node *temp = *top;
        *top = (*top)->next;
        int x = temp->info;
        free(temp);
        return x;
    }
}


void display(struct node *top){
    if(top==NULL){
        printf("The stack is empty");
    }
    else{
        struct node *temp = top;
        while(temp!=NULL){
            printf("%d\n", temp->info);
            temp = temp->next;
        }
    }
}
int main(){
    struct node *top = NULL;
    top = push(top, 78);
    top = push(top, 90);
    printf("The pushed elements are\n");
    display(top);
    
    int ele = pop(&top);
    printf("The popped element is: %d\n", ele);
    
    printf("The elements after popping\n");
    display(top);
    
}