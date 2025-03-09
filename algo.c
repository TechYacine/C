#include<stdio.h>
int main(){
    int v; 
    printf("Choose a value");
    scanf("%d", &v);
    for(int i = 3 ; i != v; i++){
        printf("hi \n");
    }
    return 0;
}