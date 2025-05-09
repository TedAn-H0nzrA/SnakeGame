#pragma once

#include <SFML/Graphics.hpp>
#include "Food.hpp"
#include "Snake.hpp"

class Game{
    private:
        sf::RenderWindow window;
        sf::Clock clock;

        // Entity
        Food food;
        Snake snake;

        bool snakeColliedWindow;

    public: 
        Game();

        void manageEvent(sf::Event& events); 
        void draw();

        void update();

        void run();
};