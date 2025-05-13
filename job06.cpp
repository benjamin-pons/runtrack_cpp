#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list> 

// Classe Aquatique
class Aquatique {
protected:
    double vitesseNage;  

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
    static std::list<std::string> lieuxRencontre;  // Liste statique de lieux de rencontre

public:
    Pingouin(std::string nom, double vNage, double vMarche, double vGlisse)
        : Aquatique(vNage), Terrestre(vMarche), nom(nom), vitesseGlisse(vGlisse) {
        tousLesPingouins.push_back(std::make_shared<Pingouin>(*this));  // Ajouter le pingouin au vecteur
    }

    // Méthode pour insérer un lieu de rencontre
    static void ajouterLieu(const std::string& lieu) {
        lieuxRencontre.push_back(lieu);
    }

    // Méthode pour retirer un lieu de rencontre
    static void retirerLieu(const std::string& lieu) {
        lieuxRencontre.remove(lieu);  // Retirer le lieu de la liste
    }

    // Afficher tous les lieux de rencontre
    static void afficherLieux() {
        std::cout << "Lieux de rencontre disponibles : " << std::endl;
        for (const auto& lieu : lieuxRencontre) {
            std::cout << "- " << lieu << std::endl;
        }
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
std::list<std::string> Pingouin::lieuxRencontre;  // Initialisation de la liste statique

int main() {
    Pingouin p1("Pingo", 2.5, 0.8, 3.0);
    Pingouin p2("Pingu", 2.2, 0.7, 2.8);
    Pingouin p3("Flappy", 2.0, 0.6, 3.5);

    p1.sePresenter();
    p1.nage();
    p1.marche();
    std::cout << "Temps de parcours pour Pingo : " << p1.tempsParcours() << " secondes." << std::endl;

    // Ajouter des lieux de rencontre
    Pingouin::ajouterLieu("Lac");
    Pingouin::ajouterLieu("Glacier");
    Pingouin::ajouterLieu("Forêt");
    Pingouin::ajouterLieu("Plage");

    // Afficher les lieux de rencontre
    Pingouin::afficherLieux();

    // Retirer un lieu de rencontre
    Pingouin::retirerLieu("Forêt");
    std::cout << "\nAprès retrait de Forêt : " << std::endl;
    Pingouin::afficherLieux();

    return 0;
}
