#include <iostream>

int main() {
    double a, b;
    char operateur;

    std::cout << "Entrez un nombre : ";
    std::cin >> a;

    std::cout << "Entrez un operateur (+, -, *, /) : ";
    std::cin >> operateur;

    std::cout << "Entrez un autre nombre : ";
    std::cin >> b;

    switch(operateur) {
        case '+':
            std::cout << "Résultat : " << a + b << std::endl;
            break;
        case '-':
            std::cout << "Résultat : " << a - b << std::endl;
            break;
        case '*':
            std::cout << "Résultat : " << a * b << std::endl;
            break;
        case '/':
            if (b != 0)
                std::cout << "Résultat : " << a / b << std::endl;
            else
                std::cout << "Erreur : division par zéro !" << std::endl;
            break;
        default:
            std::cout << "Opérateur invalide !" << std::endl;
    }

    return 0;
}
