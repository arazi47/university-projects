#include "stdafx.h"
#include "repository.h"

/*
	Create a dynamic array of a given capacity and return it
*/
DynamicArray* create_dynamic_array(int capacity)
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (da == NULL)
		return NULL;

	da->capacity = capacity;
	da->length = 0;

	da->elems = (TElement*)malloc(capacity * sizeof(TElement));
	if (da->elems == NULL)
		return NULL;

	return da;
}

/*
	Destroy the given dynamic array
*/
void destroy(DynamicArray* arr)
{
	if (arr == NULL)
		return;

	free(arr->elems);
	arr->elems = NULL;

	free(arr);
	arr = NULL;
}

/*
	Double the capacity of the given dynamic array
*/
void resize(DynamicArray* arr)
{
	if (arr == NULL)
		return;

	arr->capacity *= 2;
	TElement* aux = (TElement*)realloc(arr->elems, arr->capacity * sizeof(TElement));
	if (aux == NULL)
		return;

	arr->elems = aux;
}

/*
	Add a TElement to the given dynamic array
*/
void add(DynamicArray* arr, TElement t)
{
	if (arr == NULL)
		return;

	if (arr->elems == NULL)
		return;

	if (arr->length == arr->capacity)
		resize(arr);

	arr->elems[arr->length] = t;
	++arr->length;
}

// Linear search
// An offer is uniquely identified by its address
// Returns -1 if arr, elems == NULL or if the address it not found
// Otherwise, the function returns the index of the element
int search_element(DynamicArray* arr, char* address)
{
	if (arr == NULL)
		return -1;

	if (arr->elems == NULL)
		return -1;

	int i;
	for (i = 0; i < arr->length; ++i)
	{
		if (has_address(arr->elems[i].address, address) == 1)
			return i;
	}

	return -1;
}

/*
	Remove the element found at index_to_remove from the given dynamic array
*/
void remove_element(DynamicArray* array, int index_to_remove)
{
	for (int i = index_to_remove; i < array->length - 1; ++i)
		array->elems[i] = array->elems[i + 1];

	--array->length;
}

/*
	Insert old_elem on position index in the given dynamic array
*/
void insert_at_position(DynamicArray* array, int index, struct Offer old_elem)
{
	for (int i = array->length; i > index; --i)
		array->elems[i] = array->elems[i - 1];
	
	array->elems[index] = old_elem;
	++array->length;
}

// asc_desc == 1 -> ascending
// asc_desc != 1 -> descending

// cmp == 1 -> by surface
// cmp == 2 -> by price
// cmp == 3 -> by address
// cmp == 4 -> by type
void sort(DynamicArray* array, int asc_desc, int cmp)
{
	int i, j;
	struct Offer aux;
	for (i = 0; i < array->length - 1; ++i)
		for (j = i + 1; j < array->length; ++j)
			if (cmp == 2) // price
			{
				if (asc_desc == 1) // ascending
				{
					if (array->elems[i].price > array->elems[j].price)
					{
						aux = array->elems[i];
						array->elems[i] = array->elems[j];
						array->elems[j] = aux;
					}
				}
				else // descending
				{
					if (array->elems[i].price < array->elems[j].price)
					{
						aux = array->elems[i];
						array->elems[i] = array->elems[j];
						array->elems[j] = aux;
					}
				}
			}
			else if (cmp == 1) // surface
			{
				if (asc_desc == 1) // ascending
				{
					if (array->elems[i].surface > array->elems[j].surface)
					{
						aux = array->elems[i];
						array->elems[i] = array->elems[j];
						array->elems[j] = aux;
					}
				}
				else // descending
				{
					if (array->elems[i].surface < array->elems[j].surface)
					{
						aux = array->elems[i];
						array->elems[i] = array->elems[j];
						array->elems[j] = aux;
					}
				}
			}
			else if (cmp == 3) // address
			{
				{
					if (asc_desc == 1) // ascending
					{
						if (strcmp(array->elems[i].address, array->elems[j].address) < 0)
						{
							aux = array->elems[i];
							array->elems[i] = array->elems[j];
							array->elems[j] = aux;
						}
					}
					else // descending
					{
						if (strcmp(array->elems[i].address, array->elems[j].address) > 0)
						{
							aux = array->elems[i];
							array->elems[i] = array->elems[j];
							array->elems[j] = aux;
						}
					}
				}
			}
			else if (cmp == 4) // type
			{
				{
					if (asc_desc == 1) // ascending
					{
						if (strcmp(array->elems[i].type, array->elems[j].type) < 0)
						{
							aux = array->elems[i];
							array->elems[i] = array->elems[j];
							array->elems[j] = aux;
						}
					}
					else // descending
					{
						if (strcmp(array->elems[i].type, array->elems[j].type) > 0)
						{
							aux = array->elems[i];
							array->elems[i] = array->elems[j];
							array->elems[j] = aux;
						}
					}
				}
			}
}
