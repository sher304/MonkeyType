//
// Created by Шермат Эшеров on 21/5/24.
//

#include <iostream>
#include <string>
#include <fstream>
#include <fmt/core.h>
#include <fmt/ranges.h>

std::string getScore() {
    auto file = std::fstream("../Assets/Data/score.txt");
    std::string score;
    file >> score;
    file.close();
    return score;
}