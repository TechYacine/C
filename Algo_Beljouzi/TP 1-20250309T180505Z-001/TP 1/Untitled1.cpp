/*Exercice 1 :

Ecrire des actions paramétrées (procédure ou fonction) permettant de :

Convertir un temps en secondes en un temps en heures, minutes et secondes.

Afficher tous les nombres impairs inférieurs à N

Calculer la factorielle de N .

Calculer la somme des K premiers nombres premiers.

Vérifier si un entier positif peut s'écrire sous la forme X=2N (N>=2)

 

Solution
*/

 

#include <stdio.h>

#include <stdlib.h>

 

void   TempsConversionHrMnSec(int secondes, int *hr, int *mn, int *sec)

{

    *hr = secondes / 3600;

    secondes = secondes % 3600;

    *mn = secondes / 60;

    *sec = secondes % 60;

}

 

void  AfficheImpairInfN(int N)

{

   int i;

 

   i = 1;

   while (i < N)

   {

      printf("%5d  ", i);

      i += 2;

   }

   printf("\n");

}

 

int   Factoriel(int N)

{

   int i, fact;

 

   fact = 1;

   for(i = 1; i <= N; i++)

   {

       fact = fact * i;

   }

   return fact;

}

 

int   SommeKNbrPremier(int k)

{

    int cptPrem, SPrem, i, nPrem;

    int prem;

 

    // somme des K premiers nombres premiers initialisee a 2 (k >= 1),

    // le 1er nombre premier est 2

    SPrem = 2;

 

    cptPrem = 1; // compte combien de nombres premiers

 

    nPrem = 3;   // le 1er nombre premier a essayer est 3

    printf("Liste des %d premiers Nombres Premiers: 2", k);

 

    while (cptPrem < k)

    {

        // chercher le prochain nombre premier

        prem = 0;

 

        while (prem == 0)

        {

 

            // voir si nPrem est un nombre premier ou non

            // nPrem est un nombre premier s'il n'y a aucun diviseur de nPrem a partir de 3 jusqu'a (nPrem Div 2)

            i = 3;

            while ((i <= nPrem / 2) && (nPrem % i != 0))

                i += 2;

 

            // nPrem est un nombre premier si i > nPrem Div 2

            if (i > (nPrem / 2))

                prem = 1;

            else

                // ajouter 2 et essayer le prochain nombre impair

                nPrem += 2;

        }

        printf(", %4d", nPrem);

        // nPrem est un nombre premier, l'ajouter a SPrem et incrementer cptPrem

        SPrem = SPrem + nPrem;

        cptPrem++;

        nPrem += 2;  // prochain nombre a essayer

    }

    printf("\n");

    return SPrem;

}

 

 

int   N2PuissanceN(int N)

{

   int i = 1, puiss2;

 

   puiss2 = 2;   // on suppose N > 2

   // multiplier chaque fois puiss2 par 2 jusqu'a arriver a N ou bien a un nombre > N

 

   while (puiss2 < N)

   {

       puiss2 *= 2;

       i++;

   }

 

   if (puiss2 == N)

      return i;

   else

      return 0;

}

 

int     main()

{

    int k, S, N, i, choix;

    int secondes, hr, mn, sec;

 

    while(1)

    {

        printf("\nMenu Entrer :\n");

        printf("0: Arreter le programme ...\n");

        printf("1: pour convertir temps secondes en hr, mn et sec\n");

        printf("2: pour afficher tous le nbrs impairs < N\n");

        printf("3: pour calculer factoriel de N\n");

        printf("4: pour calculer la somme des k premiers nombres premiers\n");

        printf("5: pour verifier si nombre est puissance de 2\n");

        scanf("%d", &choix);

 

        if(choix == 0)

            break;

 

        switch(choix)

        {

            case 1:

                do {

                    printf("Donner secondes > 0\n");

                    scanf("%d", &secondes);

                  } while (secondes <= 0);

                TempsConversionHrMnSec(secondes, &hr, &mn, &sec);

                printf("%d secondes: %d hr, %d mn, %d sec", secondes, hr, mn, sec);

            break;

 

           case 2:

              do {

                    printf("Donner N >= 2\n");

                    scanf("%d", &N);

                  } while (N < 2);

              AfficheImpairInfN(N);

            break;

 

            case 3:

               do {

                    printf("Donner N >= 0\n");

                    scanf("%d", &N);

                  } while (N < 0);

               printf("%d! = %d\n", N, Factoriel(N));

 

            break;

 

            case 4:

                do {

                    printf("Donner k > 0\n");

                    scanf("%d", &k);

                   } while (k <= 0);

 

                 S = SommeKNbrPremier(k);

                 printf("Somme des %d premiers Nombres Premiers = %d ...\n", k, S);

            break;

 

            case 5:

               do {

                    printf("Donner N > 2\n");

                    scanf("%d", &N);

                  } while (N <= 2);

               if (i = N2PuissanceN(N))

                   printf("%d est 2 puissance %d ...\n", N, i);

               else

                   printf("%d N'est PAS une puissance de 2 ...\n", N);

            break;

 

         default:

            printf("Mauvais choix ...\n");

        }

    }

 

    return 0;

}
