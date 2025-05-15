#include <iostream>
#include <string>

int main() {
    std::string chaine1, chaine2;

    std::cout << "Entrez la première chaîne : ";
    std::getline(std::cin, chaine1);

    std::cout << "Entrez la deuxième chaîne : ";
    std::getline(std::cin, chaine2);

    if (chaine1 == chaine2) {
        std::cout << "0" << std::endl; // chaînes égales
    } else {
        std::cout << "1" << std::endl; // chaînes différentes
    }

    return 0;
}