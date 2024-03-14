#include "../include/Textual.hpp"
#include <ncurses.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

Textual::Textual()
{
    bool exitLoop = false;
    
    Data D;
    D.refresh();

    std::string HS_N_S;
    const char *HS_N_C;

    std::string US_N_S;
    const char *US_N_C;

    std::string OP_N_S;
    const char *OP_N_C;

    std::string KE_V_S;
    const char *KE_V_C;

    std::string RAM_S = D.memstock;

    std::stringstream ss(RAM_S);

    std::string RAM_S_1;
    std::string RAM_S_2;
    std::string RAM_S_3;

    const char *RAM_C_1;
    const char *RAM_C_2;
    const char *RAM_C_3;

    timeout(1500);

    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    timeout(1500);

    while (!exitLoop) {
        clear();
        D.refresh();

        HS_N_S = D.host.toString();
        HS_N_C = HS_N_S.c_str();

        US_N_S = D.user.toString();
        US_N_C = US_N_S.c_str();

        OP_N_S = D.operatorname;
        OP_N_C = OP_N_S.c_str();

        KE_V_S = D.kernelversion;
        KE_V_C = KE_V_S.c_str();

        RAM_S = D.memstock;
        std::stringstream ss(RAM_S);

        std::getline(ss, RAM_S_1, '\n');
        std::getline(ss, RAM_S_2, '\n');
        std::getline(ss, RAM_S_3, '\n');

        RAM_C_1 = RAM_S_1.c_str();
        RAM_C_2 = RAM_S_2.c_str();
        RAM_C_3 = RAM_S_3.c_str();

        mvprintw(1, 1, "--- HOSTNAME :");
        mvprintw(1, 16, HS_N_C);

        mvprintw(2, 1, "--- USERNAME :");
        mvprintw(2, 16, US_N_C);

        mvprintw(3, 1, "--- OPERATING SYSTEM :");
        mvprintw(3, 24, OP_N_C);

        mvprintw(4, 1, "--- KERNEL VERSION :");
        mvprintw(4, 22, KE_V_C);

        mvprintw(5, 1, "--- TOTAL :");
        mvprintw(5, 17, RAM_C_1);
        mvprintw(6, 1, "--- FREE :");
        mvprintw(6, 12, RAM_C_2);
        mvprintw(7, 1, "--- AVAILABLE :");
        mvprintw(7, 17, RAM_C_3);

        refresh();

        if (getch() == 'q')
            exitLoop = true;
    }
    endwin();
    return;
}

Textual::~Textual()
{
    return;
}
