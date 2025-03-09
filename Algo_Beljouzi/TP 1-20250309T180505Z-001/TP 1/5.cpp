/*App 2

Consider a CH character string terminated by point '.'. Write a program that:

     - displays the number of characters of CH, i.e. the size of CH;

- displays the number of lowercase alphabetic characters;

- displays the number of uppercase alphabetic characters.

(We assume, in this exercise, that we do not have the size function which gives the size of a character string).*/

 

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

const int max=100; 

 

main()

{

    int i, size, cpt_min, cpt_maj;

    char ch[max];

 

    i = 0;

    size = 1;

 

    cpt_min = 0;

    cpt_maj = 0;

     printf("Enter character string ending with a period\n");

     scanf("%s", ch);

 

     /* We assume in what follows that the user always gives us a string that ends with a dot */

 

     while (ch[i] != '.')

      {

        size++;

        if ((ch[i] >= 'a') && (ch[i] <= 'z'))

            cpt_min++;

        if ((ch[i] >= 'A') && (ch[i] <= 'Z'))

            cpt_maj++;

        i = i + 1;

      }

 

     printf("Size of CH %s is = %d\n", ch, size);

     printf("For comparison, size that strlen returns = %d\n", strlen(ch));

     printf("Number of lowercase letters = %d\n", cpt_min);

     printf("Number of uppercase letters = %d\n", cpt_maj);

 

     system("pause");

     return 1;

 

}
