#include <stdio.h>

int main() {
    int a = 2;
    int b = 5;

    int *ptrA = &a;
    int *ptrB = &b;


    printf("Avant : a = %d, b = %d\n", a, b);

    // Échange des valeurs
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;


    printf("Après : a = %d, b = %d\n", a, b);

    return 0;
}
