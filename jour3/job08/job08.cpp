#include <iostream>

int main() {
    int a, b;

    std::cout << "Entrez la borne de départ (a) : ";
    std::cin >> a;

    std::cout << "Entrez la borne de fin (b) : ";
    std::cin >> b;

    int i = a;

    if (a <= b) {
        while (i <= b) {
            std::cout << i << " ";
            i++;
        }
    } else {
        while (i >= b) {
            std::cout << i << " ";
            i--;
        }
    }

    std::cout << std::endl;

    return 0;
}
