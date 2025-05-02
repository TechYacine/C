#include<stdio.h>
#include<string.h>
typedef struct{
    int taille[100];
    int N;

}E;

E search(char word[]){
    E e;
    int len = strlen(word);
    int i = 0;
    e.N = 0 ;
    while(i< len){
        if((word[i] == 'a') && (word[i+1] == 'b')){
            e.taille[e.N] = i;
            e.N += 1;
            i += 2;
        }
        else{
            i += 1;
        }
    }

    return e;
}

void affiche(E e){
    printf("the number of ab in this char is %d \n", e.N);
    printf("the indexes of the repetition are : \n");
    for(int i = 0; i < e.N; i++){
        printf("%d ", e.taille[i]);
    }
}

int main(){
    char word[] = "absubnababajbabapiufbababa";
    E r;
    char x[100];
    r = search(word);
    affiche(r);
    printf("----------------- \n");
    int len = strlen(word);
    int k = 0;
    int l = 0;
    for(int i = 0; i<len; i++){
        if(i != r.taille[k]){
            x[l] = word[i];
            l += 1;
             
        }
        else{
            i += 1;
            k += 1;
        }
    }
    x[l] = '\0';
    printf("the word without 'ab' is : %s\n", x);

    return 0;
}