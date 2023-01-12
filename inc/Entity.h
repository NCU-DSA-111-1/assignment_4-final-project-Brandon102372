#ifndef ENTITY_H
#define ENTITY_H
#include <stdio.h>
#include "Assets.h"
#include "coord.h"
#include "linkedlist.h"
#define ENTITY_TABLE_SIZE 1
void initialize_entity_memory(List * table[]);

void add_entity(GRID world[][MAX_MAP_SIZE],List * table[],coord target,ARMY type,short team,short health,short armor,short attack,short m_count,short a_count);

/*void infantry_move(GRID world[][MAX_SIZE],coord now);

void valid_move(GRID world[][MAX_SIZE],coord current);*/
#endif
