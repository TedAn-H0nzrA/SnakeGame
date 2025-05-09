#include "Game.hpp"
#include "Constants.hpp"

Game::Game(): snakeColliedWindow(false)
{
    window.create(Constants::desktop, Constants::TITLE, sf::Style::Default);
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