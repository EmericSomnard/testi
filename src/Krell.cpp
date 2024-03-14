#include "../include/Krell.hpp"

std::ostream& operator<<(std::ostream &os, Krell::IModule *ref)
{
    os << ref->toString();
    return os;
}
