/*Exercice 

1- Ecrire une AP Carre vérifiant si un nombre entier naturel est un carré parfait, en utilisant seulement les opérateurs de base, et renvoie sa racine dans le cas favorable. ( Indication : X est un carré parfait s’il existe un entier i tel que X = i * i.) 

2- Ecrire un algorithme qui, parmi N entiers naturels, calcul la somme et le produit des racines carrées des entiers carrés parfaits. Ensuite il vérifie si la somme et le produit sont des carrés parfaits. 
*/
 

#include <stdio.h>

#include <stdlib.h>

 

void    carreParfait(int x, int *rac, int *carParf)

{

    int i;

 

    i = 0;

    while ((i * i) < x)

    {

        i++;

    }

 

    if ((i * i) == x)

    {

        *rac = i;

        *carParf = 1;

    }

    else

    {

        *carParf = 0;

    }

}

 

int      main()

{

    int T[100];

    int i, Prod, Som, rac, carParf, N;

 

   do

   {

      printf("Donner N compris entre 1 et 100\n");

      scanf("%d", &N);

   } while  ((N<=1) || (N>=100));

 

   for(i = 0; i < N; i++)

   {

       printf("Donner %d eme valeur du vecteur\n", i + 1);

       scanf("%d", &T[i]);

   }

 

   Som = 0;

   Prod = 1;

   for(i = 0; i < N; i++)

   {

       carreParfait(T[i], &rac, &carParf);

       if (carParf == 1)

       {

          Som = Som + rac;

          Prod = Prod * rac;

       }

   }

   printf("Somme des Racines des carres parfaits = %d\n ", Som);

   printf("Produit des Racines des carres parfaits = %d\n", Prod);

 

   carreParfait(Som, &rac, &carParf);

   if (carParf == 1)

       printf("Somme des racines des carres parfaits N'est PAS un carre parfait ...\n");

   else

       printf("Somme des racines des carres parfaits est un carre parfait\n");

 

 

    carreParfait(Prod, &rac, &carParf);

    if (carParf == 1)

       printf("Prod des racines des carres parfaits N'est PAS un carre parfait ...\n");

   else

       printf("Prod des racines des carres parfaits est un carre parfait\n");

 

   return 0;

}
