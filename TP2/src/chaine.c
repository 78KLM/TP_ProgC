#include <stdio.h>

int main() {
    char s1[50] = "Hello";
    char s2[50] = " World!";
    char copie[50];
    char concat[100];

    // Longueur
    int len = 0;
    while (s1[len] != '\0') len++;

    // Copie
    int i = 0;
    while (s1[i] != '\0') {
        copie[i] = s1[i];
        i++;
    }
    copie[i] = '\0';

    // Concaténation
    int j = 0;
    while (s1[j] != '\0') {
        concat[j] = s1[j];
        j++;
    }
    int k = 0;
    while (s2[k] != '\0') {
        concat[j + k] = s2[k];
        k++;
    }
    concat[j + k] = '\0';

    printf("Longueur = %d\n", len);
    printf("Copie = %s\n", copie);
    printf("Concat = %s\n", concat);

    return 0;
}
