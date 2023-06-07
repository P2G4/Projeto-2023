#ifndef MAP_H
#define MAP_H

#define MAP_HEIGHT 30
#define MAP_WIDTH 150
#define NUM_CHUNKS 30
#define CHUNK_SIZE 6
#define PLAYER_CHAR '@'
#define WALL '#'
#define FLOOR '.'
#define EXIT_CHAR '>'
#define FOV_RADIUS 8

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

struct map
{
    char filler;
    bool isVisible;
};

extern struct map map[MAP_HEIGHT][MAP_WIDTH];

void generateMap();
void generateChunks();
void generatePlayerPosition();
void calculateFOV();

#endif