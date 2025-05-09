#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace LoadRessource{
    inline sf::Font loadFont(const std::string& filePath){
        sf::Font font;

        if (!font.loadFromFile(filePath)) {
            std::cerr << "Failed to load font : " << filePath << std::endl;

            return sf::Font();
        }


        return font;
    }
}