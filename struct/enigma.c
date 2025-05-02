#include <stdio.h>
#include <string.h>

typedef struct {
    int T[100];  
    int N;       
} E;

E funct(char M[]) {
    E E1;
    E1.N = 0; 
    int k = 0;
    int i = 0;
    int len = strlen(M);

    while (i < len - 1) {
        if (M[i] == 'a' && M[i + 1] == 'b') {
            E1.T[k] = i;  
            E1.N++;
            k++;
            i += 2; 
        } else {
            i++;
        }
    }
    return E1;
}

void removeAllAb(char M[]) {
    E E2 = funct(M);

    // Print occurrences
    printf("Total occurrences of 'ab': %d\n", E2.N);
    printf("Positions of 'ab': ");
    for (int i = 0; i < E2.N; i++) {
        printf("%d ", E2.T[i]);
    }
    printf("\n");

    if (E2.N > 1) {
        printf("Repeated indices: ");
        for (int i = 1; i < E2.N; i++) {
            printf("%d ", E2.T[i]);
        }
        printf("\n");
    }

    
    char M2[100]; 
    int k = 0;
    int i = 0;
    while (i < strlen(M)) {
        if (i < strlen(M) - 1 && M[i] == 'a' && M[i+1] == 'b') {
            i += 2;
        } else {
            M2[k++] = M[i++];
        }
    }
    M2[k] = '\0'; 

    printf("New string after removing 'ab': %s\n", M2);
}

int main() {
    char M[] = "dabbbaiaabbeabababoebab";
    printf("Original: %s\n", M);

    removeAllAb(M);
    return 0;
}