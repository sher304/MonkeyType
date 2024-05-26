//
// Created by Шермат Эшеров on 23/5/24.
//

#ifndef MONKEYTYPE_SAVEGAME_H
#define MONKEYTYPE_SAVEGAME_H
#endif //MONKEYTYPE_SAVEGAME_H

#include <iostream>
#include <vector>
#include <fmt/core.h>
#include "../../Extension/TextParameter.h"

void saveGame(const std::vector<TextParameter>& texts,
              const int& userScore, const int& time,
              const int& correctAttempt, const int& generalAttempt,
              const int& missedWords);
