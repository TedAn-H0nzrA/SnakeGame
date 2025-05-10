#include "Food.hpp"
#include "Constants.hpp"

Food::Food() : radius(Constants::F_radius)
{
    shape.setRadius(radius);
    shape.setFillColor(Constants::F_color);
    shape.setOrigin(radius, radius);

    // Initialisation des random
    gen.seed(rd());
    maxGridX = Constants::WIDTH / Constants::GRID_SIZE - 1;
    maxGridY = Constants::HEIGHT / Constants::GRID_SIZE - 1;
    distX = std::uniform_int_distribution<int>(Constants::F_radius, maxGridX - Constants::F_radius);
    distY = std::uniform_int_distribution<int>(Constants::F_radius, maxGridY - Constants::F_radius);

    int gridX = distX(gen);
    int gridY = distY(gen);

    setPosition(gridX * Constants::GRID_SIZE + Constants::GRID_SIZE / 2,
                gridY * Constants::GRID_SIZE + Constants::GRID_SIZE / 2);
}

void Food::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

bool Food::checkCollision(sf::FloatRect& entity) {
    auto shapeDim = shape.getGlobalBounds();

    if (shapeDim.intersects(entity)) {
        int gridX = distX(gen);
        int gridY = distY(gen);

        setPosition(gridX * Constants::GRID_SIZE + Constants::GRID_SIZE / 2,
                    gridY * Constants::GRID_SIZE + Constants::GRID_SIZE / 2);

        return true;
    }

    return false;
}

void Food::reset() {
    int gridX = distX(gen);
    int gridY = distY(gen);

    setPosition(gridX * Constants::GRID_SIZE + Constants::GRID_SIZE / 2,
                gridY * Constants::GRID_SIZE + Constants::GRID_SIZE / 2);
}

sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}

void Food::draw(sf::RenderWindow& window) {
    window.draw(shape);
}