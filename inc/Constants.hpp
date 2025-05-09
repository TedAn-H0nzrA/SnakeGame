#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace Constants{
    inline sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    inline float WIDTH = static_cast<float>(desktop.width);
    inline float HEIGHT = static_cast<float>(desktop.height);
    inline std::string TITLE = "Snake Game";
    inline sf::Color BACKGROUND{30, 30, 40};

    // Food
    inline constexpr float F_radius = 10;
    inline sf::Color F_color{225, 85, 85};

    // Snake
    inline sf::Color S_headColor{100, 255, 100};
    inline sf::Color S_bodyColor{50, 180, 50};
    inline constexpr float S_edge = F_radius;

    inline constexpr float S_speed = 200;
};