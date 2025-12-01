#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int t[100];
    int i, val, trouve = 0;

    srand(time(NULL));

    for (i = 0; i < 100; i++)
        t[i] = rand() % 1000;

    printf("Tableau :\n");
    for (i = 0; i < 100; i++) printf("%d ", t[i]);
    printf("\n");

    printf("Entrez l'entier à chercher : ");
    scanf("%d", &val);

    for (i = 0; i < 100; i++) {
        if (t[i] == val) {
            trouve = 1;
            break;
        }
    }

    if (trouve) printf("entier présent\n");
    else printf("entier absent\n");

    return 0;
}
