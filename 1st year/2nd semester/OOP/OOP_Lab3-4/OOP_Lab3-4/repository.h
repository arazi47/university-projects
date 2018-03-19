#ifndef _REPOSITORY_H
#define _REPOSITORY_H

#include "offer.h"

typedef struct Offer TElement;

typedef struct
{
	TElement* elems;
	int length;
	int capacity;
} DynamicArray;

DynamicArray* create_dynamic_array(int capacity);
void destroy(DynamicArray* arr);
void add(DynamicArray* arr, TElement t);
void remove_element(DynamicArray* array, int index_to_remove);
int search_element(DynamicArray* arr, char* address);
void insert_at_position(DynamicArray* array, int index, struct Offer old_elem);

void sort(DynamicArray* array, int asc_desc, int cmp);

#endif // !_REPOSITORY_H
