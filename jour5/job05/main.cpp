#include <iostream>
#include "Etudiant.hpp"

// Implémentation du constructeur
Etudiant::Etudiant(const std::string& nom, const std::string& prenom, int age, int matricule)
    : nom(nom), prenom(prenom), age(age), matricule(matricule) {}

// Méthode pour afficher les informations
void Etudiant::afficherInfos() const {
    std::cout << "Nom : " << nom << "\n"
              << "Prénom : " << prenom << "\n"
              << "Âge : " << age << " ans\n"
              << "Matricule : " << matricule << "\n";
}

int main() {
    // Création d'un étudiant
    Etudiant etu("Durand", "Marie", 20, 123456);
    etu.afficherInfos();

    return 0;
}
