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
    headShape.setOrigin(segmentSize / 2, segmentSize / 2);

    int gridCols = Constants::WIDTH / Constants::GRID_SIZE;
    int gridRows = Constants::HEIGHT / Constants::GRID_SIZE;
    headShape.setPosition(Constants::GRID_SIZE * (gridCols / 2), 
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
    
    if (!isCollied){
        // Movement de chaque segment du serpent
        if (!bodyShape.empty()) {
            for (size_t i = bodyShape.size() - 1; i > 0; i--) {
                bodyShape[i].setPosition(bodyShape[i - 1].getPosition());
            }
            bodyShape[0].setPosition(headShape.getPosition());
        }

        headShape.move(velocity);
        checkCollisionWindow();
        checkCollisionBody();
    }
}

void Snake::grow() {
    sf::RectangleShape newBodySegment;
    newBodySegment.setSize(sf::Vector2f(Constants::S_bodyEdge, Constants::S_bodyEdge));
    newBodySegment.setFillColor(Constants::S_bodyColor);
    newBodySegment.setOrigin(Constants::S_bodyEdge / 2, Constants::S_bodyEdge / 2);

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

void Snake::checkCollisionWindow() {
    sf::Vector2f currentPos = headShape.getPosition();
    float halfSize = segmentSize / 2;

    if (currentPos.x - halfSize <= 0 || currentPos.x + halfSize >= Constants::WIDTH ||
        currentPos.y - halfSize <= 0 || currentPos.y + halfSize >= Constants::HEIGHT) {
        std::cout << "Position snake: " << headShape.getPosition().x << " " << headShape.getPosition().y << std::endl;
        std::cout << "Taille écran: " << Constants::WIDTH << " " << Constants::HEIGHT << std::endl;
        isCollied = true;
    }
}

bool Snake::getisCollied() const {
    return isCollied;
}

void Snake::checkCollisionBody() {
    for (auto&& segment : bodyShape) {
        if (segment.getGlobalBounds().intersects(headShape.getGlobalBounds())){
            isCollied = true;
        }
    }
}

sf::FloatRect Snake::getGlobalBounds() const {
    return headShape.getGlobalBounds();
}

void Snake::reset() {
    bodyShape.clear();
    int gridCols = Constants::WIDTH / Constants::GRID_SIZE;
    int gridRows = Constants::HEIGHT / Constants::GRID_SIZE;
    headShape.setPosition(Constants::GRID_SIZE * (gridCols / 2), 
                            Constants::GRID_SIZE * (gridRows / 2));
}

void Snake::draw(sf::RenderWindow& window) {
    for (auto&& segment : bodyShape) {
        window.draw(segment);
    }
    window.draw(headShape);
}