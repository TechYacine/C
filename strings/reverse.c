#include<stdio.h>
#include<string.h>

int main() {
    char name[20] = "Tamma";
    char reversed[20] ;

    int n = strlen(name);
    int i = 0;
    while(n > 0){
        reversed[i] = name[n-1];
        i ++ ; 
        n -- ;

    }
    reversed[i] = '\0';

    printf("%s" , reversed);
    return 0;
}