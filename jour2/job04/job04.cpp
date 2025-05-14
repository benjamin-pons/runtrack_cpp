#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
    double vitesseGlisse;  // Vitesse de glisse en m/s
    static std::vector<std::shared_ptr<Pingouin>> tousLesPingouins;  // Vector statique pour tous les pingouins

public:
    Pingouin(std::string nom, double vNage, double vMarche, double vGlisse)
        : Aquatique(vNage), Terrestre(vMarche), nom(nom), vitesseGlisse(vGlisse) {
        tousLesPingouins.push_back(std::make_shared<Pingouin>(*this));  // Ajouter le pingouin au vecteur
    }

    // Calcul du temps de parcours
    double tempsParcours() const {
        double tempsGlisse = 15.0 / vitesseGlisse;  // 15 mètres à glisser
        double tempsMarche1 = 20.0 / vitesseMarche;  // 20 mètres à plat
        double tempsNage = 50.0 / vitesseNage;  // 50 mètres à nager
        double tempsMarche2 = 15.0 / vitesseMarche;  // 15 mètres à plat
        return tempsGlisse + tempsMarche1 + tempsNage + tempsMarche2;
    }

    // Méthode pour afficher les informations d'un pingouin
    void sePresenter() const {
        std::cout << "Bonjour, je suis un pingouin et je m'appelle " << nom << "." << std::endl;
    }

    // Redéfinition de nage et marche
    void nage() override {
        std::cout << nom << " nage à " << vitesseNage << " m/s." << std::endl;
    }

    void marche() override {
        std::cout << nom << " marche à " << vitesseMarche << " m/s." << std::endl;
    }

    // Méthode statique pour afficher les informations de tous les pingouins
    static void afficherTousLesPingouins() {
        for (const auto& p : tousLesPingouins) {
            std::cout << "Pingouin: " << p->nom << " | Temps de parcours: " << p->tempsParcours() << " secondes." << std::endl;
        }
    }

    // Destructeur
    ~Pingouin() {
        // Le destructeur est appelé automatiquement lorsque le shared_ptr sort du scope.
    }
};

// Initialisation du vecteur statique
std::vector<std::shared_ptr<Pingouin>> Pingouin::tousLesPingouins;

int main() {
    Pingouin p1("Pingo", 2.5, 0.8, 3.0);
    Pingouin p2("Pingu", 2.2, 0.7, 2.8);

    p1.sePresenter();
    p1.nage();
    p1.marche();
    std::cout << "Temps de parcours pour Pingo : " << p1.tempsParcours() << " secondes." << std::endl;

    p2.sePresenter();
    p2.nage();
    p2.marche();
    std::cout << "Temps de parcours pour Pingu : " << p2.tempsParcours() << " secondes." << std::endl;

    // Afficher tous les pingouins et leur temps de parcours
    std::cout << "\nListe de tous les pingouins et leur temps de parcours :\n";
    Pingouin::afficherTousLesPingouins();

    return 0;
}
