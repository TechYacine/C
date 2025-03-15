#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool ans(char answer[20]){
    if(strcmp(answer, "o" ) == 0 || strcmp(answer, "O" ) == 0 ){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    char answer[20];
    int num ; 
    bool c; 
    do{
        printf("Enter an integer ");
        scanf("%d", &num);
        for(int i= 1 ; i<= 10; i ++){
            printf("%d \n", num*i);
        } 
        printf("would you continue ? , if yes enter (o) \n ");scanf(" %19[^\n]", answer);  // Capture toute la ligne pour éviter les erreurs avec des espaces
        scanf("%19s", answer); //
        c = ans(answer);
    }while(c);
    

    return 0;
}