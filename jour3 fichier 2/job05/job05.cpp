#include <iostream>
#include <string>
#include <cctype>

bool estHeureValide(const std::string& heure) {
    // Vérifie la longueur exacte
    if (heure.length() != 5)
        return false;

    // Vérifie le format XXhXX
    if (!std::isdigit(heure[0]) || !std::isdigit(heure[1]))
        return false;

    if (heure[2] != 'h')
        return false;

    if (!std::isdigit(heure[3]) || !std::isdigit(heure[4]))
        return false;

    // Convertir en entier pour vérifier les limites
    int heures = std::stoi(heure.substr(0, 2));
    int minutes = std::stoi(heure.substr(3, 2));

    return (heures >= 0 && heures <= 23) && (minutes >= 0 && minutes <= 59);
}

int main() {
    std::string saisie;

    std::cout << "Entrez une heure au format XXhXX : ";
    std::cin >> saisie;

    if (estHeureValide(saisie)) {
        std::cout << "Heure valide !" << std::endl;
    } else {
        std::cout << "Format invalide." << std::endl;
    }

    return 0;
}
