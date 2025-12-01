#include <stdio.h>

/* fonction factorielle récursive (retourne int; attention overflow si n grand) */
int factorielle(int num) {
    if (num <= 1) {
        return 1;
    } else {
        return num * factorielle(num - 1);
    }
}

int main(void) {
    int tests[] = {0, 1, 2, 5, 7, 10};
    int ntests = sizeof(tests)/sizeof(tests[0]);
    for (int i = 0; i < ntests; i++) {
        int n = tests[i];
        int f = factorielle(n);
        printf("%d! = %d\n", n, f);
    }
    return 0;
}
