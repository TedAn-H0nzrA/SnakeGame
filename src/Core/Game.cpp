#include "Game.hpp"
#include "Constants.hpp"
#include <iostream>

Game::Game(): snakeCollied(false),
                gameOverText(Constants::gameOverSize, Constants::gameOverColor),
                scoreText(Constants::scoreSize, Constants::scoreColor),
                snakePosText(Constants::snakePosInfoSize, Constants::snakePosInfoColor),
                isStarted(false),
                isGameOver(false),
                isUser(true),
                score(0), 
                accumulatedTime(0),
                snake(std::make_shared<Snake>()),
                food(std::make_shared<Food>()),
                searchDepth(4),
                ai_bruteForce(snake, food, searchDepth),
                isAI_BF(false)
{
    window.create(sf::VideoMode(Constants::WIDTH, Constants::HEIGHT), Constants::TITLE, sf::Style::Default);
    window.setFramerateLimit(Constants::FPS);

    // Initialisation des random
    gen.seed(rd());
    maxGridX = Constants::WIDTH / Constants::GRID_SIZE - 1;
    maxGridY = Constants::HEIGHT / Constants::GRID_SIZE - 1;
    distX = std::uniform_int_distribution<int>(Constants::F_radius, maxGridX - Constants::F_radius);
    distY = std::uniform_int_distribution<int>(Constants::F_radius, maxGridY - Constants::F_radius);

    gameOverText.setString(Constants::gameOverText);
    gameOverText.setPosition(Constants::WIDTH / 2, Constants::HEIGHT / 2);
    scoreText.setString(Constants::scoreText + std::to_string(score));
    scoreText.setPosition(Constants::WIDTH / 2, 10);

    snakePosText.setString(Constants::snakePosInfo);
    snakePosText.setPosition(Constants::WIDTH / 2, Constants::HEIGHT - 10);

    generateNewFoddPosition();
}

void Game::runBruteForce() {
    Direction bestMove = ai_bruteForce.findBestMove();
    snake->setDirection(bestMove);
}

void Game::manageEvent(sf::Event& event) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        
        // AI & User & Play & Pause
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                isStarted = true;
            }

            if (event.key.code == sf::Keyboard::U) {
                std::cout << "Mode Utilisateur\n";
                isAI_BF = false;
                isUser = true;
            }
            
            // AI
            // BruteForce
            if (event.key.code == sf::Keyboard::B) {
                std::cout << "BruteForce Algorithme\n";
                isAI_BF = true;
                isUser = false;
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) snake->setDirection(Direction::Up);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) snake->setDirection(Direction::Down);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) snake->setDirection(Direction::Right);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) snake->setDirection(Direction::Left);

        // Reset
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) reset();
    }
    
    snakeCollied = snake->getIsCollied();
    if (snakeCollied) {
        isGameOver = true;
    }
}

void Game::generateNewFoddPosition() {
    while (true) {
        int gridX = distX(gen);
        int gridY = distY(gen);
    
        auto newPosX = gridX * Constants::GRID_SIZE + Constants::GRID_SIZE / 2;
        auto newPosY = gridY * Constants::GRID_SIZE + Constants::GRID_SIZE / 2;
        
        food->setPosition(newPosX, newPosY);
        auto snakeBoundsHead = snake->getGlobalBoundsHead();

        // Détection de collision entre serptent et food pour placer food dans les positions qui ne sont pas prise par snake
        if (food->checkCollision(snakeBoundsHead)) continue;

        bool colliedWithBody = false;
        for (auto&& segmentBound : snake->getGlobalBoundsBody()) {
            if (food->checkCollision(segmentBound)) {
                colliedWithBody = true;
                break;
            }
        }

        if (!colliedWithBody) break;
    }
}

void Game::reset() {
    score = 0;
    isGameOver = false;

    snake.reset();
    food.reset();
    // Nouvelle instance
    snake = std::make_shared<Snake>();
    food = std::make_shared<Food>();
    generateNewFoddPosition();

    ai_bruteForce = BruteForce(snake, food, searchDepth);

    scoreText.setString(Constants::scoreText + std::to_string(score));
    snakePosText.setString(Constants::snakePosInfo);
    accumulatedTime = 0;

    isAI_BF = false;
    isUser = true;
    isStarted = false;
}
void Game::draw() {
    window.clear(Constants::BACKGROUND);

    // Drawing entity
    food->draw(window);
    snake->draw(window);
    snakePosText.draw(window);
    scoreText.draw(window);

    if (isGameOver) gameOverText.draw(window);

    window.display();
}

void Game::update() {
    float deltaTime = clock.restart().asSeconds();
    
    // Ne déplacez le serpent que lorsque suffisamment de temps s'est écoulé
    accumulatedTime += deltaTime;
    
    // Déplacer le serpent à un rythme constant basé sur sa vitesse
    float moveInterval = 1.0f / (Constants::S_speed / Constants::GRID_SIZE);
    
    if (accumulatedTime >= moveInterval) {
        if (isAI_BF) {
            ai_bruteForce = BruteForce(snake, food, searchDepth);
            runBruteForce();
        }
        snake->move();
        accumulatedTime = 0;
    }

    // Gestion des collisions
    // Food et Snake
    auto snakeBounds = snake->getGlobalBoundsHead();
    if (food->checkCollision(snakeBounds)) {
        snake->grow();
        score++;
        scoreText.setString(Constants::scoreText + std::to_string(score));

        generateNewFoddPosition();
    }

    // Snake position
    int posX = snake->getPosition().x;
    int posY = snake->getPosition().y;
    snakePosText.setString(Constants::snakePosInfo + std::to_string(posX) + " | " + std::to_string(posY));
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        manageEvent(event);
        
        if (!isGameOver && isStarted) update();
        
        draw();
    }
}