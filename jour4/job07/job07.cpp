#include <iostream>
using namespace std;

int main(){
    int a = 2;
    int b = 5;

    // Tableau de pointeurs vers void (type générique)
    void* tableau[4];

    // Remplissage du tableau
    tableau[0] = &a;
    tableau[1] = &b;

    cout << "Valeur 1 (int): " << *(int*)tableau[0] << " à l'adresse " << tableau[0] << endl;
    cout << "Valeur 2 (int): " << *(int*)tableau[1] << " à l'adresse " << tableau[1] << endl;
}