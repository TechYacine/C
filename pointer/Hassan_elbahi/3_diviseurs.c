#include<stdio.h>
#include<stdlib.h>

int main(){
    int a;
    int *p = &a ;
    printf("Enter the value of \"a\" " );
     do{
        scanf("%d", p);
    }while( *p <= 0);
    int k = 0;
    printf("Les diviseurs sont \n");
    for(int i = *p; i>0; i--){
        if(*p % i == 0){
            k += 1;
            printf("the %d div is %d \n .", k , i);
        }
    }
    return 0;
}