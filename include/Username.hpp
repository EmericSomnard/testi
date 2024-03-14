#ifndef _USERNAME_HPP_
#define _USERNAME_HPP_

#include "Krell.hpp"
#include <iostream>
#include <unistd.h>

class Username : public Krell::IModule
{
public:
    Username();
    Username(const Username &ref);
    Username(Username &ref);
    Username(Username *ptr);
    ~Username();
    Username operator=(const Username &ref);
    Username operator=(Username &ref);
    void copy(Username src);
    void setName(const std::string &str);
    
    int run();
    std::string toString();
    
private:
    std::string _Name;
};

#endif
