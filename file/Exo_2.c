#include<stdio.h>
typedef struct 
{
    int mat ;
    char name[20], full_name[20] ;
    float moy ;

} Etudiant;

int main(){
    Etudiant etd ; 
    int n ;
    FILE *T = fopen("etudiant.txt", "w");
    if(T != NULL){
        printf("Enter the number of students ");
        scanf("%d", &n);
        for(int i = 0 ; i < n ; i ++){
            printf("Enter the mat, name, full_name, moy \n");
            scanf("%d %s %s %f", &etd.mat, etd.name, etd.full_name, &etd.moy);
            fprintf(T , "%d %s %s %f\n", etd.mat, etd.name, etd.full_name, etd.moy);
        

        }
    fclose(T);

    }
    FILE *ad = fopen("admis.txt", "w");
    T = fopen("etudiant.txt", "r");
    if(T != NULL || ad != NULL){
        while(fscanf(T ,"%d %s %s %f", &etd.mat, etd.name, etd.full_name, &etd.moy ) != EOF){
            if(etd.moy > 10){
                fprintf(ad , "matricule = %d , name and f_name = %s %s , moy %f", etd.mat, etd.name, etd.full_name, etd.moy);
            }
        }
        fclose(ad);
        fclose(T);
    }
    return 0;
}