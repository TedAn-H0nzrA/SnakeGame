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

        float segmentSize; // Taille de chaque segment
        std::vector<sf::RectangleShape> bodyShape;
        Direction currentDirection;

        bool dirVertical;
        bool dirHorizontal;

        float speed;
        sf::Vector2f velocity;

        bool isCollied;

    public:
        Snake();

        void updateVelocity();
        void move();
        void setDirection(Direction dir);


        void checkCollisionWindow();
        bool getisCollied() const;

        void checkCollisionBody();

        void grow();

        void reset();

        sf::FloatRect getGlobalBounds() const;
        void draw(sf::RenderWindow& window);
};