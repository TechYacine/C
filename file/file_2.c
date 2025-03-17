#include<stdio.h>
int main(){
    FILE *pfile = fopen("Dat.txt", "w");
    if(pfile != NULL){
        fputc('A', pfile);
        fputc('\n', pfile);
        fclose(pfile);
    }
    return 0;
}