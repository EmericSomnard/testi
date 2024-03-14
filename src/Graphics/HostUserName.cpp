/*
** EPITECH PROJECT, 2024
** B-PDG-300-NCY-3-1-PDGRUSH3-emeric.somnard
** File description:
** HostUserName
*/

#include "HostUserName.hpp"

bool HostUserName::getHostUserDisplay() const
{
    return _isActive;
}

void HostUserName::setHostUserDisplay(const bool isActive)
{
    _isActive = isActive;
}

void HostUserName::displayHostUserInfo(sf::RenderWindow *win, Data &data)
{
    sf::Text text;
    sf::Text text2;
    sf::Font font;
    Hostname host;
    Username user;
    std::string str = "Host: " + data.host.toString() + "\nUser: " + data.user.toString();
    std::string str2 = "Date + Time: " + data.date.gDate();


    font.loadFromFile("./assets/arial.ttf");
    text.setFont(font);
    text2.setFont(font);
    text.setString(str);
    text2.setString(str2);
    text.setCharacterSize(24);
    text2.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text2.setFillColor(sf::Color::White);
    text.setPosition(100, 100);
    text2.setPosition(100, 150);
    win->draw(text);
    win->draw(text2);
}
