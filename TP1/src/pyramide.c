#include <stdio.h>

int main() {
    int n = 5;  // hauteur de la pyramide
    int i, j;

    for (i = 1; i <= n; i++) {

        // 1) Affichage des espaces pour centrer la ligne
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 2) Affichage des nombres croissants 1 → i
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // 3) Affichage des nombres décroissants (i - 1) → 1
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        // 4) Nouvelle ligne
        printf("\n");
    }

    printf("\nPyramide terminee.\n");

    return 0;
}

