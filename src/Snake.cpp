#include "Snake.hpp"
#include "Constants.hpp"
#include <iostream>

Snake::Snake(): segmentSize(Constants::GRID_SIZE), 
                speed(Constants::GRID_SIZE),
                isColliedWindow(false),
                currentDirection(Direction::Right),
                dirVertical(true),
                dirHorizontal(false)
{
    // Snake headShape
    headShape.setSize(sf::Vector2f(segmentSize, segmentSize));
    headShape.setFillColor(Constants::S_headColor);

    int gridCols = Constants::WIDTH / Constants::GRID_SIZE;
    int gridRows = Constants::HEIGHT / Constants::GRID_SIZE;
    headShape.setPosition(Constants::GRID_SIZE * (gridCols/ 2), 
                            Constants::GRID_SIZE * (gridRows / 2));
}



void Snake::updateVelocity() {
    switch (currentDirection) {
        case Direction::Up:
            velocity = {0, -speed};
            dirVertical = true;
            dirHorizontal = false;  
            break;
            
        case Direction::Down:
            velocity = {0, speed};
            dirVertical = true;
            dirHorizontal = false;
            break;

        case Direction::Right:
            velocity = {speed, 0};
            dirHorizontal = true;
            dirVertical = false;
            break;
        
        case Direction::Left:
            velocity = {-speed, 0};
            dirHorizontal = true;
            dirVertical = false;
            break; 
    }
}
void Snake::move() {
    updateVelocity();
    checkCollisionWindow();

    if (!isColliedWindow) headShape.move(velocity);
}

void Snake::setDirection(Direction dir) {
    switch (dir) {
        case Direction::Up:
            if (!dirVertical) currentDirection = dir;
            break;

        case Direction::Down:
            if (!dirVertical) currentDirection = dir;
            break;
        
        case Direction::Right:
            if (!dirHorizontal) currentDirection = dir;
            break;

        case Direction::Left:
            if (!dirHorizontal) currentDirection = dir;
            break;
    }
}

void Snake::checkCollisionWindow() {
    sf::Vector2f nextPos = headShape.getPosition() + velocity;
    float maxX = Constants::WIDTH - segmentSize;
    float maxY = Constants::HEIGHT - segmentSize;

    if (nextPos.x < 0 || nextPos.x > maxX || nextPos.y < 0 || nextPos.y > maxY) {
        std::cout << "Position snake: " << headShape.getPosition().x << " " << headShape.getPosition().y << std::endl;
        std::cout << "Taille écran: " << Constants::WIDTH << " " << Constants::HEIGHT << std::endl;
        isColliedWindow = true;
    }
}

bool Snake::getIsColliedWindow() const {
    return isColliedWindow;
}

sf::FloatRect Snake::getGlobalBounds() const {
    return headShape.getGlobalBounds();
}

void Snake::draw(sf::RenderWindow& window) {
    window.draw(headShape);
}