#include "../include/Date.hpp"
#include <ctime>

Date::Date()
{
    _Name = "";
}

Date::Date(const Date &ref)
{
    *this = ref;
}

Date::Date(Date &ref)
{
    *this = ref;
}

Date::Date(Date *ptr)
{
    if (ptr != NULL)
        *this = *ptr;
}

Date::~Date()
{
}

Date Date::operator=(const Date &ref)
{
    if (&ref != this)
        this->copy(ref);
    return *this;
}

Date Date::operator=(Date &ref)
{
    if (&ref != this)
        this->copy(ref);
    return *this;
}

void Date::copy(Date src)
{
    try {
        _Name = src._Name;
    } catch(...) {
    }
}

int Date::run()
{
    return 0;
}

std::string Date::gDate()
{
    time_t now = time(0);
    std::string Date = ctime(&now);
    _Name = Date;
    return Date;
}

std::string Date::toString()
{
    return _Name;
}
