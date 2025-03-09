/*App 3

Let T1(N<=10) and T2(M<=15) be two arrays of character strings.

Write a program that displays words from T1 that do not exist in T2.
*/

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

const int max=100;

 

main()

{

    int i, j, N, M, Find ;

    char T1[10][max], T2[15][max]; 

 

    do

    {

       printf("Enter N integer between 1 and 10\n");

       scanf("%d", &N);

    } while ((N < 1) || (N > 10));

 

    do

    {

       printf("Enter M integer between 1 and 15\n");

       scanf("%d", &M);

    } while ((M < 1) || (M > 15));

 

     printf("Enter %d strings from T1\n", N);

     for (i=0; i<N; i++)

       scanf("%s", &T1[i]);

 

     printf("Enter %d strings from T2\n", M);

     for (i=0; i<M; i++)

       scanf("%s", &T2[i]);

 

     for (i=0; i < N; i++)

     {

       j = 0;

       Find = 0;

       while ( (j < M) && (Find == 0))

       {

      if (strcmp(T1[i], T2[j]) == 0)

             Find = 1;

         else

             j++;

       }

 

       if (Find == 0)

           printf("String from T1 Not Found in T2: %s\n", T1[i]);

     }       

 

     system("pause");

     return 0;

 

}
