/*
�nonc� :

�crire un programme en langage C pour effectuer les op�rations suivantes sur un tableau d'entiers contenant 3 �l�ments :

Afficher tous les �l�ments du tableau.
Afficher le premier et le dernier �l�ment du tableau.
Trouver et afficher le plus grand �l�ment du tableau.
Trier le tableau par ordre croissant.
Afficher le tableau apr�s le tri.
Utiliser une fonction pour trier le tableau par ordre croissant.

Le programme doit afficher les r�sultats de chaque �tape de mani�re claire et ordonn�e.
*/

#include <stdio.h>

// Fonction pour trier un tableau d'entiers par ordre croissant
void trierTableau(int tableau[], int taille) {
    int temp;
    // Double boucle pour comparer chaque paire d'�l�ments du tableau
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if (tableau[i] > tableau[j]) { // Si tableau[i] est plus grand que tableau[j]
                // �changer les valeurs pour les mettre dans l'ordre croissant
                temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }
}

int main() {
    // D�claration et initialisation d'un tableau de 3 entiers
    int nombres[] = {15, 42, 8};
    int taille = 3; // Taille du tableau

    // 1. Afficher tous les �l�ments du tableau
    printf("Les �l�ments du tableau sont : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", nombres[i]);
    }
    printf("\n");

    // 2. Afficher le premier et le dernier �l�ment du tableau
    printf("Premier �l�ment : %d\n", nombres[0]);
    printf("Dernier �l�ment : %d\n", nombres[taille - 1]);

    // 3. Trouver le plus grand nombre dans le tableau
    int max = nombres[0]; // Initialiser le maximum avec le premier �l�ment
    for (int i = 1; i < taille; i++) {
        if (nombres[i] > max) { // Comparer chaque �l�ment pour trouver le maximum
            max = nombres[i];
        }
    }
    printf("Le plus grand nombre est : %d\n", max);

    // 4. Trier le tableau par ordre croissant en utilisant la fonction 'trierTableau'
    trierTableau(nombres, taille);

    // 5. Afficher les �l�ments du tableau apr�s le tri
    printf("Tableau tri� par ordre croissant : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", nombres[i]);
    }
    printf("\n");

    return 0;
}

