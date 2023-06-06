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

    int player_x = player.x;
    int player_y = player.y;

    for (int i = 0; i < NUM_CHUNKS; i++)
    {
        int chunkX, chunkY;

        do
        {
            chunkX = rand() % (MAP_WIDTH - CHUNK_SIZE - 5) + 3;
            chunkY = rand() % (MAP_HEIGHT - CHUNK_SIZE - 5) + 3;
        } while (abs(chunkX - player_x) + abs(chunkY - player_y) < 10);

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
        exit_x = rand() % (MAP_WIDTH - 2) + 1;
        exit_y = rand() % (MAP_HEIGHT - 2) + 1;
    } while (abs(exit_x - player_x) + abs(exit_y - player_y) < 10);

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
