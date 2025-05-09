#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Soit un enregistrement E d�fini par deux informations : 
   -- T un tableau d�entiers pouvant contenir au maximum 100 �l�ments;
   -- N le nombre d��l�ments du tableau T.
Soit une cha�ne de caract�res M, �crire une action param�tr�e qui retourne un enregistrement de type E contenant toutes les positions de la cha�ne �ab� dans la cha�ne M.

Exemple :
            M = �faabaababbaabrs'
            Resultat: { [3, 6, 8, 12] , 4 }
*/

typedef struct {
    int T[100];
    int N;
} E;

E Rechercher(char M[]) {
    int i, l;
    E res;
    res.N = 0;
    l = strlen(M) - 1; // l is gonna be used as an index so we take the length- 1 because in indexing it is the last elemnet .
    
    i = 0;
    while(i < l) { // we put i < l and not <= because the last it is impossible for the last letter to be an "ab". so we don't check it .
        if ((M[i] == 'a') && (M[i+1] == 'b')) {
            res.T[res.N] = i;
            res.N++; // it is important to take in consideration this operation because it will affect all the rest of the code.
            i += 2;
        } else {
            i++;
        }
    }
    return res;
}

void afficherE(E res) {
    printf("N = %d\n", res.N);
    for (int i=0; i<res.N; i++)
        printf("%2d ", res.T[i]);
    printf("\n\n");
}

int main() {
    char M[201]= "absubnababajbabapiufbababa";
    E res;
    int i, j, k, l;
    
    l = strlen(M);
    res = Rechercher(M);
    afficherE(res);
    while (res.N != 0) {
        for (j = res.N - 1; j >= 0; j--) {//The loop iterates from the last occurrence to the first (reverse order). This is important because removing characters from the end prevents messing up the indices of earlier occurrences.
           for (k = res.T[j]; k < l; k++)
             M[k] = M[k + 2];
           l = l - 2;   
           M[l] = '\0';
        }
        res = Rechercher(M); 
    }
    printf("Nouvelle Chaine sans 'ab' est: %s ...\n", M);
    return 0;
}
