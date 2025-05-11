#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Food.hpp"
#include "Snake.hpp"
#include "TextManager.hpp"
#include "BruteForce.hpp"

class Game{
    private:
        sf::RenderWindow window;
        sf::Clock clock;
        TextManager gameOverText;
        TextManager scoreText;
        TextManager snakePosText;

        int score;
        float accumulatedTime;

        // Entity
        std::shared_ptr<Snake> snake;
        std::shared_ptr<Food> food;

        bool snakeCollied;
        bool isStarted;
        bool isGameOver;
        bool isUser;

        // Intilialisation random
        std::random_device rd;
        std::mt19937 gen;
        int maxGridX;
        int maxGridY;
        std::uniform_int_distribution<int> distX;
        std::uniform_int_distribution<int> distY;

        // Ai
        BruteForce ai_bruteForce;
        int searchDepth;
        bool isAI_BF;

        void generateNewFoddPosition();

    public: 
        Game();

        void manageEvent(sf::Event& events); 
        void draw();

        void runBruteForce();

        void update();
        void reset();

        void run();
};