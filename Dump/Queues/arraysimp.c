#include <stdio.h>
#define size 5
int queue[size];
int front =-1; 
int rear = -1;


void enqueue(int item){
    if(rear==size-1){
        printf("Queue is full");
    }
    else{
        if(front==-1&&rear==-1){
            front = 0;
            rear = 0;
            queue[rear]=item;
        }
        else{
            rear++;
            queue[rear]=item;
        }
    }
}


int dequeue(){
    if(front==-1){
        printf("Queue is empty\n");
        
    }
    else{
        int ans = queue[front];
        front++;
        return ans;
    }
}

void display(){
    for(int i=front;i<=rear;i++){
        
        printf("%d\n", queue[i]);
    }
}

int main() {
	for(int i=0;i<5;i++){
	    enqueue(i);
	}
	
	display();
	
	int res = dequeue();
	printf("The deleted element is%d\n", res);
	printf("The new queue elements are\n");
	display();
	return 0;
	
}