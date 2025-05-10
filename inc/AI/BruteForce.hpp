#pragma once

#include <memory>
#include "Snake.hpp"
#include "Food.hpp"

class BruteForce{
    private:
        std::shared_ptr<Snake> snake;
        std::shared_ptr<Food> food;

    public:
        BruteForce(std::shared_ptr<Snake> snake, std::shared_ptr<Food> food);
};