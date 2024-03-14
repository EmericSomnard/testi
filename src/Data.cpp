/*
** EPITECH PROJECT, 2024
** B-PDG-300-NCY-3-1-PDGRUSH3-emeric.somnard
** File description:
** Data
*/

#include "Data.hpp"

Data::Data()
{
}

Data::~Data()
{
}


void Data::getoperatork()
{
    struct utsname sysinfo;
    if (uname(&sysinfo) != -1) {
        operatorname = sysinfo.sysname;
        kernelversion = sysinfo.release;
    }
}

void Data::refresh()
{
    host.run();
    user.run();
    getoperatork();
    getram();
}

std::string filterNumbers(const std::string& input) {
    std::string output;
    for (char c : input) {
        if (std::isdigit(c)) {
            output += c;
        }
    }
    return output;
}

std::string Data::getram() {
    std::ifstream meminfo("/proc/meminfo");
    std::string res;
    if (meminfo.is_open()) {
        std::string line;
        for (int i = 0; i < 3 && std::getline(meminfo, line); ++i) {
            res += filterNumbers(line) + "\n";
        }
        meminfo.close();
    }
    return (res);
}

double convertMHztoGHz(double mhz) {
    return mhz / 1000.0;
}

std::string Data::cpuName()
{
    std::ifstream cpuinfo("/proc/cpuinfo");

    if (!cpuinfo.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier cpuinfo." << std::endl;
        return NULL;
    }
    std::string line;
    while (std::getline(cpuinfo, line))
        if (line.find("model name") != std::string::npos) {
            line.erase(0, 13);
            return line;
        }
    return NULL;
}

double Data::cpuFreq()
{
    std::ifstream cpuinfo("/proc/cpuinfo");

    if (!cpuinfo.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier cpuinfo." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(cpuinfo, line)) {
        size_t pos = line.find("cpu MHz");
        if (pos != std::string::npos) {
            double mhzValue = std::stod(line.substr(pos + 10));
            double ghzValue = convertMHztoGHz(mhzValue);
            return ghzValue;
        }
    }
    cpuinfo.close();
    return 0;
}
