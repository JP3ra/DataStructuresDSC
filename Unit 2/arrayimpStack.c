#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size];
int top = -1;

void push(int item){
    if(top==size-1                                          ){
        printf("Stack overflow");
    }
    else{
        top = top +1;
        stack[top] = item;
    }
}

void pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    else{
        int item = stack[top];
        printf("The popped item is: %d", item);
        top = top-1;
    }
}

void display(){
    if(top==-1){
        printf("The stack is empty");
    }
    else{
        for(int i = top; i>=0; i--){
            printf("%d ", stack[i]);
        } 
    }
}

int main(){

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    display();

    pop();
    printf("\n");
    display();


}