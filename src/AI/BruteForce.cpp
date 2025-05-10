#include "BruteForce.hpp"
#include <cmath>
#include <vector>

BruteForce::BruteForce(std::shared_ptr<Snake> snake, std::shared_ptr<Food> food, int depthSearch = 3) :
            snake(snake),
            food(food),
            searchDepth(depthSearch)
{}

sf::Vector2f BruteForce::simulateMove(Direction dir) {
    Snake copy = *snake;
    copy.setDirection(dir);
    copy.move();

    return copy.getPosition();
}

int BruteForce::evaluateState(const Snake& simulatedSnake) {
    if (simulatedSnake.getIsCollied()) return -1000;

    sf::Vector2f head = simulatedSnake.getPosition();
    sf::Vector2f target_food = food->getPosition();

    // Calcule distance du food par rapport à la position du snake actuelle
    int dx = std::abs(head.x - target_food.x);
    int dy = std::abs(head.y - target_food.y);

    return -(dx + dy); //si la distance est petite alors c'est mieux
}

Direction BruteForce::findBestMove() {
    int bestScore = -1000; // Initialisation du meilleur score au plus pire
    Direction bestDirection = snake->getDirection();

    // Reformulation des directions pour pouvoir les parcourir
    std::vector<Direction> directions = {
        Direction::Up,
        Direction::Down,
        Direction::Right,
        Direction::Left,
    };

    // Algorithme BruteForce
    for (auto&& dir : directions) {
        Snake simulatedSnake = *snake;
        simulatedSnake.setDirection(dir);
        simulatedSnake.move();
        int score = evaluateState(simulatedSnake);

        if (score > bestScore) {
            bestScore = score;
            bestDirection = dir;
        }
    }

    return bestDirection;
}