#include<stdio.h>
int main(){
    int T[100] ;
    int po[100];
    int N ;
    int  k = 0 ;
    int *n ,*l;
    n = T;
    printf("Give the length of the array n > 0 and n <= 100 ");
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i ++){
        scanf("%d", n+i); 
    }
    n = T;
    l = po;
    for(int i = 0 ; i < N; i++){
        if(*(n + i) > 0){
            *(l + k) = *(n + i);
            k ++  ; 
        }
    }
    for(int i = 0 ; i < N ; i ++){
        printf("the %d number is :%d\n", i, *(n + i) );
    }
    for(int i = 0 ; i < k ; i ++){
        printf("the %d number is :%d\n", i, *(l + i));
    }
    return 0;
}