#include <iostream>

int main() {
    int a, b, somme;

    std::cout << "Entrez le premier nombre : ";
    std::cin >> a;

    std::cout << "Entrez le deuxième nombre : ";
    std::cin >> b;

    somme = a + b;

    std::cout << "La somme est : " << somme << std::endl;

    return 0;
}
