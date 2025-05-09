#include "Food.hpp"
#include "Constants.hpp"

Food::Food() : radius(Constants::F_radius)
{
    shape.setRadius(radius);
    shape.setFillColor(Constants::F_color);
    shape.setOrigin(radius, radius);

    // Initialisation des random
    gen.seed(rd());
    distX = std::uniform_real_distribution<float>(radius, Constants::WIDTH - radius);
    distY = std::uniform_real_distribution<float>(radius, Constants::HEIGHT - radius);

    setPosition(distX(gen), distY(gen));
}

void Food::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void Food::checkCollision(sf::FloatRect& entity) {
    auto shapeDim = shape.getGlobalBounds();

    if (shapeDim.intersects(entity)) {
        setPosition(distX(gen), distY(gen));
    }
}

void Food::draw(sf::RenderWindow& window) {
    window.draw(shape);
}