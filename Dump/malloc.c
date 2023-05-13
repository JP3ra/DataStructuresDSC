#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int i = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    //dynamic memory allocation
    
    int *ptr = (int *)malloc(n*sizeof(int));
    
    for(i = 0;i<n;i++){
        scanf("%d", ptr+i);
    }
    
    for(int i=0;i<n;i++){
        printf("%d ", *(ptr+i));
    }
}