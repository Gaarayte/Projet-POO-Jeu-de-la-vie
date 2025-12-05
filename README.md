# 🚀 Projet : Jeu de la Vie (Game of Life)

## 1\. Aperçu du Projet

Ce projet implémente le célèbre automate cellulaire de Conway, le **Jeu de la Vie**, en C++ moderne.

L'application suit une architecture **Modèle-Vue-Contrôleur (MVC)** claire et utilise des patrons de conception comme le **State Pattern** (pour gérer l'état des cellules : vivant/mort) et le **Strategy Pattern** (pour les règles d'évolution).

Deux modes d'affichage sont disponibles :

1.  **Mode Console** : Rendu simple dans le terminal.
2.  **Mode Graphique** : Rendu performant via la librairie **SFML** (Simple and Fast Multimedia Library).

-----

## 2\. Fonctionnalités

  * **Règles Standard** : Implémentation des règles classiques du Jeu de la Vie (B3/S23).
  * **Affichage Dynamique** : Support du rendu dans la console ou via SFML.
  * **Configuration par Fichier** : Lecture des paramètres d'exécution et des états initiaux de la grille via un fichier de configuration (`.txt`).
  * **Journalisation** : Enregistrement de l'état de la simulation (`GameLogger`).

-----

## 3\. Prérequis

Pour compiler et exécuter ce projet, vous devez disposer des éléments suivants :

  * **Compilateur C++** : G++ (version 17 ou supérieure recommandée).
  * **GNU Make** : Pour l'exécution du `Makefile`.
  * **Librairies SFML** :
      * SFML Graphics
      * SFML Window
      * SFML System

### Installation de SFML (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install libsfml-dev
```

-----

## 4\. Compilation et Exécution

### Compilation

Utilisez le `Makefile` inclus pour compiler l'exécutable `start`.

```bash
make
```

### Exécution

L'application attend en argument le chemin d'accès à un fichier de configuration.

```bash
./start
```

#### Exemple de Fichier de Configuration (`config.txt`)

```
20 20
0 0 0 0 0
0 0 1 0 0
0 1 1 1 0
0 0 1 0 0
0 0 0 0 0
... (le reste de la grille)
```

  * **Ligne 1** : Dimensions de la grille (Largeur Hauteur)
  * **Lignes suivantes** : Représentation binaire de l'état initial (1 = Vivant, 0 = Mort).

#### Sélection du Mode d'Affichage

Le mode d'affichage est déterminé par le code source dans `main.cpp` (choix entre `SFMLView` et `ConsoleView`).

-----

## 5\. Structure du Projet

Le projet suit une architecture stricte de dossiers :

```
.
├── controller/
│   ├── gameOfLife.cpp/h  # Logique principale, gère le cycle de vie
│   ├── gameLogger.cpp/h  # Journalisation des états
│   ├── inputParser.cpp/h # Lecture du fichier de configuration
│   └── unitTests.cpp/h   # Fonctions de tests unitaires
├── model/
│   ├── cell.cpp/h        # Représente une seule cellule
│   ├── grid.cpp/h        # Gère l'ensemble des cellules
│   └── rules/
│       ├── ruleStrategy.cpp/h  # Interface des règles (Strategy Pattern)
│       └── rules.cpp/h         # Implémentation des règles de Conway
│   └── state/
│       ├── cellState.cpp/h     # Interface d'état (State Pattern)
│       ├── aliveState.cpp/h    # État Cellule Vivante (Singleton)
│       └── deadState.cpp/h     # État Cellule Morte (Singleton)
├── view/
│    ├── iView.h             # Interface de vue
│    ├── consoleView.cpp/h   # Vue console (implémentation de IView)
│    └── SFMLView.cpp/h      # Vue graphique (implémentation de IView)
│
├── main.cpp                 # Passage entre SFMLView ou ConsoleView
├── config.txt               # FIchier  avec les premières cellules
└── Makefile                 # Compilateur


```

-----

## 6\. Tests Unitaires

Le projet inclut un module de tests unitaires (défini dans `unitTests.cpp`) qui vérifie :

  * Le calcul correct du nombre de voisins vivants.
  * Le parsing correct des fichiers d'entrée (`InputParser`).
  * La validité de l'évolution (test de motifs stables comme le Bloc).

Pour exécuter les tests,
