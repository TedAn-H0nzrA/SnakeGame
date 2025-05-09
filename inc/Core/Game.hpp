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
        TextManager snakePosText;

        int score;

        // Entity
        Food food;
        Snake snake;

        bool snakeCollied;
        bool isGameOver;

    public: 
        Game();

        void manageEvent(sf::Event& events); 
        void draw();

        void update();
        void reset();

        void run();
};