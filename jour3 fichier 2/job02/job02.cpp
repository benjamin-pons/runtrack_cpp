#include <iostream>
#include <string>

int main() {
    std::string texte = "vive la plateforme !";
    std::string resultat = "";

    for (char c : texte) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' && c != 'Y') {
            resultat += c;
        }
    }

    std::cout << "Texte sans voyelles : " << resultat << std::endl;

    return 0;
}
