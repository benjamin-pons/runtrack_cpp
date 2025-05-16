#include <iostream>
#include "Joueur.hpp"

// Constructeurs
Joueur::Joueur() : x(0), y(0), nom("Inconnu") {}

Joueur::Joueur(int posX, int posY) : x(posX), y(posY), nom("Inconnu") {}

Joueur::Joueur(int posX, int posY, const std::string& nomJoueur)
    : x(posX), y(posY), nom(nomJoueur) {}

// Setters utilisant "this"
void Joueur::setX(int newX) {
    this->x = newX;
}

void Joueur::setY(int newY) {
    this->y = newY;
}

void Joueur::setNom(const std::string& nouveauNom) {
    this->nom = nouveauNom;
}

// Getters
int Joueur::getX() const {
    return this->x;
}

int Joueur::getY() const {
    return this->y;
}

std::string Joueur::getNom() const {
    return this->nom;
}

// Autres méthodes
void Joueur::deplacer(int dx, int dy) {
    this->x += dx;
    this->y += dy;
}

void Joueur::afficherPosition() const {
    std::cout << "Nom : " << this->nom
              << " | Position : (" << this->x << ", " << this->y << ")" << std::endl;
}

int main() {
    // Joueur 1 : constructeur par défaut
    Joueur joueur1;
    joueur1.afficherPosition();

    // Modification via setters
    joueur1.setNom("Joueur1");
    joueur1.setX(7);
    joueur1.setY(9);
    joueur1.afficherPosition();

    // Joueur 2 : constructeur avec x et y
    Joueur joueur2(10, 20);
    joueur2.setNom("Joueur2");
    joueur2.afficherPosition();

    // Joueur 3 : constructeur avec x, y et nom
    Joueur joueur3(5, 15, "Alex");
    joueur3.afficherPosition();

    // Déplacement de joueur3
    joueur3.deplacer(-2, 4);
    joueur3.afficherPosition();

    return 0;
}
