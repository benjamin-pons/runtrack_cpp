#include <iostream>
#include <string>

// Classe Aquatique
class Aquatique {
protected:
    double vitesseNage;

public:
    Aquatique(double vNage = 0.0) : vitesseNage(vNage) {}

    virtual void nage() const {
        std::cout << "Je nage à " << vitesseNage << " m/s." << std::endl;
    }

    void setVitesseNage(double v) { vitesseNage = v; }

    virtual ~Aquatique() {}
};

// Classe Terrestre
class Terrestre {
protected:
    double vitesseMarche;

public:
    Terrestre(double vMarche = 0.0) : vitesseMarche(vMarche) {}

    virtual void marche() const {
        std::cout << "Je marche à " << vitesseMarche << " m/s." << std::endl;
    }

    void setVitesseMarche(double v) { vitesseMarche = v; }

    virtual ~Terrestre() {}
};

// Classe Pingouin
class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;
    double vitesseGlisse;

public:
    // Constructeur
    Pingouin(std::string nom, double vNage, double vMarche, double vGlisse)
        : Aquatique(vNage), Terrestre(vMarche), nom(nom), vitesseGlisse(vGlisse) {}

    // Constructeur de copie
    Pingouin(const Pingouin& autre)
        : Aquatique(autre.vitesseNage),
          Terrestre(autre.vitesseMarche),
          nom(autre.nom),
          vitesseGlisse(autre.vitesseGlisse) {}

    void presentation() const {
        std::cout << "Bonjour, je suis un pingouin nommé " << nom << "." << std::endl;
    }

    void glisse() const {
        std::cout << "Je glisse à " << vitesseGlisse << " m/s." << std::endl;
    }

    void setVitesseGlisse(double v) { vitesseGlisse = v; }
};

// Fonction principale
int main() {
    Pingouin p1("Pingu", 2.5, 1.0, 3.2);
    p1.presentation();
    p1.nage();
    p1.marche();
    p1.glisse();

    std::cout << "\nCopie de Pingu dans p2 et modification de ses vitesses :\n";
    Pingouin p2 = p1;
    p2.setVitesseNage(1.8);
    p2.setVitesseMarche(0.9);
    p2.setVitesseGlisse(2.7);
    p2.presentation();
    p2.nage();
    p2.marche();
    p2.glisse();

    return 0;
}
