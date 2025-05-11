#include "Food.hpp"
#include "Constants.hpp"

Food::Food() : radius(Constants::F_radius)
{
    shape.setRadius(radius);
    shape.setFillColor(Constants::F_color);
    shape.setOrigin(radius, radius);
}

Food::Food(const Food& other) : radius(other.radius),
                                shape(other.shape)
{}

void Food::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

bool Food::checkCollision(sf::FloatRect& entity) {
    auto shapeDim = shape.getGlobalBounds();

    if (shapeDim.intersects(entity)) {
        return true;
    }

    return false;
}

sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}

void Food::draw(sf::RenderWindow& window) {
    window.draw(shape);
}