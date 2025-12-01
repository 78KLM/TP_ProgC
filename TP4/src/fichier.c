#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

int lire_fichier(const char *nom_de_fichier) {
    FILE *f = fopen(nom_de_fichier, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return -1;
    }
    char buf[1024];
    printf("Contenu du fichier %s :\n", nom_de_fichier);
    while (fgets(buf, sizeof(buf), f)) {
        fputs(buf, stdout);
    }
    fclose(f);
    return 0;
}

int ecrire_dans_fichier(const char *nom_de_fichier, const char *message) {
    FILE *f = fopen(nom_de_fichier, "a"); /* append */
    if (!f) {
        perror("Erreur ouverture fichier en ecriture");
        return -1;
    }
    fprintf(f, "%s\n", message);
    fclose(f);
    return 0;
}

void fichier_entry(void) {
    int choix = 0;
    char filename[256];
    char message[1024];

    while (1) {
        printf("\nQue souhaitez-vous faire ?\n1. Lire un fichier\n2. Ecrire dans un fichier\n3. Retour\nVotre choix : ");
        if (scanf("%d", &choix) != 1) { fprintf(stderr, "Lecture invalide\n"); return; }
        getchar(); /* consomme newline */

        if (choix == 1) {
            printf("Entrez le nom du fichier à lire : ");
            if (!fgets(filename, sizeof(filename), stdin)) return;
            filename[strcspn(filename, "\n")] = 0;
            lire_fichier(filename);
        } else if (choix == 2) {
            printf("Entrez le nom du fichier dans lequel vous souhaitez écrire : ");
            if (!fgets(filename, sizeof(filename), stdin)) return;
            filename[strcspn(filename, "\n")] = 0;

            printf("Entrez le message à écrire : ");
            if (!fgets(message, sizeof(message), stdin)) return;
            message[strcspn(message, "\n")] = 0;

            if (ecrire_dans_fichier(filename, message) == 0)
                printf("Le message a été écrit dans le fichier %s.\n", filename);
        } else if (choix == 3) {
            break;
        } else {
            printf("Choix invalide\n");
        }
    }
}
