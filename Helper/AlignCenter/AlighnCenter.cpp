//
// Created by Шермат Эшеров on 24/5/24.
//

#include "SFML/Graphics.hpp"

// Centering the text, according the window
void aligntCenter(sf::Text& text, const sf::RenderWindow& window) {
    auto center = text.getGlobalBounds().getSize() / 2.f;
    auto localBounds = center + text.getLocalBounds().getPosition();
    auto rounded = sf::Vector2f{ std::round(localBounds.x), std::round(localBounds.y) };
    text.setOrigin(rounded);
    text.setPosition(sf::Vector2f (window.getSize() / 2u));
}