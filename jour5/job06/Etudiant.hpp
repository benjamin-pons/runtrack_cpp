#ifndef ETUDIANT_HPP
#define ETUDIANT_HPP

#include <string>
#include <iostream>

class Etudiant {
private:
    std::string nom;
    std::string prenom;
    int age;
    int matricule;

public:
    // ✅ Constructeur avec liste d'initialisation
    Etudiant(const std::string& nom, const std::string& prenom, int age, int matricule);

    // ✅ Méthode pour afficher les infos de l'étudiant
    void afficherInfos() const;
};

#endif
