#include <iostream>

int main() {
    int a, b, produit;

    std::cout << "Entrez le premier nombre : ";
    std::cin >> a;

    std::cout << "Entrez le deuxième nombre : ";
    std::cin >> b;

    produit = a * b;

    std::cout << "Le produit est : " << produit << std::endl;

    return 0;
}
