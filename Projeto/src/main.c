#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "mapa.h"
#include "player.h"

int main() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    WINDOW *window = newwin(MAP_HEIGHT, MAP_WIDTH, 5, 30);
    player.x = MAP_WIDTH / 2;
    player.y = MAP_HEIGHT / 2;

    generateMap();
    generateChunks();

    map[player.y][player.x].filler = '@';

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            mvwprintw(window, y, x, "%c", map[y][x].filler);
        }
    }

    refresh();
    wrefresh(window);

    int ch;
    while ((ch = getch()) != 'q') {
        map[player.y][player.x].filler = '.';

        int new_player_x = player.x;
        int new_player_y = player.y;

        switch (ch) {
            case KEY_UP:
                new_player_y = player.y - 1;
                break;
            case KEY_DOWN:
                new_player_y = player.y + 1;
                break;
            case KEY_LEFT:
                new_player_x = player.x - 1;
                break;
            case KEY_RIGHT:
                new_player_x = player.x + 1;
                break;
        }

        if (map[new_player_y][new_player_x].filler != '#') {
            player.x = new_player_x;
            player.y = new_player_y;
        }

        map[player.y][player.x].filler = '@';

        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                mvwprintw(window, y, x, "%c", map[y][x].filler);
            }
        }

        refresh();
        wrefresh(window);
    }

    endwin();
    return 0;
}
