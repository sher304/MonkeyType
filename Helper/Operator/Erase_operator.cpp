//
// Created by Шермат Эшеров on 18/5/24.
//

#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>

auto operator--(std::string& word) -> std::string {
    if (word.size() == 0) return "";
    word.erase(word.end()-1);
    return word;
}