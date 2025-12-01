#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int t[100];
    int i;

    for (i = 0; i < 100; i++)
        t[i] = i * 2;

    printf("Tableau trié :\n");
    for (i = 0; i < 100; i++) printf("%d ", t[i]);
    printf("\n");

    int val;
    printf("Entrez l'entier à chercher : ");
    scanf("%d", &val);

    int gauche = 0, droite = 99, trouve = 0;

    while (gauche <= droite) {
        int milieu = (gauche + droite) / 2;

        if (t[milieu] == val) {
            trouve = 1;
            break;
        }
        else if (t[milieu] < val)
            gauche = milieu + 1;
        else
            droite = milieu - 1;
    }

    if (trouve) printf("entier présent\n");
    else printf("entier absent\n");

    return 0;
}
