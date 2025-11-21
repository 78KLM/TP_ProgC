#include <stdio.h>

int main() {
    int d = 0x10001000;  // valeur de test, modifiez selon vos besoins

    // Détermination des positions des bits à tester (sur 32 bits)
    int bit4gauche = 31 - 3;   // = 28
    int bit20gauche = 31 - 19; // = 12

    // Extraction des bits
    int extrait4 = (d >> bit4gauche) & 1;
    int extrait20 = (d >> bit20gauche) & 1;

    // Vérification
    int resultat = (extrait4 == 1 && extrait20 == 1) ? 1 : 0;

    printf("%d\n", resultat);

    return 0;
}
