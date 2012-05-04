#include <unistd.h>
#include "common.h"

void initncurses()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);

    if (has_colors()) {
        start_color();
        init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
        init_pair(BLACK, COLOR_BLACK, COLOR_WHITE);
        init_pair(RED, COLOR_RED, COLOR_RED);
        init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
        init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
        init_pair(CYAN, COLOR_CYAN, COLOR_CYAN);
        init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
        init_pair(ORANGE, COLOR_YELLOW, COLOR_YELLOW);
        use_default_colors();
    } else {
        fprintf(stderr, "[Error] Your terminal does not support colors.\n");
        endwin();
        exit(1);
    }
}

void quit()
{
    dispfree();
    endwin();
}

int main(int argc, char *argv[])
{
    initncurses();
    dispinit(argv[1]);

    do {
        dispdraw();
    } while (route(getch()));

    quit();
    return 0;
}

