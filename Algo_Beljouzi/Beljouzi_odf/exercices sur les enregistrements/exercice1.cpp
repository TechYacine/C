#include <stdio.h>
#include <stdlib.h>

/*
Soit un type TEMPS contenant le résultat obtenu par un athlète dans une course de marathon.

1- Ecrire une action paramétrée (AP) TRANSFORM qui transforme un temps T de type TEMPS en un entier S exprimant ce temps en secondes.

2- Ecrire une AP DECOMPOS qui décompose un temps S exprimé en secondes en un temps T de type TEMPS.

3- Soient N participants dans cette course (N=100). Chaque athlète est défini par un Numéro, un Nom et un Résultat de type TEMPS. Ecrire un algorithme permettant de construire un vecteur contenant les informations des différents athlètes, puis affiche la liste des athlètes (avec résultat) sélectionnés ayant obtenu un résultat inférieur ou égale à la moyenne de tous les athlètes.
*/

typedef struct {
    int hr;
    int min;
    int sec;
} Temps;

typedef struct {
    int Num;
    char nom[21];
    Temps Res;
} Athlete;

int Transformer(Temps res) {
    return ((res.hr * 3600) + (res.min * 60) + res.sec);
}

Temps Decompose(int sec) {
    Temps res;
    res.hr = sec / 3600;
    res.min = (sec % 3600) / 60;
    res.sec = (sec % 3600) % 60;
    return res;
}

void lireTabAth(Athlete T[], int N) {
    int i;
    for(i = 0; i < N; i++) {
        printf("Donner Num et Nom du %d Athlete ...\n ", i + 1);
        scanf("%d %s", &T[i].Num, T[i].nom);
        printf("Donner pour Athlete %d le Nombre d'heures...\n", i + 1);
        scanf("%d", &T[i].Res.hr);
        do {
           printf("Donner pour Athlete %d le Nombre de minutes ...\n", i + 1);
           scanf("%d", &T[i].Res.min);
        } while ((T[i].Res.min < 0) || (T[i].Res.min > 59));
        do {
           printf("Donner pour Athlete %d le Nombre de secondes ...\n", i + 1);
           scanf("%d", &T[i].Res.sec);
        } while ((T[i].Res.sec < 0) || (T[i].Res.sec > 59));
    }
}

int main() {
    Athlete TabAth[100];
    int i, N, moy;

    do {
        printf("Donner N Compris entre 1 et 100 ...\n");
        scanf("%d", &N);
    } while ((N < 1) || (N > 100));

    lireTabAth(TabAth, N);
    moy = 0;
    for(i = 0; i < N; i++) {
        moy += Transformer(TabAth[i].Res);
    }
    moy /= N;
    printf("Liste des Athletes ayant obtenu un temps plus petit que la moyenne:\n");
    for(i = 0; i < N; i++) {
        if (Transformer(TabAth[i].Res) <= moy) {
            printf("Num:%d, Nom:%s Temps(hr:%d, mn:%d, sec:%d)\n",
                   TabAth[i].Num, TabAth[i].nom, TabAth[i].Res.hr, TabAth[i].Res.min, TabAth[i].Res.sec);
        }
    }
    printf("\n********************\n");

    return 0;
}
