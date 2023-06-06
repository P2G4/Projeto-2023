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
        }
    }
}

void generateChunks()
{
    srand(time(NULL));

    int validExitRangeX = MAP_WIDTH - 2 * CHUNK_SIZE - 3;
    int validExitRangeY = MAP_HEIGHT - 2 * CHUNK_SIZE - 3;

    for (int i = 0; i < NUM_CHUNKS; i++)
    {
        int chunkX = rand() % (validExitRangeX - 3) + CHUNK_SIZE + 2;
        int chunkY = rand() % (validExitRangeY - 3) + CHUNK_SIZE + 2;

        for (int y = chunkY; y < chunkY + CHUNK_SIZE; y++)
        {
            for (int x = chunkX; x < chunkX + CHUNK_SIZE; x++)
            {
                map[y][x].filler = '#';
            }
        }
    }

    int exit_x, exit_y;

    do
    {
        exit_x = rand() % (validExitRangeX - 1) + CHUNK_SIZE + 1;
        exit_y = rand() % (validExitRangeY - 1) + CHUNK_SIZE + 1;
    } while (map[exit_y][exit_x].filler != FLOOR);

    map[exit_y][exit_x].filler = EXIT_CHAR;
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
