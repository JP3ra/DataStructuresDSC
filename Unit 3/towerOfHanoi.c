#include<stdio.h>

void towerOfHanoi(int n, char source, char dest, char interm){
    if(n==1){
        printf("The disc is moved from %c to %c", source, dest);
    }
    else{
        towerOfHanoi(n-1, source, interm, dest);
        towerOfHanoi(1, source, dest, interm);
        towerOfHanoi(n-1, interm, dest, source);
    }
}

int main(){
    towerOfHanoi(5, 'A', 'B', 'C');
}