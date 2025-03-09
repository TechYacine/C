/*Application 1

Write a program that checks if a character string is a palindrome.

A palindrome is a word that is read left to right and right to left (that is, the word is read both ways).  

             Example of palindrome words: RADAR, HERE, SHE,

…
*/
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 



 

main()

{
    const int max=100;
    int i, j;

    char st_entry[max], car ;

 

    do

    {

       printf("Enter character string to check as palindrome\n");

       scanf("%s", st_entry);

 

       i = 0;

       j = strlen(st_entry) - 1;

 

       while ((i < j) && (st_entry[i] == st_entry[j]))

       {

            i = i + 1;

            j = j - 1;

       }

 

       if (i >= j)

         printf("%s Is a Palindrome \n", st_entry);

       else

         printf("%s Is not a Palindrome \n", st_entry);

 

       printf("Enter 'o' if you want to continue...\n");

       scanf(" %c", &car);

     } while (car == 'o');

 

     system("pause");

     return 0; 

}
