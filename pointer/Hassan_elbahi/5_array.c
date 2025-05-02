/*
 * C Pointer Exercise Walkthrough
 * Exercise #84 - Memory Manipulation with Pointers
 */

// tab[i]        ≡  *(tab + i)
// *(tab + i)    ≡  tab[i]

// p[i]          ≡  *(p + i)
// *(p + i)      ≡  p[i]

#include <stdio.h>

int main() {
    // Initial variable declarations
    int a = 10;
    int b = 5;
    int tab[3] = {1, 2, 3};
    int *p;

    /* 
     * INITIAL MEMORY STATE (each int took 4 bytes of memory)
     * | Variable | Address | Value |
     * |----------|---------|-------|
     * | a        | 1000    | 10    | 
     * | b        | 1004    | 5     |
     * | tab[0]   | 1008    | 1     |
     * | tab[1]   | 1012    | 2     |
     * | tab[2]   | 1016    | 3     |
     * | p        | 1020    | ?     |
     */

    // Step 1: tab[0] = a;
    tab[0] = a;  // Copy value from a to tab[0]
    /*
     * After tab[0] = a:
     * | tab[0] | 1008 | 10 (was 1) |
     */

    // Step 2: *(tab + 1) = b;
    *(tab + 1) = b;  // Pointer notation to set tab[1] = b
    /*
     * After *(tab + 1) = b:
     * | tab[1] | 1012 | 5 (was 2) |
     */

    // Step 3: p = tab + 2;
    p = tab + 2;  // p now points to tab[2]
    /*
     * After p = tab + 2:
     * | p | 1020 | 1016 (address of tab[2]) |
     */

    // Step 4: *p = *(p - 1);
    *p = *(p - 1);  // Copy value from tab[1] to tab[2]
    /*
     * After *p = *(p - 1):
     * | tab[2] | 1016 | 5 (was 3) |
     */

    // Step 5: --p;
    --p;  // Move pointer back to tab[1]
    /*
     * After --p:
     * | p | 1020 | 1012 (now points to tab[1]) |
     */

    // Step 6: *p = *(p - 1);
    *p = *(p - 1);  // Copy value from tab[0] to tab[1]
    /*
     * After *p = *(p - 1):
     * | tab[1] | 1012 | 10 (was 5) |
     */

    // Step 7: --p;
    --p;  // Move pointer back to tab[0]
    /*
     * After --p:
     * | p | 1020 | 1008 (now points to tab[0]) |
     */

    // Step 8: *p = *(p + 1);
    *p = *(p + 1);  // Copy value from tab[1] to tab[0]
    /*
     * Final Memory State:
     * | Variable | Address | Value |
     * |----------|---------|-------|
     * | a        | 1000    | 10    |
     * | b        | 1004    | 5     |
     * | tab[0]   | 1008    | 10    |
     * | tab[1]   | 1012    | 10    |
     * | tab[2]   | 1016    | 5     |
     * | p        | 1020    | 1008  |
     */

    return 0;
}

