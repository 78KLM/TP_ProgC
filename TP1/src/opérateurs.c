#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;

    printf("a = %d, b = %d\n\n", a, b);

    
    printf("Addition (a + b) = %d\n", a + b);
    printf("Soustraction (a - b) = %d\n", a - b);
    printf("Multiplication (a * b) = %d\n", a * b);
    printf("Division (a / b) = %d\n", a / b);  // division entière
    printf("Modulo (a %% b) = %d\n", a % b);

    // Opérateurs logiques (comparaisons)
    printf("\nComparaison (a == b) = %d\n", (a == b));
    printf("Comparaison (a > b) = %d\n", (a > b));

    return 0;
}
