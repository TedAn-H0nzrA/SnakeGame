#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TextManager{
    private:
        sf::Font font;
        sf::Text text;
        float textSize;
        sf::Color textColor;
        
        void manageText();
        void setOrigin();

    public:
        TextManager(float textSize, sf::Color& textColor);
        void setString(const std::string& str);

        void setPosition(float x, float y);

        void draw(sf::RenderWindow& window);
};