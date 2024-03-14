#include "../include/Username.hpp"

Username::Username()
{
    _Name = "";
}

Username::Username(const Username &ref)
{
    *this = ref;
}

Username::Username(Username &ref)
{
    *this = ref;
}

Username::Username(Username *ptr)
{
    if (ptr != NULL)
        *this = *ptr;
}

Username::~Username()
{
}

Username Username::operator=(const Username &ref)
{
    if (&ref != this)
        this->copy(ref);
    return *this;
}

Username Username::operator=(Username &ref)
{
    if (&ref != this)
        this->copy(ref);
    return *this;
}

void Username::copy(Username src)
{
    try {
        _Name = src._Name;
    } catch(...) {
    }
}

int Username::run()
{
    char str[1024];
    int ret = getlogin_r(str, 1024);
    if (0 == ret)
        _Name = str;
    return ret;
}

std::string Username::toString()
{
    return _Name;
}
