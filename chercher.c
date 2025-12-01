#include <stdio.h>

int same_string(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return 1;
}

int main() {
    char phrases[10][100] = {
        "Bonjour, comment ca va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journee.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent etre deroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est interessante.",
        "Les structures de donnees sont importantes.",
        "Programmer en C, c'est genial."
    };

    char recherche[100];
    printf("Entrez une phrase : ");
    fgets(recherche, 100, stdin);

    int i, trouve = 0;
    for (i = 0; i < 100; i++) {
        if (recherche[i] == '\n') {
            recherche[i] = '\0';
            break;
        }
    }

    for (i = 0; i < 10; i++) {
        if (same_string(phrases[i], recherche)) {
            trouve = 1;
            break;
        }
    }

    if (trouve) printf("Phrase trouvee\n");
    else printf("Phrase non trouvee\n");

    return 0;
}
