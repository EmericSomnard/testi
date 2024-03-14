/*
** EPITECH PROJECT, 2024
** B-PDG-300-NCY-3-1-PDGRUSH3-emeric.somnard
** File description:
** CPU
*/

#ifndef CPU_HPP_
#define CPU_HPP_
#include "IDisplay.hpp"
#include "./../Data.hpp"
#include <string.h>

class CPU {
    public:
        bool getCpuDisplay() const;
        void setCpuDisplay(const bool isActive);
        void displayCpuInfo(sf::RenderWindow *win, Data &data);
    protected:
        bool _isActive = true;
        // CpuModule data;
    private:
};

#endif /* !CPU_HPP_ */
