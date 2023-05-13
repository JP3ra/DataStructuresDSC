#include<stdio.h>

int exponent(int x, int y){
    if(y==0){
        return 1;
    }

    return x*exponent(x, y-1);
}

int main(){
    int res = exponent(2,5);
    printf("%d", res);
}