#ifndef DISPLAY_H
#define DISPLAY_H
#include "../inc/Map.h"
#include "../inc/Entity.h"
typedef enum {BLACK,DARK_BLUE,DARK_GREEN,DARK_CYAN,DARK_RED,DARK_PURPLE,
DARK_YELLOW,DARK_WHITE,GREY,BLUE,GREEN,CYAN,RED,PURPLE,YELLOW,WHITE}Color;

  
void show_all(GRID world[][MAX_MAP_SIZE]){
	system("cls");
	int i=0,j=0;
	char v[3];
	printf("      1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16\n");
	printf("  ¢z¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢s¢w¢w¢w¢w¢{\n");
	for (i=0;i<MAX_MAP_SIZE;i++){
		i<9 ? printf(" %d¢x",i+1):printf("%d¢x",i+1);
		for (j=0;j<MAX_MAP_SIZE;j++){
			
			if (world[i][j].visit>0){
				strcpy(v," O");
			}else if(world[i][j].visit==-1){
				strcpy(v," X");
			}else{
				strcpy(v,"  ");
			}
			if(world[i][j].entity!=NULL){
				ARMY a=world[i][j].entity->type;
				printf("%s%s¢x",army_texture[a],v);	
			}else{
				printf("  %s¢x",v);	
			}
		}
		printf("\n  ¢x");
		for (j=0;j<MAX_MAP_SIZE;j++){
			RESOURCE re=world[i][j].resource;
			printf("%s  ¢x",res_texture[re]);
		}
		printf("\n");
		if(i!=MAX_MAP_SIZE-1){	
			printf("  ¢u¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢q¢w¢w¢w¢w¢t\n");	
		}
	}
	printf("  ¢|¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢r¢w¢w¢w¢w¢}\n");
}
#endif
