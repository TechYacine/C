#include<stdio.h>
int main(){
    FILE *pfile = fopen("Data.txt", "w");
    if(pfile != NULL){
        fprintf(pfile, "Nom: %s, Age: %d", "Alice", 25);
        fclose(pfile);  
    }
    char name[50];
    int Age;
    pfile = fopen("Data.txt", "r");
    if(pfile != NULL){
        fscanf(pfile, "Nom: %s, Age: %d", name, &Age);
        printf("Nom: %s, age: %d\n", name, Age);
        fclose(pfile);

    }
    return 0;
}