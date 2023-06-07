#include "./include/rogue.h"

void generatePlayerPosition()
{
    srand(time(NULL));

    while (map[player.y][player.x].filler == WALL)
    {
        player.x = rand() % (MAP_WIDTH - 2) + 1;
        player.y = rand() % (MAP_HEIGHT - 2) + 1;
    }
}