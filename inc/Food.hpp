#pragma once

#include <SFML/Graphics.hpp>
#include <random>

class Food{
    private:
        sf::CircleShape shape;
        float radius;

        // Intilialisation random
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_real_distribution<float> distX;
        std::uniform_real_distribution<float> distY;

    public:
        Food();

        void setPosition(float x, float y);
        void checkCollision(sf::FloatRect& entity);

        void draw(sf::RenderWindow& window);
};