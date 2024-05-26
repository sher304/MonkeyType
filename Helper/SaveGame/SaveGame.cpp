//
// Created by Шермат Эшеров on 23/5/24.
//

#include <iostream>
#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fstream>
#include <map>
#include "../../Extension/TextParameter.h"

void saveGame(const std::vector<TextParameter>& texts,
              const int& userScore, const int& time,
              const int& correctAttempt, const int& generalAttempt,
              const int& missedWords) {

    // Clear all content of the file, and rewrite it. With fstream
    auto file = std::fstream("../Assets/Data/game.txt", std::ios::out | std::ios::trunc);

    file << "User Score\n";
    file << userScore << "\n";

    file << "Time\n";
    file << time << "\n";

    file << "Correct Attempt\n";
    file << correctAttempt << "\n";

    file << "General Attempt\n";
    file << generalAttempt << "\n";

    file << "Missed Words\n";
    file << missedWords << "\n";

    file << "Words\n";
    for (int i = 0; i < texts.size(); i++) {
        file << texts[i].text.getString().toAnsiString() << " ";
        if (texts[i].text.getFillColor().toInteger() == 4034609151) {
            file << "Yellow" << " ";
        } else if (texts[i].text.getFillColor().toInteger() == 3931395583) {
            file << "Red" << " ";
        } else {
            file << "Green" << " ";
        }
        fmt::println("WORD: {}: X {}, Y {}", texts[i].text.getString().toAnsiString(), texts[i].text.getPosition().x, texts[i].text.getPosition().y);
        file << static_cast<int>(texts[i].text.getPosition().x) << " ";
        file << static_cast<int>(texts[i].text.getPosition().y) << "\n";
    }
    file.close();
}
