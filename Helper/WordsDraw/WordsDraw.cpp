//
// Created by Шермат Эшеров on 24/5/24.
//


#include <SFML/Graphics.hpp>
#include "../../Extension/TextParameter.h"

void wordsDraw(sf::RenderWindow& window,
                   std::vector<TextParameter>& wordsText,
                   const std::string& userInputString,
                   sf::Text& userInput, const sf::Color& f1, const sf::Color& f2, int& missedCounter,
                   const bool& stopGame, const bool& loadSavedGame) {
    for (int i = 0; i < wordsText.size(); i++) {
        sf::Text &text = wordsText[i].text;
        if (text.getPosition().x > window.getSize().x / 2) text.setFillColor(f1);
        if (text.getPosition().x > window.getSize().x / 1.4) text.setFillColor(f2);
        if (text.getPosition().x > window.getSize().x) wordsText.erase(wordsText.begin() + i), missedCounter++;
        userInput.setString(userInputString);
        window.draw(text);
        if (stopGame || loadSavedGame) text.move(0, 0);
        else text.move(0.5f, 0);
    }
}