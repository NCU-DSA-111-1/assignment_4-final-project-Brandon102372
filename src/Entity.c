#include "../inc/Entity.h"

void initialize_entity_memory(List * table[]){
	int i=0;
	for(i=0;i<ENTITY_TABLE_SIZE;i++){
		table[i]=makelist();
	}
}

void add_entity(GRID world[][MAX_MAP_SIZE],List * table[],coord target,ARMY type,short team,short health,short armor,short attack,short m_count,short a_count){
	Entity e;
	e.position=target;
	e.type=type;
	e.team=team;
	e.health=health;
	e.armor=armor;
	e.attack=attack;
	e.mv_count=m_count;
	e.at_count=a_count;
	world[target.y][target.x].entity=add(e,table[type]);
}

void infantry_move(GRID world[][MAX_MAP_SIZE],coord now){
	coord move[8]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
	int i=0;
	coord tmp;
	for (i=0;i<8;i++){
		tmp=plus(now,move[i]);
		if(world[tmp.y][tmp.x].entity == NULL){
			world[tmp.y][tmp.x].visit=1;
		}
	}
}

bool melee_attack(GRID world[][MAX_MAP_SIZE],coord now){
	coord move[8]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
	int i=0;
	bool enemy=false;
	coord tmp;
	for (i=0;i<8;i++){
		tmp=plus(now,move[i]);
		Entity *attacker=world[now.y][now.x].entity, *defender=world[tmp.y][tmp.x].entity;
		if(defender!=NULL && attacker->team!=defender->team){
			world[tmp.y][tmp.x].visit=-1;
			enemy=true;
		}
	}
	return enemy;
}


void valid_move(GRID world[][MAX_MAP_SIZE],coord current){
	ARMY a=world[current.y][current.x].entity->type;
	switch(a){
		case MILITIA :
			infantry_move(world,current);
			break;
		default:
			break;
	}
}

bool valid_attack(GRID world[][MAX_MAP_SIZE],coord current){
	bool enemy=false;
	switch(world[current.y][current.x].entity->type){
		case MILITIA:
			enemy=melee_attack(world,current);
			break;
		default:
			break;
	}
	return enemy;
}

void move(GRID world[][MAX_MAP_SIZE],coord start,coord end){
	world[end.y][end.x].entity=world[start.y][start.x].entity;
	world[end.y][end.x].entity->position=end;
	world[end.y][end.x].entity->mv_count-=1;
	world[start.y][start.x].entity=NULL;
}

void attack(GRID world[][MAX_MAP_SIZE],List * mem[],coord start,coord end){
	Entity *attacker=world[start.y][start.x].entity;
	Entity *defender=world[end.y][end.x].entity;
	//printf("Type: %d Team: %d (%d,%d) HP: %d ATT: %d Armor: %d Count: %d\n", attacker->type,attacker->team,attacker->position.x,attacker->position.y,attacker->health,attacker->attack,attacker->armor,attacker->mv_count);      
	//printf("Type: %d Team: %d (%d,%d) HP: %d ATT: %d Armor: %d Count: %d\n", defender->type,defender->team,defender->position.x,defender->position.y,defender->health,defender->attack,defender->armor,defender->mv_count);      
	defender->health-=attacker->attack-defender->armor;
	if(defender->health<=0){
		delete(*defender,mem[defender->type]);
		world[end.y][end.x].entity=NULL;
	}
}
