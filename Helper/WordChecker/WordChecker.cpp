//
// Created by Шермат Эшеров on 19/5/24.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../../Extension/TextParameter.h"

void wordChecker(bool& check, std::vector<TextParameter>& textData,
                 std::string& userInputString, int& userPoints, int& userAttempt) {
    for (int i = 0; i < textData.size(); i++) {
        sf::Text& text = textData[i].text;
        if (userInputString == text.getString().toAnsiString()) {
            userPoints += text.getString().toAnsiString().size() * 3;
            userAttempt++;
            text.setString("");
            textData.erase(textData.begin() + i);
        }
    }
    userInputString = "";
    check = false;
}
