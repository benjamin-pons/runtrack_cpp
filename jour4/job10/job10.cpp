#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // pour std::setprecision
using namespace std;

// Structure pour stocker une note
struct Note {
    string nom;
    string prenom;
    float note;
};

// Fonction pour afficher le menu
void afficherMenu() {
    cout << "\n--- Menu ---" << endl;
    cout << "1. Ajouter une note" << endl;
    cout << "2. Afficher la liste des notes" << endl;
    cout << "3. Supprimer une note d'un étudiant" << endl;
    cout << "4. Afficher la moyenne des notes" << endl;
    cout << "5. Quitter" << endl;
    cout << "Choix : ";
}

int main() {
    vector<Note> notes;
    int choix;

    do {
        afficherMenu();
        cin >> choix;
        cin.ignore(); // pour gérer le retour à la ligne

        if (choix == 1) {
            // Ajouter une note
            Note n;
            cout << "Nom : ";
            getline(cin, n.nom);
            cout << "Prénom : ";
            getline(cin, n.prenom);
            cout << "Note : ";
            cin >> n.note;
            cin.ignore();

            notes.push_back(n);
            cout << "Note ajoutée avec succès.\n";

        } else if (choix == 2) {
            // Afficher les notes
            if (notes.empty()) {
                cout << "Aucune note enregistrée.\n";
            } else {
                cout << "\nListe des notes :\n";
                for (size_t i = 0; i < notes.size(); i++) {
                    cout << i + 1 << ". " << notes[i].prenom << " " << notes[i].nom 
                         << " - Note : " << fixed << setprecision(2) << notes[i].note << endl;
                }
            }

        } else if (choix == 3) {
            // Supprimer une note
            string nom, prenom;
            cout << "Nom de l'étudiant à supprimer : ";
            getline(cin, nom);
            cout << "Prénom : ";
            getline(cin, prenom);

            bool supprime = false;
            for (auto it = notes.begin(); it != notes.end(); ++it) {
                if (it->nom == nom && it->prenom == prenom) {
                    notes.erase(it);
                    cout << "Note supprimée avec succès.\n";
                    supprime = true;
                    break;
                }
            }
            if (!supprime) {
                cout << "Étudiant non trouvé.\n";
            }

        } else if (choix == 4) {
            // Calculer la moyenne
            if (notes.empty()) {
                cout << "Aucune note pour calculer la moyenne.\n";
            } else {
                float somme = 0;
                for (const auto& n : notes) {
                    somme += n.note;
                }
                float moyenne = somme / notes.size();
                cout << "Moyenne des notes : " << fixed << setprecision(2) << moyenne << endl;
            }

        } else if (choix == 5) {
            cout << "Au revoir !\n";
        } else {
            cout << "Choix invalide, veuillez réessayer.\n";
        }

    } while (choix != 5);

    return 0;
}
