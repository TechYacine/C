#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Soit un enregistrement E défini par deux informations : 
   -- T un tableau d’entiers pouvant contenir au maximum 100 éléments;
   -- N le nombre d’éléments du tableau T.
Soit une chaîne de caractères M, écrire une action paramétrée qui retourne un enregistrement de type E contenant toutes les positions de la chaîne ‘ab‘ dans la chaîne M.

Exemple :
            M = ‘faabaababbaabrs'
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
    l = strlen(M) - 1;
    i = 0;
    while(i < l) {
        if ((M[i] == 'a') && (M[i+1] == 'b')) {
            res.T[res.N] = i;
            res.N++;
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
    char M[201];
    E res;
    int i, j, k, l;
    printf("Donner une chaine de caracteres ...\n");
    scanf("%s", M);
    l = strlen(M);
    res = Rechercher(M);
    afficherE(res);
    while (res.N != 0) {
        for (j = res.N - 1; j >= 0; j--) {
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
