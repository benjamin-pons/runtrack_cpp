#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
    // Vector statique contenant tous les pingouins
    static std::vector<std::shared_ptr<Pingouin>> tousLesPingouins;

    // Constructeur
    Pingouin(std::string nom, double vNage, double vMarche, double vGlisse)
        : Aquatique(vNage), Terrestre(vMarche), nom(nom), vitesseGlisse(vGlisse) {
        // Ajouter le pingouin au vector lors de sa création
        tousLesPingouins.push_back(std::shared_ptr<Pingouin>(this));
    }

    // Constructeur de copie
    Pingouin(const Pingouin& autre)
        : Aquatique(autre.vitesseNage),
          Terrestre(autre.vitesseMarche),
          nom(autre.nom),
          vitesseGlisse(autre.vitesseGlisse) {
        // Ajouter le pingouin copié au vector
        tousLesPingouins.push_back(std::shared_ptr<Pingouin>(this));
    }

    void presentation() const {
        std::cout << "Bonjour, je suis un pingouin nommé " << nom << "." << std::endl;
    }

    void glisse() const {
        std::cout << "Je glisse à " << vitesseGlisse << " m/s." << std::endl;
    }

    void setVitesseGlisse(double v) { vitesseGlisse = v; }

    ~Pingouin() {
        // Retirer le pingouin du vector lors de sa destruction
        for (auto it = tousLesPingouins.begin(); it != tousLesPingouins.end(); ++it) {
            if (it->get() == this) {
                tousLesPingouins.erase(it);
                break;
            }
        }
    }
};

// Définition du vector statique
std::vector<std::shared_ptr<Pingouin>> Pingouin::tousLesPingouins;

int main() {
    // Créer des pingouins
    {
        auto p1 = std::make_shared<Pingouin>("Pingu", 2.5, 1.0, 3.2);
        p1->presentation();
        p1->nage();
        p1->marche();
        p1->glisse();
    } // p1 est détruit ici

    std::cout << "\nAprès destruction de Pingu :\n";

    // Vérifier les pingouins restants
    std::cout << "Il reste " << Pingouin::tousLesPingouins.size() << " pingouins dans le vector." << std::endl;

    return 0;
}
