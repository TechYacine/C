#include<stdio.h>
#include<stdlib.h>

typedef struct entlist
{
    int num;
    struct entlist *suiv ;
}entlist;

int main(){
    entlist *t = NULL;
    entlist *p = NULL ;

    int T[10][10];

    for(int i = 0; i<3 ; i ++){
        for(int j = 0; j<3 ; j++){
            scanf("%d", &T[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i<3; i++){
        int max = T[i][1];
        
        for(int j = 0; j<3 ; j ++){
            if(max < T[i][j]){
                max = T[i][j];
                
            }
        }
    
        p = (entlist *)malloc(sizeof(entlist));
        if(p= NULL){
            printf("Error allocation");
            return 1;
        }
        printf("%d", max);
        p->num = max ; 
        
        printf("%d", p->num);
        p->suiv = t;
        t = p;
    }
    printf("Element de la list lifo \n");
    p = t;
    while(p != NULL){
        printf("%5d -> ", p->num);
        p = p->suiv;
    }



    return 0;
}