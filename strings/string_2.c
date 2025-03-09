#include <stdio.h>
#include <string.h>

int main() {
    // 1️⃣ strlen - Obtenir la longueur d'une chaîne
    char str1[] = "Omar";
    printf("Longueur de '%s' : %lu\n\n", str1, strlen(str1));

    // 2️⃣ strcpy - Copier une chaîne
    char source[] = "example";
    char destination[10];  // Taille suffisante
    strcpy(destination, source);
    printf("Copie avec strcpy: %s\n\n", destination);

    // 3️⃣ strcmp - Comparer deux chaînes
    char *s1 = "abc";
    char *s2 = "abd";
    int cmp = strcmp(s1, s2);
    printf("Comparaison de '%s' et '%s' : %d\n\n", s1, s2, cmp);

    //0 → Les chaînes sont identiques.
    // < 0 → s1 est plus petit que s2.
    // > 0 → s1 est plus grand que s2.

    // 4️⃣ strstr - Chercher une sous-chaîne
    char phrase[] = "Hello, world!";
    char *sub = "world";
    char *pos = strstr(phrase, sub);
    if (pos)
        printf("'%s' est une sous-chaîne de '%s'\n\n", sub, phrase);
    else
        printf("'%s' n'est PAS une sous-chaîne de '%s'\n\n", sub, phrase);

    // 5️⃣ strncpy - Copier n caractères
    char src[] = "example";
    char dest[5];  // Moins d'espace
    strncpy(dest, src, 4);  // Copie 4 caractères seulement
    dest[4] = '\0';  // Ajout de '\0' manuellement
    // Sans \0, dest ne sera pas une chaîne C valide et pourrait causer un comportement indéfini si nous l'affichons avec printf("%s", dest)
    // (il pourrait continuer à lire des caractères indésirables en mémoire).

    printf("Copie partielle avec strncpy : %s\n\n", dest);

    

    // 6️⃣ strncmp - Comparer les n premiers caractères
    char *st1 = "abc";
    char *st2 = "abd";
    int result = strncmp(st1, st2, 2);  // Compare seulement "ab" et "ab"
    printf("Comparaison partielle avec strncmp : %d\n", result);

    return 0;
}
