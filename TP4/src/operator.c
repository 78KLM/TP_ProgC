#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int somme(int a, int b) { return a + b; }
int difference(int a, int b) { return a - b; }
int produit(int a, int b) { return a * b; }

int quotient(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Erreur: division par zero.\n");
        return 0;
    }
    return a / b;
}

int modulo(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Erreur: modulo par zero.\n");
        return 0;
    }
    return a % b;
}

int et_bit(int a, int b) { return a & b; }
int ou_bit(int a, int b) { return a | b; }

int negation(int a) { return ~a; }

/* Interaction simple pour l'exercice 4.1 */
void operator_entry(void) {
    int num1, num2;
    char op;
    printf("Entrez num1 : ");
    if (scanf("%d", &num1) != 1) { fprintf(stderr, "Lecture invalide\n"); return; }
    printf("Entrez num2 : ");
    if (scanf("%d", &num2) != 1) { fprintf(stderr, "Lecture invalide\n"); return; }
    printf("Entrez l'opérateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);

    int res = 0;
    switch (op) {
        case '+': res = somme(num1, num2); printf("Résultat : %d\n", res); break;
        case '-': res = difference(num1, num2); printf("Résultat : %d\n", res); break;
        case '*': res = produit(num1, num2); printf("Résultat : %d\n", res); break;
        case '/': res = quotient(num1, num2); printf("Résultat : %d\n", res); break;
        case '%': res = modulo(num1, num2); printf("Résultat : %d\n", res); break;
        case '&': res = et_bit(num1, num2); printf("Résultat (bitwise &) : %d\n", res); break;
        case '|': res = ou_bit(num1, num2); printf("Résultat (bitwise |) : %d\n", res); break;
        case '~': res = negation(num1); printf("Résultat (~num1) : %d\n", res); break;
        default: printf("Operateur inconnu: %c\n", op); break;
    }
}
