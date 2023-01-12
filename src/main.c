#include <stdio.h>
#include <stdlib.h>
#include "../inc/linkedlist.h"
#include "../inc/Map.h"
#include "../inc/Entity.h"
#include "../inc/Display.h"
#include "../inc/coord.h"
#define INPUT_SIZE 10

GRID World[MAX_MAP_SIZE][MAX_MAP_SIZE];
List * e_memory[ENTITY_TABLE_SIZE];
void get_coord(coord *st,char*in){
	short x=0,y=0;
	int i=0;
	bool flag=true;
	for (i=0;i<INPUT_SIZE;i++){
		if(in[i]==' '){
			flag=false;
		}else{
			if (flag){
				x=x*10+(in[i]-'0');
			}else{
				if(in[i]>='0'&&in[i]<='9') y=y*10+(in[i]-'0');
			}	
		}
	}
	st->y=(y-1>=0 && y-1<=15)?y-1:-1;
	st->x=(x-1>=0 && x-1<=15)?x-1:-1;
}
int main(){
	char file_name[30];
	char input_str[INPUT_SIZE];
	//fgets(input_str,INPUT_SIZE,stdin);
	input_str[0]='n';
	switch(input_str[0]){
		case 'n': //New game
			world_generator(World);
			initialize_entity_memory(e_memory);
			coord tmp={6,8};
			add_entity(World,e_memory,tmp,MILITIA,0,10,0,2,1,1);
			coord tmp_={7,8};
			add_entity(World,e_memory,tmp_,MILITIA,1,1,0,2,1,1);
			show_all(World);
			Entity *select_e=NULL;
			coord now,target;
			bool gameover=false;
			while(!gameover){
				printf("input options:");
				fgets(input_str,INPUT_SIZE,stdin);
				switch(input_str[0]){
					case 's'://save
						break;
					case 'q'://quit
						gameover=true;
						break;
					case 'h'://harvest resources
						if(World[now.y][now.x].resource!=NONE){
							World[now.y][now.x].resource=NONE;
							show_all(World);
						}else{
							printf("No resources to be harvest !\n");
						}
						break;
					case 't'://train army
						if(World[now.y][now.x].resource!=NONE){
							fgets(input_str,INPUT_SIZE,stdin);
							if(input_str[0]=='m'){
								add_entity(World,e_memory,tmp,MILITIA,0,10,0,2,1,1);
							}
							show_all(World);
						}else{
							printf("Army can only be trained in cities !\n");
						}
						break;
					case 'm'://move army
						if(World[now.y][now.x].entity!=NULL){
							select_e=World[now.y][now.x].entity;
							bool in_range=false;
							if(select_e->mv_count>0 || (select_e->at_count>0&&in_range)){
								if(select_e->mv_count>0){
									valid_move(World,now);
								}
								in_range=valid_attack(World,now);
								show_all(World);
								printf("Enter target coordinate: ");
								fgets(input_str,INPUT_SIZE,stdin);
								get_coord(&target,input_str);
								if(World[target.y][target.x].visit!=0){
									if(World[target.y][target.x].entity==NULL){
										move(World,now,target);
									}else if(World[target.y][target.x].entity->team!=select_e->team){
										attack(World,e_memory,now,target);
									}else{
										printf("Your army is on this grid\n");
									}
								}
								clear_visit(World);
								show_all(World);
							}else{
								printf("Unable to move !\n");
							}
						}else{
							printf("No army in the grid !\n");
						}
						break;
					default:
						get_coord(&now,input_str);
						printf("Current grid: (%d,%d)\n",now.x,now.y);
						break;
				}
			}
			break;
		case 'l': //Load game
			break;
		default:
			break;
	}
	
}
