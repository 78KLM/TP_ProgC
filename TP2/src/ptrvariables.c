#include <stdio.h>

int main() {
    char c = 'A';
    short s = 123;
    int i = 45678;
    long l = 987654321;
    long long ll = 1234567890123;
    float f = 3.14f;
    double d = 6.28;
    long double ld = 9.81;

    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long *pl = &l;
    long long *pll = &ll;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;

    printf("Avant manipulation :\n");
    printf("i : adresse=%p valeur=%x\n", pi, i);
    printf("f : adresse=%p valeur=%x\n", pf, *(unsigned int*)pf);

    (*pi)--;
    *pf = 1.0f;

    printf("\nAprès manipulation :\n");
    printf("i : adresse=%p valeur=%x\n", pi, i);
    printf("f : adresse=%p valeur=%x\n", pf, *(unsigned int*)pf);

    return 0;
}
