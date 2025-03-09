/*Let T1(N<=10) and T2(M<=15) be two arrays of character strings.
Write a program that displays words from T1 that do not exist in T2.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// D�finition de la taille maximale d'une cha�ne
const int max = 100;

int main()
{ // debut
    int i, j, N, M, Trouve; // Variables pour les boucles et indicateur de recherche
    char T1[10][max], T2[15][max]; // D�claration des deux tableaux T1 et T2

    // Saisie de N (nombre de cha�nes dans T1) entre 1 et 10
    do
    {
        printf("Entrez un entier N (entre 1 et 10) :\n");
        scanf("%d", &N);
    } while ((N < 1) || (N > 10)); 

    // Saisie de M (nombre de cha�nes dans T2) entre 1 et 15
    do
    {
        printf("Entrez un entier M (entre 1 et 15) :\n");
        scanf("%d", &M);
    } while ((M < 1) || (M > 15));

    // Saisie des cha�nes du tableau T1
    printf("Entrez %d cha�nes pour le tableau T1 :\n", N);
    for (i = 0; i < N; i++)
        scanf("%s", T1[i]); 

    // Saisie des cha�nes du tableau T2
    printf("Entrez %d cha�nes pour le tableau T2 :\n", M);
    for (i = 0; i < M; i++)
        scanf("%s", T2[i]);

    // Comparaison des cha�nes de T1 avec celles de T2
    printf("\nLes cha�nes de T1 qui n'existent pas dans T2 sont :\n");
    for (i = 0; i < N; i++) // Parcours de chaque cha�ne de T1
    {
        j = 0;         // Initialisation de l'indice de T2
        Trouve = 0;    // Indicateur de recherche, 0 signifie "non trouv�"

        // Comparaison avec les cha�nes de T2
        while ((j < M) && (Trouve == 0)) // Boucle tant que l'on n'a pas trouv� ou que T2 n'est pas parcouru
        {
            if (strcmp(T1[i], T2[j]) == 0) // Comparaison des cha�nes
                Trouve = 1; // Cha�ne trouv�e dans T2
            else
                j++; // Passer � la cha�ne suivante dans T2
        }

        // Si la cha�ne de T1 n'existe pas dans T2, l'afficher
        if (Trouve == 0)
            printf("%s\n", T1[i]);
    }


    return 0;
    //fin
}

