#include <iostream>

int main() {
    int a, b, c;

    std::cout << "Entrez le premier nombre : ";
    std::cin >> a;

    std::cout << "Entrez le deuxième nombre : ";
    std::cin >> b;

    std::cout << "Entrez le troisième nombre : ";
    std::cin >> c;

    int max = a;

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    std::cout << "Le plus grand nombre est : " << max << std::endl;

    return 0;
}
