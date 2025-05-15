#include <stdio.h>

int main() {
    int number = 2019;
    int *ptr = &number;      


    printf("La valeur de number est : %d\n", *ptr);

    return 0;
}
