#include<stdio.h>
#define size 5
int stack[5];
int top = -1;


void push(int item){
    if(top==size-1){
        printf("Stack is Full\n");
    }
    else{
        stack[++top]=item;
    }
}

void pop(){
    if(top==-1){
        printf("Stack is Empty\n");
    }
    else{
        int item = stack[top];
        top--;
        printf("The deleted item is: %d\n", item);
    }
}


void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d ", stack[i]);
        }
    }    
}

int main(){
    for(int i=0;i<5;i++){
        push(i);
    }
    printf("The elements are\n");
    display();
    pop();
    display();
}