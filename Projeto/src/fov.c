#include "mapa.h"
#include "player.h"

void calculateFOV()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            int dx = x - player.x;
            int dy = y - player.y;
            double distance = sqrt(dx * dx + dy * dy);

            if (distance <= FOV_RADIUS)
            {
                bool obstacle = false;
                for (int i = 1; i <= distance; i++)
                {
                    int px = player.x + dx * i / distance;
                    int py = player.y + dy * i / distance;

                    if (map[py][px].filler == WALL)
                    {
                        obstacle = true;
                        break;
                    }
                }

                if (!obstacle)
                {
                    map[y][x].isVisible = true;
                }
                else
                {
                    map[y][x].isVisible = true;
                }
            }
            else
            {
                map[y][x].isVisible = false;
            }
        }
    }
}