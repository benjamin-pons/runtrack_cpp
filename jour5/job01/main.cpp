#include <iostream>
#include "Joueur.hpp"

// Définition des méthodes de la classe Joueur
Joueur::Joueur(int posX, int posY) {
    x = posX;
    y = posY;
}

void Joueur::deplacer(int dx, int dy) {
    x += dx;
    y += dy;
}

void Joueur::afficherPosition() const {
    std::cout << "Position actuelle du joueur : (" << x << ", " << y << ")" << std::endl;
}

int main() {
    // Instanciation d'un joueur en position (0, 0)
    Joueur joueur(5, 10);

    // Affichage de la position initiale
    joueur.afficherPosition();

    // Déplacement 1
    joueur.deplacer(3, 2);
    joueur.afficherPosition();

    // Déplacement 2
    joueur.deplacer(-1, 4);
    joueur.afficherPosition();

    // Déplacement 3
    joueur.deplacer(0, -3);
    joueur.afficherPosition();

    return 0;
}
