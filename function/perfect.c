#include<stdio.h>
#include<stdbool.h>
bool perfect(int i){
    int sum  = 0;
    for(int j = 1 ; j<= (i/2) ; j++){
        if(i%j == 0){
            sum += j;
        }
    }
    if(sum == i){return true;}
    else{return false;}

    
    

}
int main(){
    printf("The perfect numbers are : \n");
    for(int i= 1  ; i<= 200; i ++){
        
        if(perfect(i)){
            printf("%d \n", i);
        }
        
    }
    return 0;
}