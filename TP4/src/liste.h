#ifndef LISTE_H
#define LISTE_H

typedef struct couleur {
    unsigned char r, g, b, a;
} couleur_t;

struct node {
    couleur_t c;
    struct node *next;
};

typedef struct {
    struct node *head;
} liste_couleurs_t;

/* initialisation */
void init_liste(liste_couleurs_t *l);

/* insertion (en tête) : copie la couleur */
void insertion(const couleur_t *couleur, liste_couleurs_t *l);

/* parcours et affichage */
void parcours(const liste_couleurs_t *l);

/* wrapper d'entrée pour l'exercice 4.7 */
void liste_entry(void);

#endif /* LISTE_H */
