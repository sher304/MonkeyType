#include <iostream>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Helper/Generator_Word/words_generator.h"
#include "Helper/Operator/erase_operator.h"
#include "Helper/WordChecker/WordChecker.h"
#include "Helper/ScoreSaverReader/gameSave.h"
#include "Extension/TextParameter.h"
#include "Helper/ScoreSaverReader/GameScoreReader.h"
#include "Helper/GameReloader/gameReloader.h"
#include "Helper/SaveGame/saveGame.h"
#include "Helper/GameLoader/gameLoad.h"
#include "Helper/ParticleDraw/drawParticles.h"
#include "Helper/WordsDraw/WordsDraw.h"
#include "Helper/AlignCenter/AlignCenter.h"


int main() {
    // Generate Unique Random Values
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Creating Window
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "MonkeyType");
    window.setFramerateLimit(120);

    //Colors
    sf::Color pointColor(255, 212, 96);
    sf::Color firstStage(240, 123, 63);
    sf::Color lastStage(234, 84, 85);

    // Setting font, fetching from file to the menu
    sf::Font menuFont;
    if (!menuFont.loadFromFile("../Assets/Font/Roboto-Medium.ttf")) {
        return EXIT_FAILURE;
    }

    // Setting font, fetching from file, for Text on the screen
    sf::Font textFont;
    if (!textFont.loadFromFile("../Assets/Font/PoetsenOne-Regular.ttf")) {
        return EXIT_FAILURE;
    }

    // Down Menu
    sf::RectangleShape downMenu;
    downMenu.setFillColor(sf::Color(45, 64, 89));
    downMenu.setSize(sf::Vector2f(window.getSize().x, 80.f));
    downMenu.setPosition(sf::Vector2f (0.f, window.getSize().y - 80));

    // User Input
    sf::Text leftSquare;
    leftSquare.setFont(menuFont);
    leftSquare.setCharacterSize(22);
    leftSquare.setString("[");
    leftSquare.setPosition(15, window.getSize().y - 45);

    sf::Text rightSquare;
    rightSquare.setFont(menuFont);
    rightSquare.setCharacterSize(22);
    rightSquare.setString("]");
    rightSquare.setPosition(200, leftSquare.getPosition().y);

    // User input Text
    std::string userInputString;
    sf::Text userInput;
    userInput.setFont(menuFont);
    userInput.setCharacterSize(22);
    userInput.setPosition(leftSquare.getPosition().x + 10, leftSquare.getPosition().y);

    // Copy, Cut ShortCuts
    std::string userShortcut;

    // Setting Line Parent to be used for each word
    sf::RectangleShape wordsLineParent;
    wordsLineParent.setFillColor(sf::Color::Black);
    wordsLineParent.setSize(sf::Vector2f (window.getSize().x, 40));

    // Sorting Shapes for Words Parents
    std::vector<sf::RectangleShape> wordsLines;
    // Adding shaped to vector
    for (int i = 0; i < window.getSize().y / 60; i++) wordsLines.push_back(wordsLineParent);

    // Stored Words Data
    std::vector<std::string> wordsData = generatingWords();

    // Setting Interval for Clock TO get words
    sf::Clock clock_for_random_words;

    // Last line used
    int lastUsedLine;
    // Storing vector of sf::Text type
    std::vector<TextParameter> wordsText;

    // UserPoints
    int userScore = 0;
    int record = std::stoi(getScore());
    TextParameter pointsText("Score:", "", menuFont, sf::Color::White, pointColor, 28, 15, downMenu.getPosition().y);
    TextParameter recordText("Record:", getScore(), menuFont, sf::Color::White, pointColor, 28, pointsText.text.getPosition().x + 250, pointsText.text.getPosition().y);

    // User Attempts
    int userGeneralAttempts = 0;
    int correctAttempts = 0;
    TextParameter skillsText("Skill:", "", menuFont, sf::Color::White, pointColor, 28, 500, pointsText.pointText.getPosition().y);

    // Particles
    std::vector<sf::CircleShape> backgroundParticles;
    std::vector<sf::CircleShape> foregroundParticles;

    // Missed Counter
    TextParameter missedText("Missed:", "", menuFont, sf::Color::White, pointColor, 28, skillsText.text.getPosition().x, leftSquare.getPosition().y);
    int missedCounter = 0;

    // Timer
    sf::Time loadedTime;
    sf::Clock timerClock;
    TextParameter timeText("Time used:", "", menuFont, sf::Color::White, pointColor, 28, 885, missedText.text.getPosition().y);

    // Check Word Validator
    bool checkWord = false;

    // Stop Game Validator
    bool stopGame = false;

    // Stop Game Text
    sf::Text stopGameText;
    stopGameText.setString("Game Over!");
    stopGameText.setFillColor(lastStage);
    stopGameText.setFont(menuFont);
    stopGameText.setCharacterSize(48);
    aligntCenter(stopGameText, window);
    int stopGameTextY = stopGameText.getPosition().y;
    int stopGameTextX = stopGameText.getPosition().x;

    // Load Previous Game Text
    sf::Text loadGameText;
    loadGameText.setFont(menuFont);
    loadGameText.setCharacterSize(48);
    loadGameText.setString("Load saved game");
    aligntCenter(loadGameText, window);
    int loadGameTextX = loadGameText.getPosition().x;
    int loadGameTextY = loadGameText.getPosition().y;

    // Save Game Subtitle
    sf::Text saveGameTitle;
    saveGameTitle.setString("Save Game Ctr/Command + S");
    saveGameTitle.setFont(menuFont);
    saveGameTitle.setCharacterSize(32);
    aligntCenter(saveGameTitle, window);
    int saveGameTitleX = saveGameTitle.getPosition().x;
    int saveGameTitleY = saveGameTitle.getPosition().y;
    saveGameTitle.setPosition(saveGameTitleX, loadGameTextY + 90);

    // Start Again Subtitle
    sf::Text stopGameRunSubtitle;
    stopGameRunSubtitle.setString("Start again");
    stopGameRunSubtitle.setFont(menuFont);
    stopGameRunSubtitle.setCharacterSize(32);

    // Load Game Validator
    bool loadSavedGame = true;

    // Start game menu
    sf::RectangleShape startGameMenu;
    startGameMenu.setSize(sf::Vector2f (window.getSize().x - 200, window.getSize().y - 200));
    startGameMenu.setFillColor(sf::Color::Black);
    startGameMenu.setOutlineThickness(4);
    startGameMenu.setOutlineColor(pointColor);
    startGameMenu.setPosition(100, 100);

    // Start game Text
    sf::Text startText;
    startText.setFont(menuFont);
    startText.setCharacterSize(48);
    startText.setString("Start");
    aligntCenter(startText, window);
    int startTextX = startText.getPosition().x;
    startText.setPosition(startTextX, loadGameTextY + 120);

    // Main
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Event Holder
            switch (event.type) {
                case sf::Event::Closed:
                    // Close Window
                    window.close();
                case sf::Event::TextEntered:
                    // Text Input
                    if (loadSavedGame || stopGame) break;
                    if (event.text.unicode == '\n') break;
                    userInputString += event.text.unicode, userInput.setString(userInputString);
                case sf::Event::MouseMoved:
                    if (startText.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x),
                                                             static_cast<float>(sf::Mouse::getPosition(window).y))) {
                        startText.setFillColor(firstStage);
                    }  else startText.setFillColor(sf::Color::White);

                    if (loadGameText.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x),
                                                                       static_cast<float>(sf::Mouse::getPosition(window).y))) {
                        loadGameText.setFillColor(firstStage);
                    } else loadGameText.setFillColor(sf::Color::White);

                    if (stopGameRunSubtitle.getGlobalBounds().contains(
                            static_cast<float>(sf::Mouse::getPosition(window).x),
                            static_cast<float>(sf::Mouse::getPosition(window).y))) {
                        stopGameRunSubtitle.setFillColor(firstStage);
                    } else stopGameRunSubtitle.setFillColor(sf::Color::White);
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (startText.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x),
                                                                 static_cast<float>(sf::Mouse::getPosition(
                                                                         window).y))) {
                            loadSavedGame = false;
                        // Resume Game
                        } else if (stopGameRunSubtitle.getGlobalBounds().contains(
                                static_cast<float>(sf::Mouse::getPosition(window).x),
                                static_cast<float>(sf::Mouse::getPosition(window).y)) and stopGame) {
                            // Start again game
                            if (stopGameText.getString() == "Game Over!") {
                                if (record < userScore) saveScore(userScore);
                                // Clear
                                reloadGame(missedCounter, userScore, userGeneralAttempts, correctAttempts,
                                           userInputString, userInput, wordsText, foregroundParticles, backgroundParticles);
                                recordText.pointText.setString(getScore());
                                // Restart timer
                                timerClock.restart();
                            }
                            stopGame = false;
                        } else if (loadGameText.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x),
                                                                        static_cast<float>(sf::Mouse::getPosition(
                                                                                window).y)) and loadSavedGame or stopGame) {
                            // Load Game
                            loadGame(wordsText, userScore, loadedTime, correctAttempts,
                                     userGeneralAttempts, missedCounter, textFont);
                            loadSavedGame = false;
                            stopGame = false;
                        }
                    }
                case sf::Event::KeyPressed:
                    // Pause Game
                    if (loadSavedGame and  sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        // Load Game
                        loadGame(wordsText, userScore, loadedTime, correctAttempts,
                                 userGeneralAttempts, missedCounter, textFont);
                        loadSavedGame = false;
                    }

                    if (loadSavedGame) break;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
                        stopGame = true;
                        stopGameText.setString("Pause!");
                        aligntCenter(stopGameText, window);
                        loadGameText.setPosition(loadGameTextX, loadGameTextY + 50);
                    }
                    // Save
                    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) and sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        stopGame = true;
                        saveGame(wordsText, userScore,
                                 int(timerClock.getElapsedTime().asSeconds()),
                                 correctAttempts, userGeneralAttempts, missedCounter);
                    }
                    if (stopGame) break;
                    // ShortCut Copy Command + C
                    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) and sf::Keyboard::isKeyPressed(sf::Keyboard::C)) userShortcut = userInputString;
                    // ShortCut Cut Command + X
                    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) and sf::Keyboard::isKeyPressed(sf::Keyboard::X)) userShortcut = userInputString, userInputString = "";
                    // ShortCut Paste Command + V
                    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) and sf::Keyboard::isKeyPressed(sf::Keyboard::V)) userInputString = userShortcut;
                    // Send to Check the word
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) checkWord = true, userGeneralAttempts++;
                    // Delete entered letter
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) userInput.setString(--userInputString);
            }
        }

        // Save Score
        if (missedCounter > 1) {
            stopGameText.setString("Game Over!");
            aligntCenter(stopGameText, window);
            if (record < userScore) saveScore(userScore);
            stopGame = true;
        }

        // Getting random word from Vec, by interval for 1 second, setting Text
        if (clock_for_random_words.getElapsedTime().asSeconds() >= 0.9) {
            // Generating New Word
            std::string generatedW = getRandomWord(wordsData);
            // Getting random line, and check if they are same to previous
            int currentLine = wordsLines[rand() % wordsLines.size()].getPosition().y;
            if (currentLine == lastUsedLine) currentLine = wordsLines[rand() % wordsLines.size()].getPosition().y;
            // Setting sf::Text with custom Struct of TextParameter
            TextParameter textParameter(generatedW, textFont, pointColor, 28, -90, currentLine);
            // Setting last used line
            lastUsedLine = currentLine;
            // Background slower particles
            sf::CircleShape circleBGShape(1);
            circleBGShape.setPosition(-90, currentLine - 10);
            // Foreground quick particles
            sf::CircleShape circleFGShape(1);
            circleFGShape.setPosition(-90, currentLine + 60);
            // Pushing new generated Text, Particles
            if (!stopGame and !loadSavedGame) wordsText.push_back(textParameter), backgroundParticles.push_back(circleBGShape), foregroundParticles.push_back(circleFGShape);
                // Reset timer
            clock_for_random_words.restart();
        }
        // Setting Timer
        sf::Time elapsedTime = loadedTime + timerClock.getElapsedTime();
        if (!stopGame and !loadSavedGame) timeText.pointText.setString((std::to_string(static_cast<int>(elapsedTime.asSeconds())) + "s"));
        // Rendering Elements
        window.clear();
        window.draw(downMenu);
        window.draw(leftSquare);
        window.draw(rightSquare);
        // Drawing each words parent shape
        for (int i = 0; i < wordsLines.size(); i++) wordsLines[i].setPosition(0.f, i * 50.f + 30.f), window.draw(wordsLines[i]);
        // Checking Words
        if (checkWord) wordChecker(checkWord, wordsText, userInputString, userScore, correctAttempts);

        // Drawing Particles
        drawParticles(window, foregroundParticles,
                      backgroundParticles, stopGame, loadSavedGame);
        // Drawing Text Words
        wordsDraw(window, wordsText, userInputString, userInput,
                  firstStage, lastStage, missedCounter, stopGame, loadSavedGame);
        // Settings Strings, for every update
        pointsText.pointText.setString(std::to_string(userScore));
        skillsText.pointText.setString(std::to_string(correctAttempts) + " (try: " + std::to_string(userGeneralAttempts) + ")");
        missedText.pointText.setString(std::to_string(missedCounter));
        // Drawing Contents
        window.draw(pointsText.text);
        window.draw(pointsText.pointText);
        // Skill Text
        window.draw(skillsText.text);
        window.draw(skillsText.pointText);
        // Missed Text
        window.draw(missedText.text);
        window.draw(missedText.pointText);
        // Record Text
        window.draw(recordText.text);
        window.draw(recordText.pointText);
        // Time
        window.draw(timeText.text);
        window.draw(timeText.pointText);
        window.draw(userInput);
        // Pause or Stop Game Text
        if (stopGame) {
            window.draw(startGameMenu);
            window.draw(stopGameText);
            window.draw(saveGameTitle);
            window.draw(loadGameText);
            if (stopGameText.getString() == "Game Over!") {
                stopGameRunSubtitle.setString("Start Again");
                aligntCenter(stopGameRunSubtitle, window);
            } else {
                stopGameRunSubtitle.setString("Resume");
                aligntCenter(stopGameRunSubtitle, window);
            }
            stopGameRunSubtitle.setPosition(stopGameRunSubtitle.getPosition().x, saveGameTitleY + 140);
            window.draw(stopGameRunSubtitle);
        }
        if (loadSavedGame) window.draw(startGameMenu), window.draw(startText), loadGameText.setPosition(loadGameTextX, stopGameTextY + 50), window.draw(loadGameText);
        window.display();
    }
    return EXIT_SUCCESS;
}
