#include "Snake.hpp"
#include "Constants.hpp"

Snake::Snake(): segmentSize(Constants::S_edge * 2), 
                speed(Constants::S_speed),
                isColliedWindow(false)
{
    // Snake headShape
    headShape.setSize(sf::Vector2f(segmentSize, segmentSize));
    headShape.setFillColor(Constants::S_headColor);
    headShape.setPosition(100, 500);

}

void Snake::updateVelocity() {
    velocity.x = speed;
    velocity.y = speed;
}
void Snake::move(float deltaTime) {
    updateVelocity();
    headShape.move(velocity * deltaTime);
    checkCollisionWindow();
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