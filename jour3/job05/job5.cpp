#include <iostream>

int main() {
    int n;

    std::cout << "Entrez un nombre : ";
    std::cin >> n;

    if (n < 10) {
        std::cout << "Non valide" << std::endl;
    } else if (n <= 20) {
        std::cout << "Valide" << std::endl;
    } else {
        std::cout << "Erreur : trop grand" << std::endl;
    }

    return 0;
}
