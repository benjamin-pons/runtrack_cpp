#include <stdio.h>

int main() {
    int entier = 17;
    float flottant = 3.14;
    double reel = 123.345;
    char caractere[] = "La Plateforme";

    printf("Valeur de entier     : %d\n", entier);
    printf("Adresse de entier    : %p\n\n", (void*)&entier);

    printf("Valeur de flottant   : %.2f\n", flottant);
    printf("Adresse de flottant  : %p\n\n", (void*)&flottant);

    printf("Valeur de reel       : %.3lf\n", reel);
    printf("Adresse de reel      : %p\n\n", (void*)&reel);

    printf("Valeur de caractere  : %s\n", caractere);
    printf("Adresse de caractere : %p\n", (void*)caractere);

    return 0;
}
