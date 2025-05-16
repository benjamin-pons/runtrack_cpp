#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <string>

class Joueur {
private:
    int x;
    int y;
    std::string nom;

public:
    // Constructeurs
    Joueur();  // Par défaut
    Joueur(int posX, int posY);  // Avec position
    Joueur(int posX, int posY, const std::string& nomJoueur);  // Avec position + nom

    // Méthodes de manipulation avec "this"
    void setX(int newX);
    void setY(int newY);
    void setNom(const std::string& nouveauNom);

    int getX() const;
    int getY() const;
    std::string getNom() const;

    void deplacer(int dx, int dy);
    void afficherPosition() const;
};

#endif
