/*Exercice 2 :

Etant donné un entier naturel A écrire une action paramétrée MIROIR permettant de donner comme résultat le nombre miroir de A

Soit V un vecteur de N (2<=N<=100) entiers naturels distincts en utilisant l'action paramétrée MIROIR, écrire un algorithme qui, pour tout élément ayant son nombre miroir dans V déplace ces deux éléments dans un autre vecteur VM. Le déplacement consiste à supprimer de V ces deux éléments et les mettre dans VM. On demande aussi l'affichage du vecteur VM.

Solution */

 

 

#include <stdio.h>

#include <stdlib.h>

 

void    AfficherTab(int V[], int N)

{

    printf("Tableau(%d):\n", N);

    for(int i = 0; i < N; i++)

    {

        printf("%5d ", V[i]);

    }

    printf("\n");

}

 

int    miroir(int A)

{

    int mir = 0;

 

    while (A !=0)

    {

        mir = (mir * 10) + (A % 10);

        A = A / 10;

    }

 

    return mir;

}

 

void     lireTabDistincts(int V[], int N)

{

    int i, J, Trouve;

 

    for (i = 0; i < N; i++)

    {

        do{

            printf("Donner Element %d de V: ", i + 1 );

            scanf("%d", &V[i]);

            J = 0;

            Trouve = 0;

            while ((J < i) && (V[i] != V[J]))

                J++;

            if (J < i)

                Trouve = 1;

        } while(Trouve == 1);

    }

}

 

int     creerVM(int V[], int N, int VM[], int *k)

{

    int i, J, k1, k2, mir;

 

   *k = 0;  // indice utilise pour mettre element de V et son miroir dans VM

 

     // Parcourir le vecteur V et pour chaque element V[i] voir si un des elements qui suivent est un

    // miroir de V[i]

    i = 0;

    while (i < N - 1)

    {

        // On debute de (i + 1) et si on trouve un miroir de V[i] on s'arrete et

        // ensuite on supprime V[i] et son miroir de V et on les ajoute a VM

        J = i + 1;

        mir = miroir(V[i]);

 

        while (J < N)

        {

            if (V[J] == mir)

                break;

            else

                J++;

        }

 

        if (J < N)   // on a trouve le miroir de V[i] c'est V[J]

        {

            // ajouter V[i] et V[J] a VM

            VM[*k] = V[i];

            (*k)++;

            VM[*k] = V[J];

            (*k)++;

 

            // supprimer les elements V[i] et V[J] de V

            k2 = i;

            for(k1=i; k1 < N; k1++)

            {

                V[k2] = V[k1];

                // Si k2=i ou bien k2=J alors ne pas incrementer k2 de facon a ecraser ces 2 elements

                // de V

                if ((k1 != i) && (k1 != J))

                    k2++;

            }

 

            N = N - 2;  // on a supprime 2 elements de V

 

           /* Une autre maniere de supprimer les 2 elements V[i] et V[J] est de

               faire des decalages:

               for(k1=i; k1 < N; k1++)

                       V[k1] = V[k1+1];

               N--;

               for(k1=J-1; k1 < N; k1++)

                       V[k1] = V[k1+1];

               N--;

            */

        }

        else    // V[i] n'a pas de miroir

        {

            i++;    // incrementer le i pour traiter prochain element de V

        }

    }

 

    return N;

}

 

int     main()

{

    int V[100], VM[100];

    int N, k;

 

    do {

        printf("Veuillez Entrer N entier entre 2 & 100 ..\n");

        scanf("%d", &N);

    } while ((N <= 1) && (N > 100));

 

    lireTabDistincts(V, N);

 

    AfficherTab(V, N);

    N = creerVM(V, N, VM, &k);

 

    if (N == 0)

        printf("Vecteur V est Vide ...\n");

    else

    {

        printf("Vecteur V:\n");

        AfficherTab(V, N);

    }

 

    if (k == 0)

        printf("Vecteur VM est Vide ...\n");

    else

    {

        printf("Vecteur VM:\n");

        AfficherTab(VM, k);

    }

 

    return 0;

}
