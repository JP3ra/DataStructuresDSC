#include<stdio.h>

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    int n = 7;
    int res = factorial(5);
    printf("%d ", res);
}