#include <SFML/Graphics.hpp>
#include <iostream>
#include <exception>

#include "Game.hpp"

int main() {
    std::cout << "Snake Game!" << std::endl;
    Game game;

    try {
        game.run();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}