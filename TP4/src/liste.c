#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(liste_couleurs_t *l) {
    l->head = NULL;
}

void insertion(const couleur_t *couleur, liste_couleurs_t *l) {
    struct node *n = malloc(sizeof(struct node));
    if (!n) {
        perror("malloc");
        return;
    }
    n->c = *couleur;
    n->next = l->head;
    l->head = n;
}

void parcours(const liste_couleurs_t *l) {
    struct node *cur = l->head;
    int idx = 0;
    while (cur) {
        printf("Couleur %d : %02x %02x %02x %02x\n",
               idx + 1, cur->c.r, cur->c.g, cur->c.b, cur->c.a);
        cur = cur->next;
        idx++;
    }
}

/* wrapper qui crée 10 couleurs, les insère et affiche la liste */
void liste_entry(void) {
    liste_couleurs_t ma_liste;
    init_liste(&ma_liste);

    couleur_t couleurs[10] = {
        {0xff,0x00,0x00,0xff}, {0x00,0xff,0x00,0xff}, {0x00,0x00,0xff,0xff},
        {0xef,0x78,0x12,0xff}, {0x2c,0xc8,0x64,0xff}, {0xaa,0x00,0xff,0x80},
        {0x10,0x20,0x30,0x40}, {0xff,0xff,0x00,0xff}, {0x55,0x66,0x77,0x88},
        {0x12,0x34,0x56,0x78}
    };

    for (int i = 0; i < 10; i++) insertion(&couleurs[i], &ma_liste);

    printf("Liste des couleurs :\n");
    parcours(&ma_liste);

    /* libération */
    struct node *cur = ma_liste.head;
    while (cur) {
        struct node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}
