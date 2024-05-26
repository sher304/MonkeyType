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

void settingTextParameters(int& i, std::vector<TextParameter>& texts,
                           const std::vector<std::string>& vecs,
                           const sf::Font& textFont) {
    // Setting Text Parameter with parameters. Fetching datas from string.
    for (int k = i + 1; k < vecs.size(); k++) {
        if (vecs[k] == "Foreground") break;
        // Taking space index information
        auto spaceToWord = vecs[k].find(" ") + 1;
        auto spaceToColor = vecs[k].find(" ", spaceToWord + 1);
        auto spaceToX = vecs[k].find(" ", spaceToColor + 1);
        auto spaceToY = vecs[k].find(" ", spaceToX + 1);
        // Taking word
        std::string word = vecs[k].substr(0, spaceToWord - 1);
        // Color
        std::string color = vecs[k].substr(spaceToWord, spaceToColor - spaceToWord);
        // X coordinate
        int x = stoi(vecs[k].substr(spaceToColor, spaceToX - spaceToColor));
        // Y coordinate
        int y = stoi(vecs[k].substr(spaceToX, spaceToY - spaceToX));
        // Color
        sf::Color textColor;
        if (color == "Green") textColor = sf::Color(255, 212, 96);
        else if (color == "Yellow") textColor = sf::Color(240, 123, 63);
        else textColor = sf::Color(234, 84, 85);
        //Adding text with parameters to Text
        texts.push_back(TextParameter(word, textFont, textColor, 28, x, y));
    }
}

void loadGame(std::vector<TextParameter>& texts,
              int& userScore, sf::Time& time,
              int& correctAttempt, int& generalAttempt,
              int& missedWords, sf::Font& textFont) {

    texts.erase(texts.begin(), texts.end());
    auto file = std::fstream("../Assets/Data/game.txt");
    std::string line;

    std::vector<std::string> vecs;
    while (std::getline(file, line)) {
        vecs.push_back(line);
    }
    for (int i = 0; i < vecs.size(); i++) {
        if (vecs[i] == "User Score") {
            userScore = std::stoi(vecs[i + 1]);
        } else if (vecs[i] == "Time") {
            time = sf::seconds(std::stoi(vecs[i + 1]));
        } else if (vecs[i] == "Correct Attempt") {
            correctAttempt = std::stoi(vecs[i + 1]);
        } else if (vecs[i] == "General Attempt") {
            generalAttempt = std::stoi(vecs[i + 1]);
        } else if (vecs[i] == "Missed Words") {
            missedWords = std::stoi(vecs[i + 1]);
        } else if (vecs[i] == "Words") {
            settingTextParameters(i, texts, vecs, textFont);
        }
    }
    file.close();
}
