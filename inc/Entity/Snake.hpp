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
        Snake(const Snake& other);

        void updateVelocity();
        void move();
        void setDirection(Direction dir);


        void checkCollision();
        bool getIsCollied() const;


        void grow();

        void reset();

        sf::Vector2f getPosition() const;
        sf::FloatRect getGlobalBounds() const;
        Direction getDirection() const;

        void draw(sf::RenderWindow& window);
};