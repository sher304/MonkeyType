//
// Created by Шермат Эшеров on 23/5/24.
//

#ifndef MONKEYTYPE_GAMERELOADER_H
#define MONKEYTYPE_GAMERELOADER_H

#endif //MONKEYTYPE_GAMERELOADER_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "../../Extension/TextParameter.h"

void reloadGame(int& missedCounter, int& userScore,
                int& userGeneralAttempts, int& correctAttempts,
                std::string& userInputString, sf::Text& userInput,
                std::vector<TextParameter>& texts,
                std::vector<sf::CircleShape>& frgParticles, std::vector<sf::CircleShape>& bgparticles);