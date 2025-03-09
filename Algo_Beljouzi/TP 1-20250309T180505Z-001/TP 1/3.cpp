/*App 3

Given a matrix A(N, M) of integers (N<=20 and M<=30), write a program which:

    - calculates and saves the sum of each column,

   - determines the jmin position of the minimum sum and the jmax position of the maximum sum.

   - permutes the two columns of indices jmin and jmax of matrix A if jmin>jmax.*/

 

#include <stdio.h>

#include <stdlib.h>

 

main()

{

 

     int A[20][30], sumColumns[30];

     int n, m, i, j, jMin, jMax, temp;

 

     do

     {

         printf("Please enter integer number of lines between 1 and 20\n");

         scanf("%d", &n);

     } while ((n <= 0) || (n > 20)); 

 

     do

     {

         printf("Please enter integer number of columns between 1 and 30 \n");

         scanf("%d", &m);

     } while ((n <= 0) || (n > 30)); 

 

     /* fill the matrix */

     printf("Enter %d lines of %d integers each\n", n, m);

     for(i= 0; i < n; i++)

       for (j= 0; j < m; j++)

          scanf("%d", &A[i][j]);

 

     jMin= 0;

     jMax= 0;

 

     for (j=0; j<m; j++)

     {

               sumColumns[j]= 0;

               for (i=0; i <n; i++)

                    sumColumns[j]= sumColumns[j] + A[i][j];

               if (sumColumns[j] < sumColumns[jMin])

                  jMin= j;

 

               if (sumColumns[j] > sumColumns[jMax])

                 jMax= j;

     }

     if (jMin > jMax)

            for (i=0; i <n; i++)

            {

                  temp= A[i][jMin];

                  A[i][jMin]= A[i][jMax];

                  A[i][jMax]= temp;

            }

 

     printf("Sum of Columns is ..:\n");

     for (i=0; i < m; i++)

         printf("sumColumn[%d] = %d\n", i, sumColumns[i]);

 

    printf("jMin = %d and jMax = %d \n", jMin, jMax);

 

     /* Show Matrix */

     printf("Contents of matrix %d rows of %d integers \n", n, m);

     for(i= 0; i < n; i++)

     {

       for (j= 0; j < m; j++)

           printf("%d ", A[i][j]);

       printf("\n");

     }

     system("pause");

     return 0;

} 
