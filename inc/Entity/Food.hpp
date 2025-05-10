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
        int maxGridX;
        int maxGridY;
        std::uniform_int_distribution<int> distX;
        std::uniform_int_distribution<int> distY;

    public:
        Food();

        void setPosition(float x, float y);
        bool checkCollision(sf::FloatRect& entity);

        void reset();
        sf::Vector2f getPosition() const;
        void draw(sf::RenderWindow& window);
};