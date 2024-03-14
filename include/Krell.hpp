#ifndef _KRELL_HPP_
#define _KRELL_HPP_

#include <string>

namespace Krell
{
    class IModule
    {
    public:
        virtual ~IModule() {};
        virtual int run() = 0;
        virtual std::string toString() = 0;
    };

    class IDisplay
    {
    };
}

std::ostream& operator<<(std::ostream &os, Krell::IModule *ref);

#endif
