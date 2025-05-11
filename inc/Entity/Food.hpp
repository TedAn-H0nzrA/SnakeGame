#pragma once

#include <SFML/Graphics.hpp>
#include <random>

class Food{
    private:
        sf::CircleShape shape;
        float radius;

    public:
        Food();
        Food(const Food& other);

        void setPosition(float x, float y);
        bool checkCollision(sf::FloatRect& entity);

        void reset();
        sf::Vector2f getPosition() const;
        void draw(sf::RenderWindow& window);
};