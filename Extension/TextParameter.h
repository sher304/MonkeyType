//
// Created by Шермат Эшеров on 18/5/24.
//

#ifndef MONKEYTYPE_TEXTPARAMETER_H
#define MONKEYTYPE_TEXTPARAMETER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>

// Struct of Text with parameters
struct TextParameter {
    sf::Text text;
    sf::Text pointText;

    TextParameter(const std::string& word, const sf::Font& font,
                  const sf::Color& color, const int& size,
                  const int& x, const int& y) {
        text.setString(word);
        text.setFont(font);
        text.setFillColor(color);
        text.setCharacterSize(size);
        text.setPosition(x, y);
    }

    TextParameter(const std::string& word, const std::string& points, const sf::Font& font,
                  const sf::Color& colorWord, const sf::Color& colorPoint, const int& size,
                  const int& x, const int& y) {
        text.setString(word);
        text.setFont(font);
        text.setFillColor(colorWord);
        text.setCharacterSize(size);
        text.setPosition(x, y);

        pointText.setString(points);
        pointText.setFont(font);
        pointText.setFillColor(colorPoint);
        pointText.setCharacterSize(size);
        pointText.setPosition(text.getGlobalBounds().left + text.getGlobalBounds().width + 15.f, text.getPosition().y);

    }

    ~TextParameter(){};

};


#endif //MONKEYTYPE_TEXTPARAMETER_H
