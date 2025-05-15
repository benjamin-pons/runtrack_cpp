#include <iostream>
using namespace std;

int main() {
    // Déclaration des valeurs
    int entier = 2019;
    float flottant = 3.14;
    const char* chaine1 = "La Plateforme";
    const char* chaine2 = "Étudiants";

    // Tableau de pointeurs vers void (type générique)
    void* tableau[4];

    // Remplissage du tableau
    tableau[0] = &entier;
    tableau[1] = (void*)chaine1;
    tableau[2] = &flottant;
    tableau[3] = (void*)chaine2;

    // Affichage des valeurs et adresses
    cout << "Valeur 1 (int)        : " << *(int*)tableau[0] << " à l'adresse " << tableau[0] << endl;
    cout << "Valeur 2 (char*)      : " << (char*)tableau[1] << " à l'adresse " << (void*)tableau[1] << endl;
    cout << "Valeur 3 (float)      : " << *(float*)tableau[2] << " à l'adresse " << tableau[2] << endl;
    cout << "Valeur 4 (char*)      : " << (char*)tableau[3] << " à l'adresse " << (void*)tableau[3] << endl;

    return 0;
}
