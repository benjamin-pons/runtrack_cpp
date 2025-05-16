#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>

class Joueur {
private:
    int x;
    int y;

public:
    // Constructeur pour initialiser les positions
    Joueur(int posX, int posY);

    // Méthode pour déplacer le joueur
    void deplacer(int dx, int dy);

    // Méthode pour afficher la position actuelle
    void afficherPosition() const;
};

#endif
