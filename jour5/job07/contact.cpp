#include "Contact.hpp"

// Constructeur paramétré
Contact::Contact(const std::string& nom, int numero)
    : nom(nom), numero(numero) {}

// Constructeur de copie
Contact::Contact(const Contact& autre)
    : nom(autre.nom), numero(autre.numero) {}

// Setter
void Contact::setNumero(int nouveauNumero) {
    this->numero = nouveauNumero;
}

// Affichage
void Contact::afficher() const {
    std::cout << "Nom : " << nom << " | Numéro : " << numero << std::endl;
}
