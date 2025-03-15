#include <stdio.h>
#include <stdlib.h>

/*
Considérons les types enregistrement suivant :

Type
       TModule = Enregitrement
                  Nom : chaine[10] ;
                  Note :reel ;
                  Coef : entier ;
       Fin ;
       TEtudiant = Enregistrement
                 Matricule : entier ;
                 Nom, Prenom : chaine [20] ;
                 M1, M2, M3 : TModule ;
                 Moyenne : réel ;
       Fin;

Soit T un tableau d’au plus 100 étudiants. Ecrire un algorithme permettant de remplir le tableau T, calculer la moyenne de chaque étudiant puis recopier tous les étudiants admis dans un tableau ADMIS de type TEtudiant. Un étudiant est admis si sa moyenne est supérieure ou égale 10.
*/

typedef struct {
     char Nom[11];
     float Note;
     int Coef;
} TModule;

typedef struct {
    int matr;
    char nom[21];
    char prenom[21];
    float moy;
    TModule M1, M2, M3;
} Etudiant;

void lireTabEtud(Etudiant T[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("Donner Matricule, nom, prenom de etudiant %d ...\n", i + 1);
        scanf("%d %s %s", &T[i].matr, T[i].nom, T[i].prenom);
        printf("Donner Nom, Note et coefficient du module M1 de etudiant %d ...\n", i + 1);
        scanf("%s %f %d", T[i].M1.Nom, &T[i].M1.Note, &T[i].M1.Coef);
        printf("Donner Nom, Note et coefficient du module M2 de etudiant %d ...\n", i + 1);
        scanf("%s %f %d", T[i].M2.Nom, &T[i].M2.Note, &T[i].M2.Coef);
        printf("Donner Nom, Note et coefficient du module M3 de etudiant %d ...\n", i + 1);
        scanf("%s %f %d", T[i].M3.Nom, &T[i].M3.Note, &T[i].M3.Coef);
    }
}

void afficherTabEtudAdmis(Etudiant T[], int N) {
    int i;
    printf("Liste des Etudiants Admis:\n");
    for (i = 0; i < N; i++) {
        printf("Matricule: %d - Nom: %s - Prenom: %s - Moyenne: %f\n", T[i].matr, T[i].nom, T[i].prenom, T[i].moy);
    }
    printf("\n********************************************\n");
}

int main() {
    int i, j, N;
    Etudiant T[100], Admis[100];
    do {
        printf("Donner N Compris entre 1 et 100 ...\n");
        scanf("%d", &N);
    } while ((N < 1) || (N > 100));
    j = 0;
    lireTabEtud(T, N);
    for(i=0; i<N; i++) {
        T[i].moy = ((T[i].M1.Note * T[i].M1.Coef) + (T[i].M2.Note * T[i].M2.Coef) + (T[i].M3.Note * T[i].M3.Coef) ) /
                    (T[i].M1.Coef + T[i].M2.Coef + T[i].M3.Coef);
    }
    for(i=0; i<N; i++) {
        if(T[i].moy >= 10) {
            Admis[j] = T[i];
            j++;
        }
    }
    afficherTabEtudAdmis(Admis, j);
    return 0;
}
