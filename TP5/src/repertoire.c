#include "repertoire.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

// ---------------------
// EXERCICE 5.1
// ---------------------

void lire_dossier(const char *nom) {
    DIR *d = opendir(nom);
    if (!d) {
        perror("Erreur ouverture répertoire");
        return;
    }

    struct dirent *ent;
    printf("Contenu de %s :\n", nom);

    while ((ent = readdir(d)) != NULL) {
        printf("%s\n", ent->d_name);
    }
    closedir(d);
}

// ---------------------
// EXERCICE 5.2 (récursif)
// ---------------------

void lire_dossier_recursif(const char
