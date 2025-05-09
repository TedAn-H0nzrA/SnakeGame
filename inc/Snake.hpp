#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

enum class Direction{
    Up,
    Down,
    Right,
    Left,
};

class Snake{
    private:
        sf::RectangleShape headShape;
        sf::RectangleShape bodyShape;

        float segmentSize; // Taille de chaque segment
        std::vector<sf::Vector2f> shape;

        float speed;
        sf::Vector2f velocity;

        bool isColliedWindow;

    public:
        Snake();

        void updateVelocity();
        void move(float deltaTime);

        void checkCollisionWindow();
        bool getIsColliedWindow() const;

        void draw(sf::RenderWindow& window);
};