#ifndef ROGUE_H
#define ROGUE_H


#define MAP_HEIGHT 40
#define MAP_WIDTH 140
#define NUM_CHUNKS 280
#define CHUNK_SIZE 3
#define PLAYER_CHAR '@'
#define WALL '#'
#define FLOOR '.'
#define EXIT_CHAR '>'
#define MOB_CHAR 'T'
#define FOV_RADIUS 6
#define PLAYER_H

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

struct Player
{
    int x;
    int y;
};
extern struct Player player;

struct Mob
{
    int x;
    int y;
};
extern struct Mob mob;


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

