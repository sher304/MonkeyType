//
// Created by Шермат Эшеров on 21/5/24.
//


#include <iostream>
#include <string>
#include <fstream>
#include <fmt/core.h>
#include <fmt/ranges.h>

void saveScore(const int& userScore) {
    auto file = std::fstream("../Assets/Data/score.txt");
    file << userScore;
    file.close();
}
