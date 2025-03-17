#include<stdio.h>

int main(){
    FILE *pfile = fopen("DA.txt", "w");
    if(pfile != NULL){
        fputs("Bonjour tout le monde \n", pfile);
        fclose(pfile);

    }

    return 0;
}