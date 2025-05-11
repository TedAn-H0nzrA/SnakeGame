#pragma once

#include <memory>
#include "Snake.hpp"
#include "Food.hpp"

class BruteForce{
    private:
        std::shared_ptr<Snake> snake;
        std::shared_ptr<Food> food;
        int searchDepth;

        // Evaluation and Algo
        sf::Vector2f simulateMove(Direction dir);
        float evaluateState(std::shared_ptr<Snake> simulatedSnake, int depth);
        std::vector<Direction> directions;

    public:
        BruteForce(std::shared_ptr<Snake> snake, std::shared_ptr<Food> food, int depthSearch);

        // Méthode de recherche
        Direction findBestMove();
};