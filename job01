#include <iostream>
#include <string>

// Classe Aquatique
class Aquatique {
protected:
    double vitesseNage;  // en m/s

public:
    Aquatique(double vNage) : vitesseNage(vNage) {}

    virtual void nage() {
        std::cout << "Je nage à " << vitesseNage << " m/s." << std::endl;
    }

    virtual ~Aquatique() {} // destructeur virtuel
};

// Classe Terrestre
class Terrestre {
protected:
    double vitesseMarche;  // en m/s

public:
    Terrestre(double vMarche) : vitesseMarche(vMarche) {}

    virtual void marche() {
        std::cout << "Je marche à " << vitesseMarche << " m/s." << std::endl;
    }

    virtual ~Terrestre() {} // destructeur virtuel
};

// Classe Pingouin héritant de Aquatique et Terrestre
class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;

public:
    Pingouin(std::string nom, double vNage, double vMarche)
        : Aquatique(vNage), Terrestre(vMarche), nom(nom) {}

    void sePresenter() {
        std::cout << "Bonjour, je suis un pingouin et je m'appelle " << nom << "." << std::endl;
    }

    // Redéfinition possible de nage() et marche() si besoin
    void nage() override {
        std::cout << nom << " nage à " << vitesseNage << " m/s." << std::endl;
    }

    void marche() override {
        std::cout << nom << " marche à " << vitesseMarche << " m/s." << std::endl;
    }
};

int main() {
    Pingouin p("Pingo", 2.5, 0.8);

    p.sePresenter();
    p.nage();
    p.marche();

    return 0;
}
