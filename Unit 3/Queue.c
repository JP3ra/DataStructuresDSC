#include<stdio.h>
#define size 10
int queue[10];
int rear = -1;
int front = -1;

void enqueue(int data){
    if(rear==size-1){
        printf("Queue is full");
        return ;
    }

    else if(front == -1 && rear ==-1){
        front = 0;
        rear = 0;
        queue[rear] = data;
    }
    else{
        rear++;
        queue[rear] = data;
    }

}

void display(){
    int i = 0;
    for(i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
}

int dequeue(){
    if(front==-1 || front>rear){
        printf("Queue underflow");
        return -1;
    }
    else{
        int val = queue[front];
        front++;
        if(front>rear){
            front = rear = -1;

        }
        return val;
    }

}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    display();

    int res = dequeue();
    printf("%d\n", res);

    display();


}