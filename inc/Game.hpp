#pragma once

#include <SFML/Graphics.hpp>
#include "Food.hpp"
#include "Snake.hpp"
#include "TextManager.hpp"

class Game{
    private:
        sf::RenderWindow window;
        sf::Clock clock;
        TextManager gameOverText;
        TextManager scoreText;

        // Entity
        Food food;
        Snake snake;

        bool snakeColliedWindow;

        bool isGameOver;

    public: 
        Game();

        void manageEvent(sf::Event& events); 
        void draw();

        void update();

        void run();
};