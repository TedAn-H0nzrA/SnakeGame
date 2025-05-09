#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace Constants{
    inline float WIDTH = 1280;
    inline float HEIGHT = 720;
    inline constexpr int FPS = 120;
    inline std::string TITLE = "Snake Game";
    inline sf::Color BACKGROUND{30, 30, 40};

    
    // Text manager and display
    inline std::string fontPath = std::string(FONTS_DIR) + "/JetBrainsMono.ttf";
    inline std::string gameOverText = "Game Over Bitch";
    inline constexpr float gameOverSize = 100;
    inline sf::Color gameOverColor{255, 20, 20};
    
    inline std::string scoreText = "Score : ";
    inline constexpr float scoreSize = 20;
    inline sf::Color scoreColor{125, 100, 125};
    
    // Food
    inline constexpr float F_radius = 10;
    inline sf::Color F_color{225, 85, 85};
    
    // Snake
    inline sf::Color S_headColor{100, 255, 100};
    inline sf::Color S_bodyColor{50, 180, 50};
    inline constexpr float S_headEdge = F_radius;
    inline constexpr float S_bodyEdge = (S_headEdge - 2) * 2;
    inline constexpr float S_speed = 200;
    
    // Grille
    const int GRID_SIZE = S_headEdge * 2;
};