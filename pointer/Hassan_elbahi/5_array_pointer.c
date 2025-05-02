#include <stdio.h>

int main() {
    int tab[5] = {10, 20, 30, 40, 50};
    int *p = tab;

    for (int i = 0; i < 5; i++) {
        printf("tab[%d]     = %d\n", i, tab[i]);
        printf("*(tab + %d) = %d\n", i, *(tab + i));
        printf("p[%d]       = %d\n", i, p[i]);
        printf("*(p + %d)   = %d\n", i, *(p + i));
        printf("i[tab]      = %d\n", i[tab]);
        printf("-------------------------\n");
    }

    return 0;
}
