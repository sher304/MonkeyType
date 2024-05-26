//
// Created by Шермат Эшеров on 23/5/24.
//

#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "../../Extension/TextParameter.h"

void reloadGame(int& missedCounter, int& userScore,
                int& userGeneralAttempts, int& correctAttempts,
                std::string& userInputString, sf::Text& userInput,
                std::vector<TextParameter>& texts,
                std::vector<sf::CircleShape>& frgParticles, std::vector<sf::CircleShape>& bgparticles) {
    missedCounter = 0;
    userScore = 0;
    userGeneralAttempts = 0;
    correctAttempts = 0;
    userInputString = "";
    userInput.setString("");

    texts.erase(texts.begin(), texts.end());
    frgParticles.erase(frgParticles.begin(), frgParticles.end());
    bgparticles.erase(bgparticles.begin(), bgparticles.end());
}
