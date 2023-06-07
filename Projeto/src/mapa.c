#include "mapa.h"
#include "player.h"

struct map map[MAP_HEIGHT][MAP_WIDTH];
struct Player player;

void generateMap()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (y == 0 || y == MAP_HEIGHT - 1 || x == 0 || x == MAP_WIDTH - 1)
            {
                map[y][x].filler = WALL;
            }
            else if (y == 1 || y == MAP_HEIGHT - 2 || x == 1 || x == MAP_WIDTH - 2)
            {
                map[y][x].filler = WALL;
            }
            else
            {
                map[y][x].filler = FLOOR;
            }
            
            map[y][x].isVisible = false;
        }
    }
}

void generateChunks() {
    srand(time(NULL));

    for (int i = 0; i < NUM_CHUNKS; i++) {
        int chunkX = rand() % (MAP_WIDTH - CHUNK_SIZE - 5) + 3;
        int chunkY = rand() % (MAP_HEIGHT - CHUNK_SIZE - 5) + 3;

        for (int y = chunkY; y < chunkY + CHUNK_SIZE; y++) {
            for (int x = chunkX; x < chunkX + CHUNK_SIZE; x++) {
                map[y][x].filler = WALL;
            }
        }
    }
}


void generatePlayerPosition()
{
    srand(time(NULL));

    while (map[player.y][player.x].filler == WALL)
    {
        player.x = rand() % (MAP_WIDTH - 2) + 1;
        player.y = rand() % (MAP_HEIGHT - 2) + 1;
    }
}