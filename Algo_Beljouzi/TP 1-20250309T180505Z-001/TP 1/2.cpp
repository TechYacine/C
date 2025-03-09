/*App 2

Given a square matrix A(N, N) of integers (N<=25), 
write a program which allows you to calculate the trace of the matrix A. The trace is the sum of the elements of the main diagonal.*/

 

 

#include <stdio.h>

#include <stdlib.h> 

main()

{

     int A[25][25];

     int n, i, j, trace; 

 

     do

     {

         printf("Please enter N positive integer between and 25\n");

         scanf("%d", &n);

     } while ((n <= 0) || (n > 25));

 

     /* fill the array */

     printf("Enter %d lines of %d integers each\n", n , n);

     for(i= 0; i < n; i++)

       for (j= 0; j < n; j++)

         scanf("%d", &A[i][j]);

 

     printf("Contents of the matrix row by row \n");

     for(i= 0; i < n; i++)

     {

       for (j= 0; j < n; j++)

          printf("%d ", A[i][j]);

       printf("\n");

     }

 

     trace= 0;

     for(i= 0; i < n; i++)

       trace = trace + A[i][i];

 

     printf("matrix trace is: %d\n" , trace);

     system("pause");

     return 0;

}
