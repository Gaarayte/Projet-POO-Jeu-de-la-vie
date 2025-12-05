#include <iostream>
#include <memory>
#include <string>
#include "controller/gameOfLife.h"
#include "view/ConsoleView.h"
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

    try {
        GameOfLife game(configPath, move(view));
        game.runSimulation();
    } catch (const exception& e) {
        cerr << "Erreur fatale : " << e.what() << endl;
        return 1;
    }

    return 0;
}