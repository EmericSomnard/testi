/*
** EPITECH PROJECT, 2024
** B-PDG-300-NCY-3-1-PDGRUSH3-emeric.somnard
** File description:
** IData
*/

#ifndef IDATA_HPP_
#define IDATA_HPP_
#include "./../include/Hostname.hpp"
#include "./../include/Username.hpp"
#include "./../include/Date.hpp"
#include <iostream>
#include <sys/utsname.h>
#include <iostream>
#include <fstream>
#include <string>


class Data {
    public:
        Data();
        ~Data();
        void refresh();
        // Hostname getHost() const {return host;};
        // Username getUser() const {return user;};
        // Ram getRam() const {return ram;};
        // Cpu getCpu() const {return cpu;};
        void getoperatork();
        std::string operatorname;
        std::string kernelversion;
        std::string getram();
        std::string memstock;
        Hostname host;
        Username user;
        Date date;
        std::string cpuName();
        double cpuFreq();
    private:
        // Ram ram;
        // Cpu cpu;
};

#endif /* !IDATA_HPP_ */
