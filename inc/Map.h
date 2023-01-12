#ifndef MAP_H
#define MAP_H
#include "Assets.h"
#include "Entity.h"
#include "coord.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define OCEAN_NUM 16
#define FOREST_NUM 16
#define MOUNTAIN_NUM 16
#define NOT_WATER_NUM 150
#define FOREST_MOV 2
#define MOUNTAIN_MOV 2
#define PLAIN_MOV 2

void initialize(GRID Oscar[][MAX_MAP_SIZE]);
void world_generator(GRID Oscar[][MAX_MAP_SIZE]);
void plain(GRID Oscar[][MAX_MAP_SIZE]);
void mountain(GRID Oscar[][MAX_MAP_SIZE]);
void forest(GRID Oscar[][MAX_MAP_SIZE]);
int randomnum(int min, int max);
void clear_visit(GRID Oscar[][MAX_MAP_SIZE]);
void tc(GRID Oscar[][MAX_MAP_SIZE]);
#endif
