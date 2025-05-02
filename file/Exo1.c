#include<stdio.h>
int main(){
    int n , N ; 
    FILE *pfile = fopen("Numbers.txt", "w");
    if(pfile != NULL){
        printf("Enter how much number \n ");
        scanf("%d", &N);
        for(int i = 0 ; i < N ; i++){
            scanf("%d", &n);
            fprintf(pfile, "%d \n", n);
        }
        
        fclose(pfile);  
    }
    pfile = fopen("Numbers.txt", "r");
    float r ;
    int nb , somme = 0 , count = 0 ;
    if(pfile != NULL){
        while(fscanf(pfile , "%d", &nb) != EOF){
            printf("%d ", nb);
            somme += nb ;
            count ++ ; 
        }
            
        fclose(pfile);
    }
    r = somme/count;
    if(count > 0 ){
        printf(" somme : %d \n ", somme);
        printf("avg  : %.2f ", r );
    }

    return 0;
}