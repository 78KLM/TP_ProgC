#include <stdio.h>

int main() {
    int num1 = 10;   // valeurs de test
    int num2 = 3;    // à changer pour tester
    char op = '&';   // opérateur à tester

    int resultat;    // variable pour stocker le résultat

    switch (op) {

        case '+':
            resultat = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, resultat);
            break;

        case '-':
            resultat = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, resultat);
            break;

        case '*':
            resultat = num1 * num2;
            printf("%d * %d = %d\n", num1, num2, resultat);
            break;

        case '/':
            if (num2 != 0) {
                resultat = num1 / num2;
                printf("%d / %d = %d\n", num1, num2, resultat);
            } else {
                printf("Erreur : division par zero !\n");
            }
            break;

        case '%':
            if (num2 != 0) {
                resultat = num1 % num2;
                printf("%d %% %d = %d\n", num1, num2, resultat);
            } else {
                printf("Erreur : modulo par zero !\n");
            }
            break;

        case '&':
            resultat = num1 & num2;
            printf("%d & %d = %d (operation ET bit a bit)\n", num1, num2, resultat);
            break;

        case '|':
            resultat = num1 | num2;
            printf("%d | %d = %d (operation OU bit a bit)\n", num1, num2, resultat);
            break;

        case '~':
            resultat = ~num1;
            printf("~%d = %d (negation bit a bit de num1)\n", num1, resultat);
            break;

        default:
            printf("Erreur : operateur '%c' non reconnu.\n", op);
            break;
    }

    return 0;
}


