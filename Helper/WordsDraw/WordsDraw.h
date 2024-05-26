//
// Created by Шермат Эшеров on 24/5/24.
//

#ifndef MONKEYTYPE_WORDSDRAW_H
#define MONKEYTYPE_WORDSDRAW_H

#endif //MONKEYTYPE_WORDSDRAW_H

#include <SFML/Graphics.hpp>
#include "../../Extension/TextParameter.h"

void wordsDraw(sf::RenderWindow& window,
               std::vector<TextParameter>& wordsText,
               const std::string& userInputString,
               sf::Text& userInput, const sf::Color& f1, const sf::Color& f2, int& missedCounter,
               const bool& stopGame, const bool& loadSavedGame);