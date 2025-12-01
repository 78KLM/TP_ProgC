#include <stdio.h>

int main() {
    int n = 7;
    int u0 = 0, u1 = 1, u;

    printf("%d, %d", u0, u1);

    for (int i = 2; i <= n; i++) {
        u = u0 + u1;
        printf(", %d", u);
        u0 = u1;
        u1 = u;
    }

    printf("\n");
    return 0;
}
