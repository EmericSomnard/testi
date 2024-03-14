#include "../include/Krell.hpp"
#include "../include/Hostname.hpp"
#include "../include/Username.hpp"
#include "../include/Textual.hpp"
#include "./Graphics/IDisplay.hpp"
#include "./Graphics/Display.hpp"
#include "Data.hpp"

#include <vector>
#include <cstring>

void print_usage()
{
    std::cout << "USAGE:" << std::endl
              << "    ./GKrellM display" << std::endl << std::endl
              << "DESCRIPTION:" << std::endl
              << "    A simplified GKrellM with two display methods:" << std::endl << std::endl
              << "        - t : open a window with a textual display" << std::endl
              << "        - v : open a window with a visual display" << std::endl << std::endl;
    return;
}

int test_input(int ac, char **av)
{
    for (int indice = 1; indice < ac; indice++) {
        if (av[indice][1] == 'h') {
            print_usage();
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac <= 1) {
        std::cout << "Error: Not enought arguments." << std::endl << std::endl;
        print_usage();
        return (84);
    }
    if (ac >= 3) {
        std::cout << "Error: Too much arguments." << std::endl << std::endl;
        print_usage();
        return (84);
    } if (test_input(ac, av) == 1) {
        return (0);
    }
    std::vector<Krell::IModule*> modules;
    modules.push_back(new Hostname());
    modules.push_back(new Username());
    
    for (std::vector<Krell::IModule*>::iterator iter = modules.begin(); iter != modules.end(); ++iter)
        (*iter)->run();
        
    for (std::vector<Krell::IModule*>::iterator iter = modules.begin(); iter != modules.end(); ++iter)
        std::cout << (*iter) << std::endl;

    if (strcmp(av[1], "t") == 0) {
        Textual();
        return (0);
    }

    if (strcmp(av[1], "v") == 0) {
        Display::display();
        return (0);
    }

    std::cout << "Error: No matching methodes." << std::endl << std::endl;
    print_usage();
    return (84);
}
