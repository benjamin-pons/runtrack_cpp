#include <iostream>

int main() {
    int a, b, n;

    std::cout << "Entrez la borne inférieure (a) : ";
    std::cin >> a;

    std::cout << "Entrez la borne supérieure (b) : ";
    std::cin >> b;

    if (a >= b) {
        std::cout << "Erreur : a doit être inférieur à b." << std::endl;
        return 1; // Sortie du programme avec une erreur
    }

    std::cout << "Entrez un entier : ";
    std::cin >> n;

    if (n >= a && n <= b) {
        std::cout << "GAGNE" << std::endl;
    } else {
        std::cout << "PERDU" << std::endl;
    }

    return 0;
}
