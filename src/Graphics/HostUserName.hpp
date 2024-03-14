/*
** EPITECH PROJECT, 2024
** ù
** File description:
** HostUserName
*/

#ifndef HOSTUSERNAME_HPP_
#define HOSTUSERNAME_HPP_

#include "IDisplay.hpp"
#include "./../../include/Username.hpp"
#include "./../../include/Hostname.hpp"
#include "./../Data.hpp"

class HostUserName {
    public:
        bool getHostUserDisplay() const;
        void setHostUserDisplay(const bool isActive);
        std::string getHostname() const;
        void displayHostUserInfo(sf::RenderWindow *win, Data &data);
    protected:
        bool _isActive = true;
        Hostname _hostData;
        Username _userData;
        Date date;
private:
};

#endif /* !HOSTUSERNAME_HPP_ */
