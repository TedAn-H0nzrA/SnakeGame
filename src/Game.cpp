#include "Game.hpp"
#include "Constants.hpp"

Game::Game(): snakeColliedWindow(false),
                gameOverText(Constants::gameOverSize, Constants::gameOverColor),
                scoreText(Constants::scoreSize, Constants::scoreColor),
                isGameOver(false),
                score(0)
{
    window.create(sf::VideoMode(Constants::WIDTH, Constants::HEIGHT), Constants::TITLE, sf::Style::Default);
    window.setFramerateLimit(Constants::FPS);

    gameOverText.setString(Constants::gameOverText);
    gameOverText.setPosition(Constants::WIDTH / 2, Constants::HEIGHT / 2);
    scoreText.setString(Constants::scoreText + std::to_string(score));
    scoreText.setPosition(Constants::WIDTH / 2, 10);
}

void Game::manageEvent(sf::Event& event) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) snake.setDirection(Direction::Up);
            if (event.key.code == sf::Keyboard::Down) snake.setDirection(Direction::Down);
            if (event.key.code == sf::Keyboard::Right) snake.setDirection(Direction::Right);
            if (event.key.code == sf::Keyboard::Left) snake.setDirection(Direction::Left);

            // Debug gameOver
            if (event.key.code == sf::Keyboard::A) isGameOver = true;
        }
    }

    snakeColliedWindow = snake.getIsColliedWindow();
    if (snakeColliedWindow) {
        isGameOver = true;
    }
}

void Game::draw() {
    window.clear(Constants::BACKGROUND);

    // Drawing entity
    food.draw(window);
    snake.draw(window);
    scoreText.draw(window);

    if (isGameOver) gameOverText.draw(window);

    window.display();
}

void Game::update() {
    float deltaTime = clock.restart().asSeconds();
    
    // Ne déplacez le serpent que lorsque suffisamment de temps s'est écoulé
    static float accumulatedTime = 0;
    accumulatedTime += deltaTime;
    
    // Déplacer le serpent à un rythme constant basé sur sa vitesse
    float moveInterval = 1.0f / (Constants::S_speed / Constants::GRID_SIZE);
    
    if (accumulatedTime >= moveInterval) {
        snake.move();
        accumulatedTime = 0;
    }

    // Gestion des collisions
    // Food et Snake
    auto snakeBounds = snake.getGlobalBounds();
    if (food.checkCollision(snakeBounds)) {
        score++;
        scoreText.setString(Constants::scoreText + std::to_string(score));
    }
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        manageEvent(event);
        
        if (!isGameOver) update();

        draw();
    }
}