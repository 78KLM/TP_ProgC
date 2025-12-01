#include <stdio.h>
#include <string.h>

struct Etudiant {
    char nom[30];
    char prenom[30];
    char adresse[100];
    float note1;
    float note2;
};

int main() {
    struct Etudiant e[5];

    strcpy(e[0].nom, "Dupont"); strcpy(e[0].prenom, "Marie");
    strcpy(e[0].adresse, "10 rue A"); e[0].note1 = 16.5; e[0].note2 = 12.1;

    strcpy(e[1].nom, "Martin"); strcpy(e[1].prenom, "Pierre");
    strcpy(e[1].adresse, "22 boulevard B"); e[1].note1 = 14.0; e[1].note2 = 14.1;

    strcpy(e[2].nom, "Durand"); strcpy(e[2].prenom, "Luc");
    strcpy(e[2].adresse, "15 avenue C"); e[2].note1 = 10.0; e[2].note2 = 9.7;

    strcpy(e[3].nom, "Leroy"); strcpy(e[3].prenom, "Sarah");
    strcpy(e[3].adresse, "7 place D"); e[3].note1 = 18.0; e[3].note2 = 15.0;

    strcpy(e[4].nom, "Bernard"); strcpy(e[4].prenom, "Jean");
    strcpy(e[4].adresse, "9 chemin E"); e[4].note1 = 11.5; e[4].note2 = 10.3;

    for (int i = 0; i < 5; i++) {
        printf("Etudiant %d :\n", i+1);
        printf("Nom : %s\n", e[i].nom);
        printf("Prenom : %s\n", e[i].prenom);
        printf("Adresse : %s\n", e[i].adresse);
        printf("Note 1 : %.2f\n", e[i].note1);
        printf("Note 2 : %.2f\n\n", e[i].note2);
    }

    return 0;
}
