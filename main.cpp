#include <iostream>
#include <memory>
#include <string>
#include "controller/gameOfLife.h"
#include "view/consoleView.h"
#include "view/SFMLView.h"

using namespace std;

int main() {
    string configPath = "config.txt";

    cout << "Bienvenue dans le Jeu de la Vie !" << endl;
    cout << "Choisissez le mode d'affichage :" << endl;
    cout << "1. Console" << endl;
    cout << "2. Graphique (SFML)" << endl;
    cout << "Votre choix : ";

    int choice;
    if (!(cin >> choice)) {
        cerr << "Entree invalide." << endl;
        return 1;
    }

    unique_ptr<IView> view;

    if (choice == 1) {
        view = make_unique<ConsoleView>(configPath);
    } else if (choice == 2) {
        view = make_unique<SFMLView>();
    } else {
        cerr << "Choix invalide. Veuillez relancer le programme et choisir 1 ou 2." << endl;
        return 1;
    }

    // Choix de la vitesse
    cout << "\nChoisissez la vitesse de simulation :" << endl;
    cout << "1. Rapide (100ms)" << endl;
    cout << "2. Moyen (500ms)" << endl;
    cout << "3. Lent (1000ms)" << endl;
    cout << "4. Personnalise" << endl;
    cout << "Votre choix : ";

    int speedChoice;
    int delayMs = 500; // Default

    if (cin >> speedChoice) {
        switch (speedChoice) {
            case 1: delayMs = 100; break;
            case 2: delayMs = 500; break;
            case 3: delayMs = 1000; break;
            case 4:
                cout << "Entrez le delai en millisecondes : ";
                if (!(cin >> delayMs) || delayMs < 0) {
                    cout << "Delai invalide, utilisation de 500ms par defaut." << endl;
                    delayMs = 500;
                }
                break;
            default:
                cout << "Choix invalide, utilisation de la vitesse moyenne (500ms)." << endl;
                delayMs = 500;
                break;
        }
    } else {
        cout << "Entree invalide, utilisation de la vitesse moyenne (500ms)." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }

    try {
        GameOfLife game(configPath, move(view));
        game.setDelay(delayMs);
        game.runSimulation();
    } catch (const exception& e) {
        cerr << "Erreur fatale : " << e.what() << endl;
        return 1;
    }

    return 0;
}