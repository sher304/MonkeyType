//
// Created by Шермат Эшеров on 18/5/24.
//

#include <iostream>
#include <fstream>

std::vector<std::string> generatingWords() {
    auto wordsFile = std::fstream("../Assets/Data/popular.txt");
    std::string word;
    std::vector<std::string> wordsData;
    while(wordsFile.is_open()) {
        while (std::getline(wordsFile, word)) {
            // Setting words to map, with points for each word
            if (word.size() < 6) wordsData.push_back(word);
        }
        wordsFile.close();
    }
    wordsFile.close();
    return wordsData;
}


// Get Random Word
std::string getRandomWord(const std::vector<std::string>& wordsData) {
    auto it = wordsData.begin();
    std::advance(it, std::rand() % wordsData.size());
    std::string generatedWord;
    generatedWord += ""+*it;
    return generatedWord;
}