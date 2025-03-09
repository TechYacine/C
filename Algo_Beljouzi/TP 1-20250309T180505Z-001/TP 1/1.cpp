/*Application 1

Consider a Tab vector (one-dimensional array) containing N integers (N<=100).
 Write a program that calculates the product of all the elements of Tab as well as the number of strictly positive values.*/

      

#include <stdio.h>

#include <stdlib.h>

 

int main()

{

    int N, i, nbrValPos, prod, Tab[100];

 

    do

    {

       printf("Give N between 1 and 100\n");

       scanf("%d", &N); 

    } while ((N < 1) || (N > 100) );

    for (i = 0; i < N; i++)

    {

        printf("Give Element %d from array \n", i + 1);

        scanf("%d", &Tab[i]);

    }

 

    prod = 1;

    nbrValPos = 0;

 

    for (i = 0; i < N; i++)

    {

        prod = prod * Tab[i];

        if (Tab[i] > 0)

            nbrValPos++;

    }

 

    printf("Product of Array elements = %d\n", prod);

    printf("Number of Positive Values in Array = %d\n", nbrValPos);

 

    system("pause");

    return 0;

}
