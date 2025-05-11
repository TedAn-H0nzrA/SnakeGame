#include "Snake.hpp"
#include "Constants.hpp"
#include <iostream>

Snake::Snake(): segmentSize(Constants::GRID_SIZE), 
                speed(Constants::GRID_SIZE),
                isCollied(false),
                currentDirection(Direction::Up),
                dirVertical(true),
                dirHorizontal(false)
{
    // Snake headShape
    headShape.setSize(sf::Vector2f(segmentSize, segmentSize));
    headShape.setFillColor(Constants::S_headColor);

    int gridCols = Constants::WIDTH / Constants::GRID_SIZE;
    int gridRows = Constants::HEIGHT / Constants::GRID_SIZE;
    headShape.setPosition(Constants::GRID_SIZE * (gridCols / 2), 
                            Constants::GRID_SIZE * (gridRows / 2));
}

Snake::Snake(const Snake& other): segmentSize(other.segmentSize),
                                    speed(other.speed),
                                    isCollied(other.isCollied),
                                    currentDirection(other.currentDirection),
                                    dirHorizontal(other.dirHorizontal),
                                    dirVertical(other.dirVertical),
                                    velocity(other.velocity),
                                    bodyShape(other.bodyShape),
                                    headShape(other.headShape)
{}

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
    
    if (!isCollied){
        // Movement de chaque segment du serpent
        if (!bodyShape.empty()) {
            for (size_t i = bodyShape.size(); i-- > 1;) {
                bodyShape[i].setPosition(bodyShape[i - 1].getPosition());
            }
            bodyShape[0].setPosition(headShape.getPosition());
        }

        headShape.move(velocity);
        checkCollision();
    }
}

void Snake::grow() {
    sf::RectangleShape newBodySegment;
    newBodySegment.setSize(sf::Vector2f(segmentSize, segmentSize));
    newBodySegment.setFillColor(Constants::S_bodyColor);

    if (bodyShape.empty()) {
        newBodySegment.setPosition(headShape.getPosition());
    } else {
        newBodySegment.setPosition(bodyShape.back().getPosition());
    }

    bodyShape.push_back(newBodySegment);
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

void Snake::checkCollision() {
    sf::Vector2f currentPos = headShape.getPosition();

    if (currentPos.x < 0 || currentPos.x + segmentSize > Constants::WIDTH ||
        currentPos.y < 0 || currentPos.y + segmentSize > Constants::HEIGHT) {
        isCollied = true;
    }
    
    // Collision Body
    for (auto&& segment : bodyShape) {
        if (segment.getGlobalBounds().intersects(headShape.getGlobalBounds())){
            isCollied = true;
        }
    }
}

bool Snake::getIsCollied() const {
    return isCollied;
}

sf::FloatRect Snake::getGlobalBoundsHead() const {
    return headShape.getGlobalBounds();
}

std::vector<sf::FloatRect> Snake::getGlobalBoundsBody() const {
    std::vector<sf::FloatRect> bounds;
    for (auto&& segment : bodyShape) {
        bounds.push_back(segment.getGlobalBounds());
    }

    return bounds;
}

void Snake::reset() {
    isCollied = false;
    velocity = {0, -speed};
    dirVertical = true;
    dirHorizontal = false;
    bodyShape.clear();
    
    int gridCols = Constants::WIDTH / Constants::GRID_SIZE;
    int gridRows = Constants::HEIGHT / Constants::GRID_SIZE;
    headShape.setPosition(Constants::GRID_SIZE * (gridCols / 2), 
                            Constants::GRID_SIZE * (gridRows / 2));
}

sf::Vector2f Snake::getPosition() const {
    return headShape.getPosition();
}

Direction Snake::getDirection() const {
    return currentDirection;
}

void Snake::draw(sf::RenderWindow& window) {
    for (auto&& segment : bodyShape) {
        window.draw(segment);
    }
    window.draw(headShape);
}