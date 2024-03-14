#ifndef _DATE_HPP_
#define _DATE_HPP_

#include "Krell.hpp"
#include <iostream>
#include <unistd.h>

class Date : public Krell::IModule
{
public:
    Date();
    Date(const Date &ref);
    Date(Date &ref);
    Date(Date *ptr);
    ~Date();
    Date operator=(const Date &ref);
    Date operator=(Date &ref);
    void copy(Date src);
    void setName(const std::string &str);
    std::string gDate();
    

    int run();
    std::string toString();
    std::string _Name;
    
private:
};

#endif
