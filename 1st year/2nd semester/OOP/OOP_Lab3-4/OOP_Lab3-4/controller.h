#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "repository.h"

int add_offer(char* type, char* address, int surface, int price, int record);
int delete_element(char* address, int record);

void show_offers();

int ctrl_search_element(char* address);

// record == 1 => register the operations in the undo list
// record != 1 => don't register the operations in the undo list
// this is needed, because we need to record the operations made by the user
// but not the operations when we call the counter functions from the undo/redo file.
void update_type(int index, char* new_type, int record);
void update_address(int index, char* new_address, int record);
void update_surface(int index, int new_surface, int record);
void update_price(int index, int new_price, int record);

void show_filtered_offers(DynamicArray* array);

void filter_sort_print_by_surface(char* type, int asc_desc, int surface_greater_than);
void filter_sort_print_by_addr(char* address);
void filter_sort_print_by_price_higher_than(int target_price);
void filer_sort_print_by_surface_lab3(int surface);

DynamicArray* offers;
void run_ctrl();

#endif // !_CONTROLLER_H
