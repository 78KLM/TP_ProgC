#ifndef FICHIER_H
#define FICHIER_H

/* lire_fichier : affiche le contenu du fichier; retourne 0 si OK, non-0 sinon */
int lire_fichier(const char *nom_de_fichier);

/* ecrire_dans_fichier : ajoute 'message' dans le fichier (append). Retourne 0 si OK. */
int ecrire_dans_fichier(const char *nom_de_fichier, const char *message);

/* wrapper d'entrée pour l'exercice 4.2 */
void fichier_entry(void);

#endif /* FICHIER_H */
