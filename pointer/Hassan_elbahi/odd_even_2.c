#include<stdio.h>
#include<stdlib.h>

int main(){
    int a;
    int *p = &a ;
    printf("Enter the value of \"a\" \n ");
    scanf("%d", p);
    if(*p % 2 == 0){
        printf("The number is even \n");
    }
    else{
        printf("The number is odd (impaire)");
    }

    return 0;
}