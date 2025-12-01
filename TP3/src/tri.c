#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int t[100];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < 100; i++) {
        t[i] = rand() % 1000;
    }

    printf("Tableau non trié :\n");
    for (i = 0; i < 100; i++) printf("%d ", t[i]);
    printf("\n");

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 99 - i; j++) {
            if (t[j] > t[j + 1]) {
                int tmp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tmp;
            }
        }
    }

    printf("Tableau trié :\n");
    for (i = 0; i < 100; i++) printf("%d ", t[i]);
    printf("\n");

    return 0;
}
