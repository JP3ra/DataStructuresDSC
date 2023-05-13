#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node *front = NULL;
struct node *rear = NULL;


struct node{
    int info;
    struct node *next;
};

void queueTraversal(struct node *front){
    struct node *temp = front;
    printf("The elements in the list ");

    while(temp!=NULL){
        printf("%d ", temp->info);
        temp = temp->next;
    }
}


void enqueue(int data){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue is empty");
    }
    else{
        n->info = data;
        n->next = NULL;

        if(front==NULL){
            front = rear = n;
        }
        else{
            rear->next = n;
            rear = n;
        }
    }
}

int isEmpty(){
    if(front==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int dequeue(){
    if(isEmpty()){
        printf("Empty");
    }
    else{
        struct node *temp = front;
        front = front->next;
        int x = temp->info;
        free(temp);
        return x;
    }
}

int main(){
    

    enqueue(30);
    enqueue(60);
    enqueue(50);
    enqueue(80);

    queueTraversal(front);

    int popped = dequeue();
    printf("The removed element is: %d\n", popped);

    queueTraversal(front);
}