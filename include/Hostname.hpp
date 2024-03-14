#ifndef _HOSTNAME_HPP_
#define _HOSTNAME_HPP_

#include "Krell.hpp"
#include <iostream>
#include <unistd.h>

class Hostname : public Krell::IModule
{
public:
    Hostname();
    Hostname(const Hostname &ref);
    Hostname(Hostname &ref);
    Hostname(Hostname *ptr);
    ~Hostname();
    Hostname operator=(const Hostname &ref);
    Hostname operator=(Hostname &ref);
    void copy(Hostname src);
    void setName(const std::string &str);
    
    int run();
    std::string toString();
    
private:
    std::string _Name;
};

#endif
