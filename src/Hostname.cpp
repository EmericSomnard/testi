#include "../include/Hostname.hpp"

Hostname::Hostname()
{
    _Name = "";
}

Hostname::Hostname(const Hostname &ref)
{
    *this = ref;
}

Hostname::Hostname(Hostname &ref)
{
    *this = ref;
}

Hostname::Hostname(Hostname *ptr)
{
    if (ptr != NULL)
        *this = *ptr;
}

Hostname::~Hostname()
{
}

Hostname Hostname::operator=(const Hostname &ref)
{
    if (&ref != this)
        this->copy(ref);
    return *this;
}

Hostname Hostname::operator=(Hostname &ref)
{
    if (&ref != this)
        this->copy(ref);
    return *this;
}

void Hostname::copy(Hostname src)
{
    try {
        _Name = src._Name;
    } catch(...) {
    }
}

int Hostname::run()
{
    char str[1024];
    int ret = gethostname(str, 1024);
    if (0 == ret)
        _Name = str;
    return ret;
}

std::string Hostname::toString()
{
    return _Name;
}
