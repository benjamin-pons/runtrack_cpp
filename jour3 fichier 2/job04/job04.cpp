#include <iostream>
#include <string>

int main() {
    std::string texte;

    std::cout << "Vive La Plateforme ";
    std::getline(std::cin, texte); 

    std::cout << "La chaîne contient " << texte.length() << " caractères." << std::endl;

    return 0;
}
