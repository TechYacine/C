#include<stdio.h>
#include<stdlib.h>

int main(){
    int a,b ;
    printf("Enter the numbers a and b \n");
    scanf("%d %d", &a,&b);
    int *p1 = &a; //int *p; p = &a
    int *p2 = &b;
    printf("The sum is %d\n", *p1 + *p2);
    printf("The sub is %d\n", *p1 - *p2);
    printf("The product is %d\n", *p1 * *p2);

    // Do not forget the zero division error boy :
    if(*p2 == 0){
        printf("Error: \"division error\" \n"); // Do not forget the escapers .
    }
    else{
            printf("The div is %d\n", *p1 / *p2);
    }
    return 0;
}