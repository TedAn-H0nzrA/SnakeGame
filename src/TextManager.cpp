#include "TextManager.hpp"
#include "LoadRessource.hpp"
#include "Constants.hpp"

TextManager::TextManager(float textSize, sf::Color& textColor): font(LoadRessource::loadFont(Constants::fontPath)),
                                            textSize(textSize),
                                            textColor(textColor)
{
    manageText();
}

void TextManager::manageText() {
    text.setFont(font);
    text.setCharacterSize(textSize);
    text.setFillColor(textColor);
}

void TextManager::setOrigin() {
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin((bounds.left + bounds.width) / 2, (bounds.top + bounds.height) / 2);
}

void TextManager::setString(const std::string& str) {
    text.setString(str);
    setOrigin();
}


void TextManager::setPosition(float x, float y) {
    text.setPosition(x, y);
}

void TextManager::draw(sf::RenderWindow& window) {
    window.draw(text);
}