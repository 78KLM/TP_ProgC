
#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

int main(void) {
    int choix = -1;
    while (1) {
        printf("\n==== Menu principal (exercices 4.x) ====\n");
        printf("1. Exercice 4.1 - Calcul avec opérateurs (operator_entry)\n");
        printf("2. Exercice 4.2 - Gestion de fichiers (fichier_entry)\n");
        printf("3. Exercice 4.7 - Gestion d'une liste de couleurs (liste_entry)\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        if (scanf("%d", &choix) != 1) { fprintf(stderr, "Lecture invalide\n"); return 1; }
        getchar(); /* consomme newline */

        switch (choix) {
            case 1:
                operator_entry();
                break;
            case 2:
                fichier_entry();
                break;
            case 3:
                liste_entry();
                break;
            case 0:
                printf("Au revoir.\n");
                return 0;
            default:
                printf("Choix non reconnu.\n");
                break;
        }
    }
    return 0;
}
