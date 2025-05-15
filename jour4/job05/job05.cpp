#include <stdio.h>

// Déclaration de la structure Point
struct Point {
    int x;
    int y;
};

int main() {
    // Déclaration d'une variable de type Point
    struct Point p;

    // Déclaration d'un pointeur vers une structure Point
    struct Point *ptr = &p;

    // Modification des membres via le pointeur
    ptr->x = 10;
    ptr->y = 20;


    printf("Coordonnées du point : x = %d, y = %d\n", p.x, p.y);

    return 0;
}
