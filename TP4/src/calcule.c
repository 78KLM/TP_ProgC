#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

/* utilisation: ./calcule <op> <num1> <num2>
   op est un caractère: + - * / % & | ~ (pour ~, num2 est ignoré) */

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <op> <num1> [num2]\n", argv[0]);
        return 1;
    }

    char op = argv[1][0];
    int num1 = atoi(argv[2]);
    int num2 = 0;
    if (argc >= 4) num2 = atoi(argv[3]);

    int res = 0;
    switch (op) {
        case '+': res = somme(num1, num2); break;
        case '-': res = difference(num1, num2); break;
        case '*': res = produit(num1, num2); break;
        case '/': res = quotient(num1, num2); break;
        case '%': res = modulo(num1, num2); break;
        case '&': res = et_bit(num1, num2); break;
        case '|': res = ou_bit(num1, num2); break;
        case '~': res = negation(num1); break;
        default:
            fprintf(stderr, "Operateur inconnu: %c\n", op);
            return 1;
    }
    printf("Résultat : %d\n", res);
    return 0;
}
