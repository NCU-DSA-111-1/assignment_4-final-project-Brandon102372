#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER
#include "Assets.h"
typedef struct node Node;

typedef struct list List;

List * makelist();
Entity *add(Entity data, List * list);
void delete(Entity data, List * list);
void display(List * list);
void reverse(List * list);
void reverse_using_two_pointers(List * list);
void destroy(List * list);

#endif
