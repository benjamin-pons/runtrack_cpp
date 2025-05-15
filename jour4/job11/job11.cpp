#include <iostream>
#include <string>

using namespace std;

int main() {
    // Tableau statique avec 5 fruits
    string fruit[5] = {"Pomme", "Banane", "Fraise", "Mangue", "Raisin"};

    // Afficher le tableau fruit
    cout << "Liste des fruits disponibles :\n";
    for (int i = 0; i < 5; ++i) {
        cout << "- " << fruit[i] << endl;
    }

    // Demander le nombre de fruits préférés
    int nbFavoris;
    cout << "\nCombien de fruits préférez-vous ? ";
    cin >> nbFavoris;
    cin.ignore(); // Pour consommer le retour à la ligne

    // Allocation dynamique pour le tableau favoris
    string* favoris = new string[nbFavoris];

    // Remplissage du tableau favoris
    for (int i = 0; i < nbFavoris; ++i) {
        cout << "Entrez le fruit préféré #" << i + 1 << " : ";
        getline(cin, favoris[i]);
    }

    // Affichage du tableau favoris
    cout << "\nVos fruits favoris sont :\n";
    for (int i = 0; i < nbFavoris; ++i) {
        cout << "- " << favoris[i] << endl;
    }

    // Libération de la mémoire
    delete[] favoris;

    return 0;
}
