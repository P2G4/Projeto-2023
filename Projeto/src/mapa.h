#ifndef MAP_H
#define MAP_H

#define MAP_HEIGHT 30
#define MAP_WIDTH 150
#define NUM_CHUNKS 30
#define CHUNK_SIZE 6

#include <stdlib.h>
#include <time.h>

struct map {
    char filler;
};

extern struct map map[MAP_HEIGHT][MAP_WIDTH];

void generateMap();
void generateChunks();

#endif