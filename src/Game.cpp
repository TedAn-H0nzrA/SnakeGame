#include "Game.hpp"
#include "Constants.hpp"

Game::Game(): snakeColliedWindow(false),
                gameOverText(Constants::gameOverSize, Constants::gameOverColor),
                scoreText(Constants::scoreSize, Constants::scoreColor)
{
    window.create(Constants::desktop, Constants::TITLE, sf::Style::Default);

    gameOverText.setString(Constants::gameOverText);
    gameOverText.setPosition(Constants::WIDTH / 2, Constants::HEIGHT / 2);
    scoreText.setString(Constants::scoreText);
    scoreText.setPosition(Constants::WIDTH / 2, 10);
}

void Game::manageEvent(sf::Event& event) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
    }

    // snakeColliedWindow = snake.getIsColliedWindow();
    // if (snakeColliedWindow) {
    //     window.close();
    // }
}

void Game::draw() {
    window.clear(Constants::BACKGROUND);

    // Drawing entity
    food.draw(window);
    snake.draw(window);

    gameOverText.draw(window);
    scoreText.draw(window);

    window.display();
}

void Game::update() {
    float deltaTime = clock.restart().asSeconds();
    snake.move(deltaTime);
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        manageEvent(event);
        update();
        draw();
    }
}