#include "stdafx.h"
#include "controller.h"
#include "offer.h"

/*
Initialize a dynamic array with a capacity of 10 elements
*/
void run_ctrl()
{	
	 offers = create_dynamic_array(10);
}

/*
	Create and add offer (after validating it) to the "offers" dynamic array
	Return:
		-1 - failed to add offer
		1 - added offer

	If the record variable is 1, then an undo operation will be created
*/
int add_offer(char* type, char* address, int surface, int price, int record)
{
	if (validate_offer(type, address, surface, price) == 1)
	{
		struct Offer offer = create_offer(type, address, surface, price);
		add(offers, offer);

		if (record == 1)
		{
			undo_op[undo_length].index = 0; // don't really need this here
			undo_op[undo_length].old_offer = offer;
			undo_op[undo_length].operation_type = OPERATION_ADD;
			++undo_length;
		}

		return 1;
	}
	
	return -1;
}

/*
	Searches and deletes an element with the specified address
	(the address being the unique identifier of an offer)
*/
int delete_element(char* address, int record)
{
	int pos = search_element(offers, address);
	if (pos == -1)
		return -1;

	if (record == 1)
	{
		undo_op[undo_length].index = pos;
		undo_op[undo_length].old_offer = offers->elems[pos];
		undo_op[undo_length].operation_type = OPERATION_DELETE;
		++undo_length;
	}

	remove_element(offers, pos);

	return 1;
}

// Debug
void show_offers()
{
	if (offers->length == 0)
	{
		printf("There are no offers!\n");
		return;
	}

	int i;
	for (i = 0; i < offers->length; ++i)
		printf("%d. %s - %s - %d - %d\n", i, offers->elems[i].type, offers->elems[i].address, offers->elems[i].surface, offers->elems[i].price);

	printf("\n");
}

// There are two functions, because when I call the debug one from the UI, "offers" can't be accessed by UI
/*
	Prints out a dynamic array
*/
void show_filtered_offers(DynamicArray* array)
{
	if (array->length == 0)
	{
		printf("There are no offers!\n");
		return;
	}

	int i;
	for (i = 0; i < array->length; ++i)
		printf("%d. %s - %s - %d - %d\n", i, array->elems[i].type, array->elems[i].address, array->elems[i].surface, array->elems[i].price);

	printf("\n");
}

/*
	Searches an element with the given address
	Return:
		-1 - offer could not be found
		i - index of the offer
*/
int ctrl_search_element(char* address)
{
	return search_element(offers, address);
}

/*
	Updates the type of the offer found at the given index
*/
void update_type(int index, char* new_type, int record)
{
	if (record == 1)
	{
		undo_op[undo_length].index = index;
		undo_op[undo_length].old_offer = offers->elems[index];
		undo_op[undo_length].operation_type = OPERATION_UPDATE_TYPE;
		++undo_length;
	}

	strcpy(offers->elems[index].type, new_type);
}

/*
	Updates the address of the offer found at the given index
*/
void update_address(int index, char* new_address, int record)
{
	if (record == 1)
	{
		undo_op[undo_length].index = index;
		undo_op[undo_length].old_offer = offers->elems[index];
		undo_op[undo_length].operation_type = OPERATION_UPDATE_ADDRESS;
		++undo_length;
	}

	strcpy(offers->elems[index].address, new_address);
}

/*
	Updates the surface of the offer found at the given index
*/
void update_surface(int index, int new_surface, int record)
{
	if (record == 1)
	{
		undo_op[undo_length].index = index;
		undo_op[undo_length].old_offer = offers->elems[index];
		undo_op[undo_length].operation_type = OPERATION_UPDATE_SURFACE;
		++undo_length;
	}

	offers->elems[index].surface = new_surface;
}

/*
	Updates the price of the offer found at the given index
*/
void update_price(int index, int new_price, int record)
{
	if (record == 1)
	{
		undo_op[undo_length].index = index;
		undo_op[undo_length].old_offer = offers->elems[index];
		undo_op[undo_length].operation_type = OPERATION_UPDATE_PRICE;
		++undo_length;
	}

	offers->elems[index].price = new_price;
}

/*
	Filters & sorts & prints the dynamic array "offers" by surface
	asc_desc - 1 ascending, != 1 descending
	surface_greater_than - will only keep the offers of which the surface is greater than this variable
*/
void filter_sort_print_by_surface(char* type, int asc_desc, int surface_greater_than)
{
	// Max length of the filtered array will be offers->length
	DynamicArray* filtered_da = create_dynamic_array(offers->length);
	int i;
	for (i = 0; i < offers->length; ++i)
	{
		if (strcmp(offers->elems[i].type, type) == 0 && offers->elems[i].surface > surface_greater_than)
		{
			add(filtered_da, offers->elems[i]);
		}
	}

	sort(filtered_da, asc_desc, 4);
	show_filtered_offers(filtered_da);

	destroy(filtered_da);
}

/*
Filters & sorts & prints the dynamic array "offers" by address & price & increasing
	surface_greater_than - will only keep the offers of which the given address matches the offer's address
*/
void filter_sort_print_by_addr(char* address)
{
	if (strcmp(address, "all") == 0)
	{
		show_offers();
		return;
	}

	DynamicArray* filtered_da = create_dynamic_array(offers->length);
	int i;
	for (i = 0; i < offers->length; ++i)
	{
		if (strstr(offers->elems[i].address, address))
		{
			add(filtered_da, offers->elems[i]);
		}
	}

	// increasing by price
	sort(filtered_da, 1, 2);
	show_filtered_offers(filtered_da);

	destroy(filtered_da);
}

/*
Filters & sorts & prints the dynamic array "offers" by price
	asc_desc - 1 ascending, != 1 descending
	target_price - will only keep the offers of which the price is greater than this variable
*/
void filter_sort_print_by_price_higher_than(int target_price)
{
	DynamicArray* filtered_da = create_dynamic_array(offers->length);
	int i;
	for (i = 0; i < offers->length; ++i)
	{
		if (offers->elems[i].price > target_price)
		{
			add(filtered_da, offers->elems[i]);
		}
	}

	// increasing by price
	//sort(filtered_da, 1, 2);
	show_filtered_offers(filtered_da);

	destroy(filtered_da);
}

/*
Filters & sorts & prints the dynamic array "offers" by surface
	asc_desc - 1 ascending, != 1 descending
	surface_greater_than - will only keep the offers of which the surface is equal to this variable
*/
void filer_sort_print_by_surface_lab3(int surface)
{
	DynamicArray* filtered_da = create_dynamic_array(offers->length);
	int i;
	for (i = 0; i < offers->length; ++i)
	{
		if (offers->elems[i].surface == surface)
		{
			add(filtered_da, offers->elems[i]);
		}
	}
	
	// increasing by price
	sort(filtered_da, 1, 2);
	show_filtered_offers(filtered_da);

	destroy(filtered_da);
}
