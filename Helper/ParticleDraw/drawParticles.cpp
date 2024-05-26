//
// Created by Шермат Эшеров on 24/5/24.
//

#include <SFML/Graphics.hpp>

void drawParticles(sf::RenderWindow& window,
                   std::vector<sf::CircleShape>& fg,
                   std::vector<sf::CircleShape>& bg,
                   const bool& stopGame, const bool& loadSavedGame) {
    // Drawing Quick Foreground Particles
    for(int i = 0; i < fg.size(); i++) {
        if (fg[i].getPosition().x > window.getSize().x) fg.erase(fg.begin() + i);
        window.draw(fg[i]);
        if (stopGame || loadSavedGame) fg[i].move(0, 0);
        else fg[i].move(5.f, 0);
    }

    // Drawing Background Particles
    for(int i = 0; i < bg.size(); i++) {
        if (bg[i].getPosition().x > window.getSize().x) bg.erase(bg.begin() + i);
        window.draw(bg[i]);
        if (stopGame || loadSavedGame) bg[i].move(0, 0);
        else bg[i].move(1.f, 0);
    }
}