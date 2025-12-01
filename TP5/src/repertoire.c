#include "repertoire.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

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

static void _lire_recursif(const char *basepath, int depth) {
    DIR *d = opendir(basepath);
    if (!d) {
        fprintf(stderr, "Impossible d'ouvrir '%s' : %s\n", basepath, strerror(errno));
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(d)) != NULL) {
        // ignorer . et ..
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        // afficher avec indentation
        for (int i = 0; i < depth; i++) putchar(' ');
        printf("%s\n", ent->d_name);

        // construire chemin complet
        size_t len = strlen(basepath) + 1 + strlen(ent->d_name) + 1;
        char *path = malloc(len);
        if (!path) { closedir(d); return; }
        snprintf(path, len, "%s/%s", basepath, ent->d_name);

        // vérifier si c'est un répertoire
        struct stat st;
        if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
            _lire_recursif(path, depth + 2);
        }
        free(path);
    }
    closedir(d);
}

void lire_dossier_recursif(const char *nom) {
    printf("Listing récursif de %s :\n", nom);
    _lire_recursif(nom, 0);
}

// ---------------------
// EXERCICE 5.3 (itératif)
// ---------------------

/*
  Approche simple : on maintient une pile (tableau dynamique) de chemins à traiter.
  On pop un chemin, on liste son contenu et on push tout sous-répertoire.
*/
void lire_dossier_iteratif(const char *nom) {
    // tableau dynamique de chemins
    size_t cap = 16;
    size_t count = 0;
    char **stack = malloc(cap * sizeof(char*));
    if (!stack) { perror("malloc"); return; }

    stack[count++] = strdup(nom);

    while (count > 0) {
        // pop
        char *path = stack[--count];

        DIR *d = opendir(path);
        if (!d) {
            fprintf(stderr, "Impossible d'ouvrir '%s' : %s\n", path, strerror(errno));
            free(path);
            continue;
        }

        printf("Contenu de %s :\n", path);
        struct dirent *ent;
        while ((ent = readdir(d)) != NULL) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                continue;

            printf("  %s\n", ent->d_name);

            // construire chemin complet
            size_t len = strlen(path) + 1 + strlen(ent->d_name) + 1;
            char *sub = malloc(len);
            if (!sub) continue;
            snprintf(sub, len, "%s/%s", path, ent->d_name);

            struct stat st;
            if (stat(sub, &st) == 0 && S_ISDIR(st.st_mode)) {
                // push sub directory
                if (count >= cap) {
                    cap *= 2;
                    stack = realloc(stack, cap * sizeof(char*));
                    if (!stack) { perror("realloc"); exit(1); }
                }
                stack[count++] = sub; // ownership transferred
            } else {
                free(sub);
            }
        }

        closedir(d);
        free(path);
    }

    free(stack);
}
