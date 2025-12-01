#include <stdio.h>

int main() {
    char nom[5][30] = {"Dupont", "Martin", "Durand", "Leroy", "Bernard"};
    char prenom[5][30] = {"Marie", "Pierre", "Luc", "Sarah", "Jean"};
    char adresse[5][100] = {
        "10 rue A", "22 boulevard B", "15 avenue C",
        "7 place D", "9 chemin E"
    };

    float note_prog[5] = {16.5, 14.2, 10.0, 18.0, 11.5};
    float note_sys[5] = {12.1, 13.7, 9.4, 15.0, 10.2};

    for (int i = 0; i < 5; i++) {
        printf("Etudiant %d :\n", i+1);
        printf("Nom : %s\n", nom[i]);
        printf("Prenom : %s\n", prenom[i]);
        printf("Adresse : %s\n", adresse[i]);
        printf("Note prog : %.2f\n", note_prog[i]);
        printf("Note sys : %.2f\n\n", note_sys[i]);
    }

    return 0;
}
