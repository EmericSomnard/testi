/*
** EPITECH PROJECT, 2024
** B-PDG-300-NCY-3-1-PDGRUSH3-emeric.somnard
** File description:
** Ram
*/

#ifndef RAM_HPP_
#define RAM_HPP_
#include "IDisplay.hpp"
#include "./../Data.hpp"

class Ram {
    public:
        bool getRamDisplay() const;
        void setRamDisplay(const bool isActive);
        void displayRamInfo(sf::RenderWindow *win, Data &data);
    protected:
        bool _isActive = true;
    private:
};

#endif /* !RAM_HPP_ */
