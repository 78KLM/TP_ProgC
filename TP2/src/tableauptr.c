#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int t1[11];
    float t2[11];

    srand(time(NULL));

    // Remplissage
    for (int i = 0; i < 11; i++) {
        t1[i] = rand() % 100;
        t2[i] = (float)(rand() % 1000) / 100.0f;
    }

    printf("Avant :\n");
    for (int i = 0; i < 11; i++) printf("%d ", t1[i]);
    printf("\n");
    for (int i = 0; i < 11; i++) printf("%.2f ", t2[i]);
    printf("\n\n");

    // Manipulation via pointeurs
    int *p1 = t1;
    float *p2 = t2;

    for (int i = 0; i < 11; i++) {
        if (i % 2 == 0) {
            *(p1 + i) *= 3;
            *(p2 + i) *= 3;
        }
    }

    printf("Après :\n");
    for (int i = 0; i < 11; i++) printf("%d ", t1[i]);
    printf("\n");
    for (int i = 0; i < 11; i++) printf("%.2f ", t2[i]);
    printf("\n");

    return 0;
}
