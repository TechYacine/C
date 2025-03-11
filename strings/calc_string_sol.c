#include <stdio.h>
#include <string.h>

int main() {
    char ch[100]; // Buffer to store the input string
    printf("Enter a string terminated by '.': ");
    scanf("%s", ch); // Read the input string

    int length = 0;
    int lowercaseCount = 0;
    int uppercaseCount = 0;

    // Iterate through the string until '.' or '\0' is found
    while (ch[length] != '.' && ch[length] != '\0') {
        if (ch[length] >= 'a' && ch[length] <= 'z') {
            lowercaseCount++;
        } else if (ch[length] >= 'A' && ch[length] <= 'Z') {
            uppercaseCount++;
        }
        length++;
    }

    // Display the results
    printf("Number of characters: %d\n", length);
    printf("Number of lowercase alphabetic characters: %d\n", lowercaseCount);
    printf("Number of uppercase alphabetic characters: %d\n", uppercaseCount);

    return 0;
}