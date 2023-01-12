#include <stdio.h>
#include <stdlib.h>
#include "../inc/linkedlist.h"

struct node {
  Entity data;
  struct node * next;
};

struct list {
  Node * head; 
};

Node * createnode(Entity data);

Node * createnode(Entity data){
  Node * newNode = malloc(sizeof(Node));
  if (!newNode) {
    return NULL;
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

List * makelist(){
  List * list = malloc(sizeof(List));
  if (!list) {
    return NULL;
  }
  list->head = NULL;
  return list;
}

void display(List * list) {
  Node * current = list->head;
  if(list->head == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
    Entity e=current->data;
    printf("Type: %d Team: %d (%d,%d) HP: %d ATT: %d Armor: %d Count: %d\n", e.type,e.team,e.position.x,e.position.y,e.health,e.attack,e.armor,e.mv_count);
  }
  printf("\n");
}

Entity *add(Entity data, List * list){
  Node * current = NULL;
  if(list->head == NULL){
    list->head = createnode(data);
    //printf("Type: %d Team: %d (%d,%d) HP: %d ATT: %d Armor: %d Count: %d\n", data.type,data.team,data.position.x,data.position.y,data.health,data.attack,data.armor,data.mv_count);
    
	Entity e=list->head->data;
    //printf("Type: %d Team: %d (%d,%d) HP: %d ATT: %d Armor: %d Count: %d\n", e.type,e.team,e.position.x,e.position.y,e.health,e.attack,e.armor,e.mv_count);
	return &(list->head->data);
  }
  else {
    current = list->head; 
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = createnode(data);
    return &(current->next->data);
  }
}

void delete(Entity data, List * list){
  Node * current = list->head;            
  Node * previous = current;           
  while(current != NULL){  
    Entity e=data;
    //printf("Type: %d Team: %d (%d,%d) HP: %d ATT: %d Armor: %d Count: %d\n", e.type,e.team,e.position.x,e.position.y,e.health,e.attack,e.armor,e.mv_count);      
    if(equal(current->data.position,data.position)){
	  printf("found\n");      
      previous->next = current->next;
      if(current == list->head)
        list->head = current->next;
      free(current);
      return;
    }                             
    previous = current;             
    current = current->next;        
  }                                 
}                                   

void reverse(List * list){
  Node * reversed = NULL;
  Node * current = list->head;
  Node * temp = NULL;
  while(current != NULL){
    temp = current;
    current = current->next;
    temp->next = reversed;
    reversed = temp;
  }
  list->head = reversed;
}
//Reversing the entire list by changing the direction of link from forward to backward using two pointers
void reverse_using_two_pointers(List *list){
    Node *previous = NULL;
    while (list->head)
    {
        Node *next_node = list->head->next; //points to second node in list
        list->head->next = previous;//at initial making head as NULL
        previous = list->head;//changing the nextpointer direction as to point backward node 
        list->head = next_node; //moving forward by next node
    }
    list->head=previous;
}
void destroy(List * list){
  Node * current = list->head;
  Node * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

void set_list(List * list,short m_count,short a_count){
  Node * current = list->head;
  if(list->head == NULL) 
    return;
  
  for(; current != NULL; current = current->next) {
      	current->data.at_count=m_count;
    	current->data.mv_count=a_count;	
  }
}
