#include <stdio.h>
#include <stdlib.h>
int main(){
    int T[100];        // an array of 100 integers
    int N;             // the number of elements to read from user
    int *P;            // pointer to integer
    P = T;             // P points to the beginning of array T
    printf("Veuillez saisir la taille du tableau : ");
    scanf("%d", &N);
    printf("Veuillez saisir les elements du tableau : \n");

    for (P = T; P < N + T; P++) {
    printf("T[%d] = ", P - T);
    scanf("%d", P);
    }
    printf("Les elements du tableau sont : \n");

    for (P = T; P < N + T; P++) {
    printf("%d ", *P);
    }
    /*
✅ Visual summary (for N = 4):

| Index |    Value    |  Pointer Expression |
|-------|-------------|---------------------|
| T[0]  | ← P = T     | T + 0               |
| T[1]  |             | T + 1               |
| T[2]  |             | T + 2               |
| T[3]  | ← last used | T + 3               |
| T[4]  | ← T + N     | (loop ends here)    |

Notes:
- T points to the start of the array.
- T + N points just after the last used element.
- The loop runs while P < T + N → this ensures you visit T[0] to T[N-1].
*/



    return 0;
}