/*
** EPITECH PROJECT, 2024
** B-PDG-300-NCY-3-1-PDGRUSH3-emeric.somnard
** File description:
** CPU
*/

#include "CPU.hpp"

bool CPU::getCpuDisplay() const
{
    return (_isActive);
}

void CPU::setCpuDisplay(const bool isActive)
{
    this->_isActive = isActive;
}

void CPU::displayCpuInfo(sf::RenderWindow *win, Data &data)
{
    sf::Text text;
    sf::Text text2;
    sf::Font font;
    std::string str = data.cpuName() + "\n";
    str += std::to_string(data.cpuFreq());
    std::string str2 = "Model:\n  Freq:";

    font.loadFromFile("./assets/arial.ttf");
    text.setFont(font);
    text2.setFont(font);
    text.setString(str);
    text2.setString(str2);
    text.setCharacterSize(24);
    text2.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text2.setFillColor(sf::Color::White);
    text.setPosition(200, 300);
    text2.setPosition(100, 300);
    win->draw(text);
    win->draw(text2);
}
