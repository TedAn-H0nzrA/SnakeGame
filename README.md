# Snake Game avec IA BruteForce

Un jeu Snake classique implémenté en C++ avec SFML, comportant un algorithme d'intelligence artificielle capable de jouer de manière autonome en utilisant la méthode de force brute (A*).

## Table des matières

- [Snake Game avec IA BruteForce](#snake-game-avec-ia-bruteforce)
  - [Table des matières](#table-des-matières)
  - [Aperçu](#aperçu)
  - [Fonctionnalités](#fonctionnalités)
  - [Structure du projet](#structure-du-projet)
  - [Prérequis](#prérequis)
  - [Installation](#installation)
    - [Installation de SFML](#installation-de-sfml)
      - [Sous Linux](#sous-linux)
      - [Sous macOS (avec Homebrew)](#sous-macos-avec-homebrew)
      - [Sous Windows](#sous-windows)
    - [Compilation du projet](#compilation-du-projet)
  - [Comment jouer](#comment-jouer)
    - [Contrôles manuels](#contrôles-manuels)
    - [Objectif](#objectif)
  - [Algorithme BruteForce](#algorithme-bruteforce)
    - [Détails techniques](#détails-techniques)
  - [Personnalisation](#personnalisation)
  - [Contribuer](#contribuer)
    - [Idées d'améliorations](#idées-daméliorations)
  - [Licence](#licence)

## Aperçu

Ce projet est une implémentation du célèbre jeu Snake avec une interface graphique utilisant la bibliothèque SFML. La particularité de cette implémentation est l'ajout d'un algorithme d'intelligence artificielle qui peut prendre le contrôle du serpent pour jouer automatiquement en utilisant l'algorithme A* pour trouver le chemin optimal vers la nourriture.

## Fonctionnalités

- Jeu Snake classique avec contrôles fluides
- Interface graphique avec SFML
- Système de score
- Affichage d'informations (position du serpent, score)
- Mode IA avec algorithme BruteForce/A*
- Contrôle manuel ou automatique (IA)
- Structure orientée objet moderne
- Configuration facile via des constantes

## Structure du projet

```
Snake_Game/
├── CMakeLists.txt        # Configuration CMake
├── src/                  # Code source
│   ├── Core/             # Noyau du jeu
│   │   ├── Game.cpp
│   │   └── main.cpp
│   ├── Entity/           # Entités du jeu
│   │   ├── Food.cpp
│   │   ├── Snake.cpp
│   │   └── BruteForce.cpp
│   ├── Utils/            # Utilitaires
│   │   └── TextManager.cpp
│   └── AI/            # Algo BruteForce
│       └── BruteForce.cpp
├── inc/                  # Fichiers d'en-tête
│   ├── Core/
│   │   └── Game.hpp
│   ├── Entity/
│   │   ├── Food.hpp
│   │   ├── Snake.hpp
│   │   └── BruteForce.hpp
│   ├── Utils/
│   │   ├── Constants.hpp
│   │   ├── LoadRessource.hpp
│   │   └── TextManager.hpp
│   └── AI/            # Algo BruteForce
│       └── BruteForce.cpp
├── font/                 # Polices utilisées
│   └── JetBrainsMono.ttf
└── out/                  # Dossier de sortie pour l'exécutable
```

## Prérequis

- C++17 ou supérieur
- CMake 3.16 ou supérieur
- SFML 2.5 ou supérieur
- Compilateur compatible (GCC, Clang, MSVC)

## Installation

### Installation de SFML

#### Sous Linux

```bash
sudo apt-get install libsfml-dev
```

#### Sous macOS (avec Homebrew)

```bash
brew install sfml
```

#### Sous Windows

Téléchargez SFML depuis le [site officiel](https://www.sfml-dev.org/download.php) et configurez votre environnement en conséquence.

### Compilation du projet

1. Clonez le dépôt:

```bash
git clone https://github.com/TedAn-H0nzrA/SnakeGame.git
cd SnakeGame
```

2. Créez un dossier de build et générez les fichiers de build:

```bash
mkdir build
cd build
cmake ..
```

3. Compilez le projet:

```bash
cmake --build .
```

4. Exécutez le jeu:

```bash
cd ../out
./Snake_Game
```

## Comment jouer

### Contrôles manuels

- **Flèches directionnelles**: Contrôler la direction du serpent
- **Espace**: Réinitialiser le jeu
- **A**: Activer/désactiver l'IA

### Objectif

- Manger autant de nourriture que possible pour faire grandir le serpent et augmenter votre score
- Éviter les collisions avec les murs et avec le corps du serpent
- Essayer de battre le score de l'IA!

## Algorithme BruteForce

L'algorithme BruteForce implémenté utilise l'algorithme de recherche de chemin A* pour trouver le chemin optimal entre la tête du serpent et la nourriture. Voici comment il fonctionne:

1. **Conversion de coordonnées**: Les positions en pixels sont converties en positions de grille pour faciliter les calculs.
2. **Recherche de chemin**: L'algorithme A* utilise une fonction heuristique (distance de Manhattan) pour estimer le coût du chemin restant vers la nourriture.
3. **Évitement d'obstacles**: L'algorithme évite les collisions avec les murs et avec le corps du serpent.
4. **Mise à jour de la direction**: Une fois le chemin trouvé, l'IA met à jour la direction du serpent pour suivre ce chemin.

### Détails techniques

- L'algorithme utilise une file de priorité pour explorer les chemins possibles.
- La distance de Manhattan est utilisée comme heuristique pour estimer la distance restante vers la nourriture.
- Si aucun chemin n'est trouvé (impasse), le serpent continue dans sa direction actuelle.

## Personnalisation

Le jeu peut être facilement personnalisé en modifiant les constantes dans le fichier `Constants.hpp`:

- Taille de la fenêtre
- Couleurs des éléments
- Taille de la grille
- Vitesse du serpent
- Textes affichés
- Polices utilisées

## Contribuer

Les contributions sont les bienvenues! Voici comment vous pouvez contribuer:

1. Fork le projet
2. Créez votre branche de fonctionnalité (`git checkout -b feature/amazing-feature`)
3. Committez vos changements (`git commit -m 'Add some amazing feature'`)
4. Push vers la branche (`git push origin feature/amazing-feature`)
5. Ouvrez une Pull Request

### Idées d'améliorations

- Ajouter des obstacles dans le jeu
- Implémenter différents niveaux de difficulté
- Ajouter des effets sonores et de la musique
- Créer un menu principal
- Implémenter un système de high scores
- Améliorer l'algorithme IA pour qu'il gère mieux les impasses
- Ajouter des bonus spéciaux (vitesse, points supplémentaires, etc.)

## Licence

Ce projet est distribué sous la licence MIT. Voir le fichier `LICENSE` pour plus d'informations.

---

Développé avec par TedAn
