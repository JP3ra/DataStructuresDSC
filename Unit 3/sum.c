// Write C program to find the sum of digits of a number using recursion.

#include<stdio.h>

int sumOfDigits(int n){
    if(n==0){
        return 0;
    }
    return (n%10)+sumOfDigits(n/10);
}

int main(){
    int res = sumOfDigits(12345);
    printf("%d", res);
}