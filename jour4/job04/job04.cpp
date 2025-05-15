#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    int *ptrA = &a;
    int *ptrB = &b;
    int *ptrC = &c;

    printf("Valeurs initiales :\n");
    printf("a = %d, b = %d, c = %d\n", *ptrA, *ptrB, *ptrC);


    *ptrA = 100;
    *ptrB = 200;
    *ptrC = 300;

    printf("Valeurs modifiées :\n");
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
