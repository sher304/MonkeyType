//
// Created by Шермат Эшеров on 23/5/24.
//

#ifndef MONKEYTYPE_GAMELOADER_H
#define MONKEYTYPE_GAMELOADER_H

#endif //MONKEYTYPE_GAMELOADER_H

#include <iostream>
#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fstream>
#include <map>
#include "../../Extension/TextParameter.h"

void loadGame(std::vector<TextParameter>& texts,
              int& userScore, sf::Time& time,
              int& correctAttempt, int& generalAttempt,
              int& missedWords, sf::Font& textFont);
