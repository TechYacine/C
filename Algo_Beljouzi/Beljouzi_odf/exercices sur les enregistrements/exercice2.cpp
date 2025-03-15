#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Let TDate be a date type composed of the integer fields DD, MM, YY.

Write the following PAs:
- CompareD: compares two dates D1 and D2 (-1, 0, 1 for lower, equal, and higher).
- LEAP : checks if a year is a leap year (année bissextile).
- Valid : checks the validity of a date.
- DiffDays : calculates the difference in days between two dates.

Let TD be an array of N dates (N=100). Write an algorithm allowing to:
- Sort this array in ascending date order.
- Calculate the minimum difference in number of days between these dates.
*/

typedef struct {
    int DD, MM, YY;
} TDate;

bool leap(int YY) {
    if ( ((YY % 4 == 0) && (YY % 100 != 0)) || (YY % 400 == 0) )
       return true;
    return false;
}

bool Valid(TDate d) {
    bool ret = false;
    if (d.YY >= 0) {
        switch (d.MM) {
           case 1: case 3: case 5: case 7: case 8: case 10: case 12:
               if ( (d.DD >= 1) && (d.DD <= 31) )
                  ret = true;
           break;
           case 4: case 6: case 9: case 11:
               if ( (d.DD >= 1) && (d.DD <= 30) )
                   ret = true;
           break;
           case 2:
              if (leap(d.YY)) {
                 if ( (d.DD >= 1) && (d.DD <= 29) )
                   ret = true;
              } else {
                 if ( (d.DD >= 1) && (d.DD <= 28) )
                   ret = true;
              }
           break;
        }
    }
    return ret;
}

int compareD(TDate d1, TDate d2) {
    if (d1.YY > d2.YY)
        return 1;
    else if (d1.YY < d2.YY)
        return -1;
    else if (d1.MM > d2.MM)
        return 1;
    else if (d1.MM < d2.MM)
        return -1;
    else if (d1.DD > d2.DD)
        return 1;
    else if (d1.DD < d2.DD)
        return -1;
    else return 0;
}

void readTabTDate(TDate T[], int N) {
    int i;
    for (i = 0; i < N; i++) {
       do {
             printf("Plz Enter Valid Date as YYYY MM DD of Date %d of array TD: ", i + 1);
             scanf("%d %d %d", &T[i].YY, &T[i].MM, &T[i].DD);
       } while(!Valid(T[i]));
    }
}

void displayTabTDate(TDate T[], int N) {
    int i;
    printf("\n\nArray of Dates TD:\n");
    for (i = 0; i < N; i++) {
        printf("%4d %2d %2d\n", T[i].YY, T[i].MM, T[i].DD);
    }
    printf("*********************\n");
}

int NbDaysYear(TDate d) {
    int i, nbj;
    nbj = d.DD;
    for(i = 0; i < d.MM - 1; i++) {
        switch(i) {
           case 1: case 3: case 5: case 7: case 8: case 10: case 12:
              nbj += 31;
           break;
           case 4: case 6: case 9: case 11:
               nbj += 30;
           break;
           case 2:
              if (leap(d.YY))
                 nbj += 29;
              else
                 nbj += 28;
           break;
        }
    }
    return nbj;
}

int DiffDays(TDate d1, TDate d2) {
    int i, nbj;
    TDate d;
    if (compareD(d1, d2) == 1) {
        d = d1;
        d1 = d2;
        d2 = d;
    }
    nbj = NbDaysYear(d2);
    for (i = d1.YY; i < d2.YY; i++) {
        if (leap(i))
            nbj += 366;
        else
            nbj += 365;
    }
    nbj -= NbDaysYear(d1);
    return nbj;
}

void sortTabTDate(TDate T[], int N) {
    int i, j, iMin;
    TDate tmp;
    for (i = 0; i < N - 1; i++) {
       iMin = i;
       for (j = i; j < N; j++) {
           if (compareD(T[iMin], T[j]) == 1)
             iMin = j;
       }
       if (iMin != i) {
           tmp = T[iMin];
           T[iMin] = T[i];
           T[i] = tmp;
       }
    }
}

int main() {
    int N, i, nb, minNbD;
    TDate TD[100];
    do {
        printf("Plz Enter  N between 2 and 100: ");
        scanf("%d", &N);
    } while ((N < 2) || (N > 100));
    readTabTDate(TD, N);
    displayTabTDate(TD, N);
    sortTabTDate(TD, N);
    displayTabTDate(TD, N);
    minNbD = DiffDays(TD[0], TD[1]);;
    for (i = 1; i < N - 1; i++) {
      nb = DiffDays(TD[i], TD[i + 1]);
      if (nb < minNbD)
         minNbD = nb;
    }
    printf("The Min Difference in number of days between 2 dates = %d ...\n", minNbD);
    return 0;
}
