#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
private:
    std::string nom;
    int numero;

public:
    // Constructeur paramétré
    Contact(const std::string& nom, int numero);

    // Constructeur de copie
    Contact(const Contact& autre);

    // Setters
    void setNumero(int nouveauNumero);

    // Méthode d'affichage
    void afficher() const;
};

#endif
