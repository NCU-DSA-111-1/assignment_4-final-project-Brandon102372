#ifndef ASSET_H
#define ASSET_H
#include <stdbool.h>
#include "../inc/coord.h"
#define MAX_MAP_SIZE 16
typedef enum{MILITIA}ARMY;
static const char *army_texture[]={" M"};

typedef struct entity{
	coord position;
	ARMY type;
	short team;
	short health;
	short armor;
	short attack;
	short mv_count;
	short at_count;
}Entity;

typedef enum {TC,FRUIT,NONE}RESOURCE;
static const char *res_texture[]={"¡¹","f ","  "};
typedef enum {OCEAN,WATER,PLAIN,FOREST,MOUNTAIN}BIOME;

typedef struct grid{
	Entity *entity;
	RESOURCE resource;
	BIOME biome;
	short visit;
	short owner;
}GRID;
#endif
