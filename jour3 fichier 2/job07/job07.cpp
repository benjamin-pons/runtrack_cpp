#include <iostream>

int main() {
    int a, b;

    std::cout << "Entrez la borne de départ (a) : ";
    std::cin >> a;

    std::cout << "Entrez la borne de fin (b) : ";
    std::cin >> b;

    if (a <= b) {
        for (int i = a; i <= b; i++) {
            std::cout << i << " ";
        }
    } else {
        // Si a > b, on affiche à l'envers
        for (int i = a; i >= b; i--) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
