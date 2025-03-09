/*
Énoncé :

Écrire un programme en langage C pour effectuer les opérations suivantes sur un tableau d'entiers contenant 3 éléments :

Afficher tous les éléments du tableau.
Afficher le premier et le dernier élément du tableau.
Trouver et afficher le plus grand élément du tableau.
Trier le tableau par ordre croissant.
Afficher le tableau après le tri.
Utiliser une fonction pour trier le tableau par ordre croissant.

Le programme doit afficher les résultats de chaque étape de manière claire et ordonnée.
*/

#include <stdio.h>

// Fonction pour trier un tableau d'entiers par ordre croissant
void trierTableau(int tableau[], int taille) {
    int temp;
    // Double boucle pour comparer chaque paire d'éléments du tableau
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if (tableau[i] > tableau[j]) { // Si tableau[i] est plus grand que tableau[j]
                // Échanger les valeurs pour les mettre dans l'ordre croissant
                temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }
}

int main() {
    // Déclaration et initialisation d'un tableau de 3 entiers
    int nombres[] = {15, 42, 8};
    int taille = 3; // Taille du tableau

    // 1. Afficher tous les éléments du tableau
    printf("Les éléments du tableau sont : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", nombres[i]);
    }
    printf("\n");

    // 2. Afficher le premier et le dernier élément du tableau
    printf("Premier élément : %d\n", nombres[0]);
    printf("Dernier élément : %d\n", nombres[taille - 1]);

    // 3. Trouver le plus grand nombre dans le tableau
    int max = nombres[0]; // Initialiser le maximum avec le premier élément
    for (int i = 1; i < taille; i++) {
        if (nombres[i] > max) { // Comparer chaque élément pour trouver le maximum
            max = nombres[i];
        }
    }
    printf("Le plus grand nombre est : %d\n", max);

    // 4. Trier le tableau par ordre croissant en utilisant la fonction 'trierTableau'
    trierTableau(nombres, taille);

    // 5. Afficher les éléments du tableau après le tri
    printf("Tableau trié par ordre croissant : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", nombres[i]);
    }
    printf("\n");

    return 0;
}

