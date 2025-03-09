#include <stdio.h>

int main() {
    int N;
    int t[100], v[200]; // Array t[100] and v[200]

    // Get N within the range [2, 100]
    do {
        printf("Enter the value of N (between 2 and 100): ");
        scanf("%d", &N);
    } while (N < 2 || N > 100);

    // Input N elements into array t
    printf("Enter %d elements:\n", N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &t[i]);
    }

    // Find max sum of consecutive pairs
    int max = t[0] + t[1];
    for(int i = 0; i < N-1; i++) {
        if(t[i] + t[i+1] > max) {
            max = t[i] + t[i+1]; 
        }
    }
    
    // Store all pairs with max sum in v
    int j = 0;
    for(int i = 0; i < N-1; i++) {
        if(t[i] + t[i+1] == max) {
            v[j++] = t[i];
            v[j++] = t[i+1];
        }
    }

    // Print the maximum sum
    printf("The max is %d\n", max);

    // Remove consecutive duplicates in v
    int k = 0;  // Start with the first element as unique
    for(int i = 1; i < j; i++) {
        if(v[i] != v[k]) {  // If the current element is not the same as the last unique element
            k++;  // Increment k to move to the next position in the array
            v[k] = v[i];  // Store the new unique element in the array
        }
    }

    // Now k represents the last unique element index
    k++;  // Include the last unique element (because `k` represents the last index with a unique value)

    // Print the final array without consecutive duplicates
    printf("Array without consecutive duplicates:\n");
    for(int i = 0; i < k; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
