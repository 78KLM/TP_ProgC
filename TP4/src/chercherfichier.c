#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* recherche naive d'une sous-chaîne dans une ligne — retourne nombre d'occurrences */
static int count_substr(const char *line, const char *pat) {
    int count = 0;
    size_t L = strlen(pat);
    if (L == 0) return 0;
    const char *p = line;
    while ((p = strstr(p, pat)) != NULL) {
        count++;
        p += L;
    }
    return count;
}

int main(void) {
    char filename[256];
    char phrase[512];
    printf("Entrez le nom du fichier à lire : ");
    if (!fgets(filename, sizeof(filename), stdin)) return 1;
    filename[strcspn(filename, "\n")] = 0;

    printf("Entrez la phrase que vous souhaitez rechercher : ");
    if (!fgets(phrase, sizeof(phrase), stdin)) return 1;
    phrase[strcspn(phrase, "\n")] = 0;

    FILE *f = fopen(filename, "r");
    if (!f) { perror("Erreur ouverture fichier"); return 1; }

    char line[2048];
    int line_no = 0;
    int total_found = 0;
    printf("Résultats de la recherche :\n");
    while (fgets(line, sizeof(line), f)) {
        line_no++;
        int cnt = count_substr(line, phrase);
        if (cnt > 0) {
            printf("Ligne %d, %d fois\n", line_no, cnt);
            total_found += cnt;
        }
    }
    if (total_found == 0) {
        printf("Phrase non trouvée.\n");
    }
    fclose(f);
    return 0;
}
