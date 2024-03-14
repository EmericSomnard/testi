/*
** EPITECH PROJECT, 2024
** B-PDG-300-NCY-3-1-PDGRUSH3-emeric.somnard
** File description:
** Ram
*/

#include "Ram.hpp"


bool Ram::getRamDisplay() const
{
    return (_isActive);
}

void Ram::setRamDisplay(const bool isActive)
{
    this->_isActive = isActive;
}

void Ram::displayRamInfo(sf::RenderWindow *win, Data &data)
{
    sf::Text text;
    sf::Text text2;
    sf::Font font;
    std::string str = data.getram();
    std::string str2 = "      Total:\n       Free:\nAvailable:";
    font.loadFromFile("./assets/arial.ttf");
    text.setFont(font);
    text2.setFont(font);
    text.setString(str);
    text2.setString(str2);
    text.setCharacterSize(24);
    text2.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text2.setFillColor(sf::Color::White);
    text.setPosition(220, 200);
    text2.setPosition(100, 200);
    win->draw(text);
    win->draw(text2);
}
