#include "../inc/Map.h"

void initialize(GRID Oscar[][MAX_MAP_SIZE]){
	srand((unsigned)time(NULL));
	int i=0,j=0;
    for(i = 0; i < 16; i++){
        for(j = 0; j < 16; j++){
            Oscar[i][j].entity=NULL;
			Oscar[i][j].biome = OCEAN;
			Oscar[i][j].resource=NONE;
			Oscar[i][j].visit=0;
			Oscar[i][j].owner=-1;
        }
    }
}

void clear_visit(GRID Oscar[][MAX_MAP_SIZE]){
	int i=0,j=0;
	for (i=0;i<MAX_MAP_SIZE;i++){
		for(j=0;j<MAX_MAP_SIZE;j++){
			Oscar[i][j].visit=0;
		}
	}
}
void world_generator(GRID Oscar[][MAX_MAP_SIZE])
{
	int i=0,j=0;
	initialize(Oscar);
    plain(Oscar);
    /*for(i=0;i<MAX_MAP_SIZE;i++){
    	for(j=0;j<MAX_MAP_SIZE;j++){
    		printf(" %d",Oscar[i][j].biome);
		}
		printf("\n");
	}*/
    mountain(Oscar);
    forest(Oscar);
    tc(Oscar);
}

void plain(GRID Oscar[][MAX_MAP_SIZE]){//???????
    coord set,tmp;
    coord move[8]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
    int i = 0;
    int j = 0;
    while(i <= NOT_WATER_NUM){
        set.x = randomnum(0, MAX_MAP_SIZE);
        set.y = randomnum(0, MAX_MAP_SIZE);
        if(Oscar[set.y][set.x].biome != PLAIN){
            Oscar[set.y][set.x].biome = PLAIN;
            i++;
            for (j=0;j<8;j++){//???????�^?l????
            	tmp=plus(set,move[j]);
                if(Oscar[tmp.y][tmp.x].biome == OCEAN){
                    Oscar[tmp.y][tmp.x].biome = WATER;   
                }
			}
        }
    }
}

void mountain(GRID Oscar[][MAX_MAP_SIZE]){//????s
    coord set;
    int i = 0;
    while(i <= MOUNTAIN_NUM){
        set.x = randomnum(0, MAX_MAP_SIZE);
        set.y = randomnum(0, MAX_MAP_SIZE);
        if(Oscar[set.y][set.x].biome == PLAIN){
            Oscar[set.y][set.x].biome = MOUNTAIN;
            i++;
        }
    }
}



void forest(GRID Oscar[][MAX_MAP_SIZE]){//?????L
    coord set;
    int i = 0;
    while(i <= FOREST_NUM){
        set.x = randomnum(0, MAX_MAP_SIZE);
        set.y = randomnum(0, MAX_MAP_SIZE);
        if(Oscar[set.y][set.x].biome == PLAIN){
            Oscar[set.y][set.x].biome = FOREST;
            i++;
        }
    }
}

void tc(GRID Oscar[][MAX_MAP_SIZE]){
    coord set, tmp;
    short team=0;
    coord move[9]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{0,0}};
    int i = 0;
    int j = 0;
    while(i < PLAYER_NUM){
        set.x = randomnum(0, MAX_MAP_SIZE);
        set.y = randomnum(0, MAX_MAP_SIZE);
        if(Oscar[set.y][set.x].biome == PLAIN){
            for (j=0;j<9;j++){
            	//printf("(%d,%d)\n",set.x,set.y);
            	tmp=plus(set,move[j]);
                if(Oscar[tmp.y][tmp.x].resource == TC){
                    break;   
                }	
                if(j == 8){
                    Oscar[set.y][set.x].resource = TC;
                    Oscar[set.y][set.x].owner=team;
                    team++;
                    i++;
                }
			}            
        }
    }
}
void generate_millitia(GRID Oscar[][MAX_MAP_SIZE],List *table[]){
	int i=0,j=0,team=0;
	for(i=0;i<MAX_MAP_SIZE;i++){
		for(j=0;j<MAX_MAP_SIZE;j++){
			if(Oscar[i][j].resource==TC){
				coord tmp={j,i};
				add_entity(Oscar,table,tmp,MILITIA,team,10,0,2,1,1);
				team+=1;
			}
		}
	}
	
}
int randomnum(int min, int max){
    int r01 = 0, result;
    r01 = (int)(rand()) % max;
    result = r01 + min;
    return result;
}
