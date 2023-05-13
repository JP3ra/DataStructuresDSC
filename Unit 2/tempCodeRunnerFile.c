#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int size = 5;

int stack[5];
int top = -1;

void push(int item){
    if(top==size-1){
        printf("Stack overflow");
    }
    else{
        top = top +1;
        stack[top] = item;
    }
}

int pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    else{
        int item = stack[top];
        printf("The popped item is: %d", item);
        top = top-1;
    }
}
int operation(op1, op2, char symbol){
    switch(symbol){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '*': return pow(op1, op2);
    }
}

int isDigit(char symbol){
    if(symbol>='0' && symbol<='9'){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    char symbol;
    char postfix[30];
    int op1, op2, res;
    scanf("%s", postfix);

    for(int i = 0; i<strlen(postfix); i++){
        symbol = postfix[i];

        if(isDigit(symbol)){
            push(symbol-'0');
        }
        else{
            op1 = pop();
            op2 = pop();
            int result = operation(op1, op2, symbol);
            push(res);

        }
    }

    printf("%d", pop());
}