#include <stdio.h>
#include <string.h>
int main(){
    char name[20], temp[20] ;
    char space[] = "";
    printf("Enter a word that ends with '.' ");
    scanf("%s", name);
    int j = 1 ;

    while(1){
        strncpy(temp, name, j);
        temp[j] = '\0';
        if(strcmp(temp, name) == 0){
            break;
        }
        else{
            j += 1;
            strcpy(temp, space);
            
        }
    }
    printf("The number of char in this word is %d", j-1);
    return 0 ;
}

