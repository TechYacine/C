#include<stdio.h>


int main() {
    char phrase[50]; 

    printf("Entrez une phrase : ");  // Affichage d'un message demandant une entrée utilisateur
    
    // fgets permet de lire une ligne avec espaces jusqu'à 49 caractères + '\0' (total 50)
    fgets(phrase, sizeof(phrase), stdin);  

    printf("Vous avez saisi : %s", phrase);  // Affichage de la phrase saisie

    return 0;
}

//fgets permet de lire une ligne de texte avec espaces.
//phrase : destination où stocker l'entrée.
//sizeof(phrase) : limite la lecture à 49 caractères (dernier réservé pour \0).
//stdin : indique que l'entrée est récupérée depuis le clavi