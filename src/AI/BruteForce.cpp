#include "BruteForce.hpp"
#include <cmath>
#include <vector>
#include <limits>
#include <iostream>

BruteForce::BruteForce(std::shared_ptr<Snake> snake, std::shared_ptr<Food> food, int depthSearch = 3) :
            snake(snake),
            food(food),
            searchDepth(depthSearch)
{
    // Reformulation des directions pour pouvoir les parcourir
    directions = {
        Direction::Up,
        Direction::Down,
        Direction::Right,
        Direction::Left,
    };
}

sf::Vector2f BruteForce::simulateMove(Direction dir) {
    Snake copy = *snake;
    copy.setDirection(dir);
    copy.move();

    return copy.getPosition();
}

float BruteForce::evaluateState(std::shared_ptr<Snake> simulatedSnake, int depth) {
    if (depth < 0) return -std::numeric_limits<float>::infinity();

    if (depth == 0 || simulatedSnake->getIsCollied()) {
            sf::Vector2f head = simulatedSnake->getPosition();
            sf::Vector2f target_food = food->getPosition();

            // Calcule distance du food par rapport à la position du snake actuelle
            float dx = head.x - target_food.x;
            float dy = head.y - target_food.y;

            return -std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
    };

    float bestScore = -std::numeric_limits<float>::infinity();

    for (auto&& dir : directions) {
        auto nextSim = std::make_shared<Snake>(*simulatedSnake);
        nextSim->setDirection(dir);
        nextSim->move();

        float score = evaluateState(nextSim, depth - 1);
        bestScore = std::max(score, bestScore);
        std::cout << "Testing dir: " << static_cast<int>(dir) << " at depth: " << depth << "\n";
    }

    return bestScore;

}

Direction BruteForce::findBestMove() {
    float bestScore = -std::numeric_limits<float>::infinity(); // Initialisation du meilleur score au plus pire
    Direction bestDirection = snake->getDirection();

    // Algorithme BruteForce
    for (auto&& dir : directions) {;
        auto simulatedSnake = std::make_shared<Snake>(*snake); 
        simulatedSnake->setDirection(dir);
        simulatedSnake->move();

        float score = evaluateState(simulatedSnake, searchDepth - 1);

        if (score > bestScore) {
            bestScore = score;
            bestDirection = dir;
        }
    }

    return bestDirection;
}