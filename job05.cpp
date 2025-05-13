# include <iostream>
# include <string>
# include <vector>
# include <memory>
# include <list>
# include <algorithm>  // pour std::sort

class Pingouin {
private:
    std::string nom;
    double vitesseNage;
    double vitesseMarche;
    double vitesseGlisse;

    // --- STATIC MEMBERS ---
    static std::vector<std::shared_ptr<Pingouin>> colony;

public:
    Pingouin(std::string nom, double nage, double marche, double glisse)
        : nom(nom), vitesseNage(nage), vitesseMarche(marche), vitesseGlisse(glisse) {
        auto self = std::make_shared<Pingouin>(*this);
        colony.push_back(self);

        // Tri du vecteur colony par temps de parcours croissant
        std::sort(colony.begin(), colony.end(), [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
            return a->tempsParcours() < b->tempsParcours();
        });
    }

    double tempsParcours() const {
        double t_glisse = 15.0 / vitesseGlisse;
        double t_marche1 = 20.0 / vitesseMarche;
        double t_nage = 50.0 / vitesseNage;
        double t_marche2 = 15.0 / vitesseMarche;
        return t_glisse + t_marche1 + t_nage + t_marche2;
    }

    void sePresenter() const {
        std::cout << nom << " - Temps de parcours : " << tempsParcours() << " s\n";
    }

    static void afficherColonie() {
        std::cout << "\n--- Colonie de pingouins triée ---\n";
        for (const auto& p : colony) {
            p->sePresenter();
        }
    }
};

// Initialisation du vecteur statique
std::vector<std::shared_ptr<Pingouin>> Pingouin::colony;

int main() {
    Pingouin p1("Pingo", 2.5, 0.8, 3.0);
    Pingouin p2("Glacius", 2.0, 0.7, 2.5);
    Pingouin p3("Frosty", 2.8, 0.9, 3.5);

    Pingouin::afficherColonie();
    return 0;
}
