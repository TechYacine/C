#include<stdio.h>
#include<string.h>

int main(){
    char word[20] ,temp[20];
    printf("Type a word please ");
    scanf("%s", &word);
    int n = strlen(word); 
    int i = 0;
    while(n> 0){
        temp[i] = word[n-1];
        i ++; 
        n --;

    }
    temp[i] = '\0';
    printf("%s  \n",  temp);
    if((strcmp(word, temp) == 0)){ // in C you can not compare 2 strings instead use that function  
        printf("This word %s is a palindrom ", word);
    }
    else{
        printf("This word %s is not a palindrom ", word);
    }
    return 0;
}