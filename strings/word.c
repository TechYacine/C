#include <stdio.h>
#include <string.h>

int main() {
    char T1[10][10] = {
        "Charlie", "David", "Eve",
        "Frank",   "Grace", "Hank",
        "Ivy",     "Jack",  "Kate",
        "" // 10th slot empty
    };

    // If T2 really has 15 rows, fill them, or just use 10 if you only have 10 items.
    char T2[10][10] = {
        "Frank", "Grace", "Hank", "Ivy",
        "Jack",  "Kate",  "Leo",  "Mia",
        "Rose",  "Steve"
    };

    // Outer loop: each word in T1
    for (int i = 0; i < 10; i++) {
        // Skip if T1[i] is empty
        if (T1[i][0] == '\0') {
            continue;
        }

        int found = 0;  // 0 means false

        // Inner loop: compare with every T2 entry
        for (int j = 0; j < 10; j++) {
            if (strcmp(T1[i], T2[j]) == 0) {
                found = 1; // We found a match in T2
                break;
            }
        }

        // If not found in T2, print it
        if (!found) {
            printf("%s\n", T1[i]);
        }
    }

    return 0;
}
