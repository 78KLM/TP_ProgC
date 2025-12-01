#include <stdio.h>

void print_bytes(void *p, int size) {
    unsigned char *c = (unsigned char*)p;

    for (int i = 0; i < size; i++)
        printf("%02x ", c[i]);
    printf("\n");
}

int main() {
    short s = 0x0302;
    int i = 0x04030201;
    long l = 0x0807060504030201;
    float f = 3.14f;
    double d = 3.14;
    long double ld = 3.14L;

    printf("Octets de short :\n");
    print_bytes(&s, sizeof(s));

    printf("Octets de int :\n");
    print_bytes(&i, sizeof(i));

    printf("Octets de long int :\n");
    print_bytes(&l, sizeof(l));

    printf("Octets de float :\n");
    print_bytes(&f, sizeof(f));

    printf("Octets de double :\n");
    print_bytes(&d, sizeof(d));

    printf("Octets de long double :\n");
    print_bytes(&ld, sizeof(ld));

    return 0;
}
