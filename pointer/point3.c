#include<stdio.h> 
#include<stdlib.h>
#include<stdlib.h>

typedef struct entlist{
    int info ;
    struct entlist *suivant ; // pointeur vers la cellule suivante .
}entlist;
int main(){
// Remplire la list chaineé :
    int N , i ;
    entlist *T ,*p = NULL, *q ;
    // Give the number : 
    do {
        printf("Enter the number \n");
        scanf("%d", &N);
    }while(N<= 0);
    // creation de la list en mode FiFO : 
    for(int i = 0 ; i<N ; i ++){
        // Alloction dynamique : 
        p = (entlist *)malloc(sizeof(entlist));
        if(p == NULL){
            printf("Error allocation");
            return 1 ;
        }
        // Lire la valeur  
        printf("Donner la valeur %d : ", i+1);
        scanf("%d", &p->info);
        p->suivant = NULL ; 
        if(i == 0){
            T = p;
            q = p ;
        }
        else{
            q->suivant = p ;
            q = p ;
        }
    }
   

// affichage :
    printf("Element de la list lifo \n");
    p = T;
    while(p != NULL){
        printf("%5d -> ", p->info);
        p = p->suivant;
    }


// liberer : 
    p = T ;
    while(p != NULL){
        entlist *Temp = p;
        p = p->suivant ;
        free(Temp);
    }
    /*
    int *p = malloc(sizeof(int)); //  size in octc 
    int *p = malloc (4*sizeof(int)) ;;
    free(p) ; // libere de l'espace . 
    int *p = calloc(4, sizeof(int)); // elle pointe sur un espace memoire qui contient un 0 .
    int *p = realloc(p, 5*sizeof(int)); // tu reserve  de facon indexé tq n sera la nouvelle taille .
    // Important : si par ex realloc ne peux pas ajouter une autre case car elle reserevé , donc tout les cases de pointeur seront deplacé vers un autre bloc  
   */
    return 0 ; 
}