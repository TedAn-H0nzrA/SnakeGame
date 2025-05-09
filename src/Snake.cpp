#include "Snake.hpp"
#include "Constants.hpp"

Snake::Snake(): segmentSize(Constants::GRID_SIZE), 
                speed(Constants::GRID_SIZE),
                isColliedWindow(false),
                currentDirection(Direction::Up),
                dirVertical(true),
                dirHorizontal(false)
{
    // Snake headShape
    headShape.setSize(sf::Vector2f(segmentSize, segmentSize));
    headShape.setFillColor(Constants::S_headColor);
    headShape.setPosition(Constants::WIDTH / 2, Constants::HEIGHT / 2);

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
    headShape.move(velocity);
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
    auto headShapeDim = headShape.getGlobalBounds();

    if (headShapeDim.left <= 0 || (headShapeDim.left + headShapeDim.width) >= Constants::WIDTH) {
        isColliedWindow = true;
    } else if (headShapeDim.top <= 0 || (headShapeDim.top + headShapeDim.height) >= Constants::HEIGHT) {
        isColliedWindow = true;
    }
}

bool Snake::getIsColliedWindow() const {
    return isColliedWindow;
}


void Snake::draw(sf::RenderWindow& window) {
    window.draw(headShape);
}