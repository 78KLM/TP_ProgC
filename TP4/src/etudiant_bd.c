#include <stdio.h>
#include <string.h>
#include "fichier.h"

/* Ce programme demande les infos de 5 étudiants et les écrit dans etudiant.txt (append) */

int main(void) {
    const char *dbfile = "etudiant.txt";
    char nom[64], prenom[64], adresse[200];
    char buf[512];
    float note1, note2;

    for (int i = 0; i < 5; i++) {
        printf("Entrez les details de l'etudiant.e %d :\n", i+1);

        printf("Nom : ");
        if (!fgets(nom, sizeof(nom), stdin)) return 1;
        nom[strcspn(nom, "\n")] = 0;

        printf("Prenom : ");
        if (!fgets(prenom, sizeof(prenom), stdin)) return 1;
        prenom[strcspn(prenom, "\n")] = 0;

        printf("Adresse : ");
        if (!fgets(adresse, sizeof(adresse), stdin)) return 1;
        adresse[strcspn(adresse, "\n")] = 0;

        printf("Note 1 : ");
        if (scanf("%f", &note1) != 1) { fprintf(stderr, "Lecture invalide\n"); return 1; }
        printf("Note 2 : ");
        if (scanf("%f", &note2) != 1) { fprintf(stderr, "Lecture invalide\n"); return 1; }
        getchar(); /* consomme newline */

        snprintf(buf, sizeof(buf), "%s;%s;%s;%.2f;%.2f", nom, prenom, adresse, note1, note2);
        if (ecrire_dans_fichier(dbfile, buf) == 0) {
            printf("Details enregistrés pour %s %s\n\n", prenom, nom);
        } else {
            printf("Erreur écriture pour %s %s\n\n", prenom, nom);
        }
    }

    printf("Les details des etudiants ont ete enregistres dans %s\n", dbfile);
    return 0;
}
