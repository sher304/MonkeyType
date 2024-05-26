//
// Created by Шермат Эшеров on 24/5/24.
//

#ifndef MONKEYTYPE_DRAWPARTICLES_H
#define MONKEYTYPE_DRAWPARTICLES_H

#endif //MONKEYTYPE_DRAWPARTICLES_H

#include <SFML/Graphics.hpp>
void drawParticles(sf::RenderWindow& window,
                   std::vector<sf::CircleShape>& fg,
                   std::vector<sf::CircleShape>& bg,
                   const bool& stopGame, const bool& loadSavedGame);