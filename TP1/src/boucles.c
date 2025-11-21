#include <stdio.h>

int main() {
    int compteur = 5;  // Change ce nombre pour tester (<10)

    if (compteur >= 10) {
        printf("Erreur : compteur doit etre strictement inferieur a 10.\n");
        return 1;
    }

    int ligne = 1;

    while (ligne <= compteur) {

        int col = 1;

        while (col <= ligne) {

            // Exemple d’utilisation de continue :
            // Si col == 0, passer directement à la suite (inutile ici, donc juste démonstration)
            if (col == 0)
                continue;

            if (col % 2 == 0)
                printf("# ");
            else
                printf("* ");

            col++;
        }

        printf("\n");
        ligne++;
    }

    return 0;
}
