#include<stdio.h>
#include<conio.h>
#include<string.h>

int top = -1, pos = 0; len;

void push(char symbol){
    top = top+1;
    stack[top] = symbol;
}

char pop(){
    symbol = stack[top];
    top = top-1;
    return symbol;
}

int preced(char symbol){
    int p;

    switch(symbol){
        case "^": p = 3; break;
        case "*":
        case "/": p = 2; break;
        case "+":
        case '-': p = 1; break;
        case ')':
        case '(': p = 0; break;
    }

    return p;
}

char iToP(char infix[], char postfix[]){
    len = strlen(infix);
    char temp, sym;

    for(int i=0; i<len; i++){

        char sym = infix[i];

        switch(sym){
            case '(': push(sym);
            case ')': temp = pop();
                      while(temp!='('){
                        postfix[pos] = temp;
                        pos++;
                        temp = pop();
                      }
            case '+':
            case '-':
            case '/':
            case '*':
            case '^': while(preced(stack[top])>=preced(sym)){
                        temp = pop();
                        postfix[pop] = temp;
                        pop++;
                    }
                    push(sym);
                    break;

            default: postfix[pos++] = sym; 
        }
    }
}