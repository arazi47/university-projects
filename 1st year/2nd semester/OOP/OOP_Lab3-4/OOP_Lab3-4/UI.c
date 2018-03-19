#include "stdafx.h"

/*
	Print text and then read an integer from the keyboard
	
	NOTE: in C++ we have cin.fail() to check for bad input, but C is not foolproof
*/
int read_integer(const char* text)
{
	int option;
	
	printf("%s", text);
	scanf("%d", &option);

	return option;
}

void print_menu()
{
	printf("0. Exit\n\
1. Add real estate (an offer)\n\
2. Update real estate\n\
3. Delete real estate\n\
4. Display all offers containing a given string (sorted in ascending order by their price)\n\
5. Display all offers of a given type, having the surface greater than a given value\n\
6. Undo\n\
7. Redo\n\
8. Show offers (debug)\n\
9. [L3] For a given surface, display all offers, sorted ascending by price\n");
}

/*
	Initialize the global dynamic array
	Add some offers for testing
	Set the undo & rendo arrays length to 0
	Start an infinite loop that prints out the menu & asks for keyboard input
*/
void run()
{
	// initialize the global dynamic array
	run_ctrl();

	// test
	char house[] = "house";
	char apartment[] = "apartment";
	char penthouse[] = "penthouse";
	char addr1[] = "addr1";
	char addr2[] = "addr2";
	char addr3[] = "addr3";
	char addr4[] = "addr4";
	//add_offer("house", "addr1", 30, 5);
	add_offer(house, addr1, 30, 5, -1);
	add_offer(house, addr2, 40, 4, -1);
	add_offer(penthouse, addr3, 15, 2, -1);
	add_offer(apartment, addr4, 15, 1, -1);
	//

	undo_length = 0;
	redo_length = 0;

	while (1)
	{
		print_menu();

		int option = read_integer(">> ");
		system("cls");

		switch (option)
		{
			case 0:
				exit(0);
				break;
			
			case 1:
			{
				int surface, price;
				char address[100] = "", type[20] = "";

				// TODO replace read_integer where needed
				printf("Type (str): ");
				scanf("%s", &type);

				printf("Address (str): ");
				scanf("%s", &address);
				
				printf("Surface (int): ");
				scanf("%d", &surface);

				printf("Price (int): ");
				scanf("%d", &price);

				int result = add_offer(type, address, surface, price, 1);
				if (result == -1)
					printf("Fail!\n");
				else
					printf("Success!\n");
			}
				break;
			
			case 2:
			{
				char address[100];
				printf("Address: ");
				scanf("%s", &address);

				int search_result = ctrl_search_element(address);
				if (search_result == -1)
				{
					printf("Failed to find the real estate with the specified address.");
					break;
				}
				
				printf("1. Update type\n2. Update address\n3. Update surface\n4. Update price\n");
				int option = read_integer(">> ");

				switch (option)
				{
					case 1:
					{
						printf("New type (str): ");
						char new_type[100];
						scanf("%s", &new_type);

						if (validate_type(new_type) == 1)
						{
							update_type(search_result, new_type, 1);
							printf("Success!");
						}
						else
							printf("Failed to update type!");
					}
						break;
					case 2:
					{
						printf("New address (str): ");
						char new_addr[100];
						scanf("%s", &new_addr);

						if (validate_address(new_addr) == 1)
						{
							update_address(search_result, new_addr, 1);
							printf("Success!");
						}
						else
							printf("Failed to update address!");
					}
						break;
					case 3:
					{
						printf("New surface (int): ");
						int new_surface;
						scanf("%d", &new_surface);

						if (validate_surface(new_surface) == 1)
						{
							printf("Success!");
							update_surface(search_result, new_surface, 1);
						}
						else
							printf("Failed to update surface!");
					}
						break;
					case 4:
					{
						printf("New price (int): ");
						int new_price;
						scanf("%d", &new_price);

						if (validate_price(new_price) == 1)
						{
							printf("Success!");
							update_price(search_result, new_price, 1);
						}
						else
							printf("Failed to update price!");
					}
						break;
					default:
						printf("Unknown option entered!\n");
				}
			}
				break;
			
			case 3:
			{
				printf("Address to delete (str): ");
				char addr_to_delete[100];
				scanf("%s", &addr_to_delete);
				int result = delete_element(addr_to_delete, 1);

				if (result == -1)
					printf("Fail!");
				else
					printf("Deletion performed successfully!");
			}
				break;

			case 4:
			{
				int option = read_integer("1. Identify by address (sorted incr. by price)\n2. [BONUS] Identify by price higher than\n");
				
				if (option == 1) // address
				{
					char given_string[100]; // address
					printf("Search offers containing a given address (enter 'all' to display all addresses): ");
					scanf("%s", &given_string);

					filter_sort_print_by_addr(given_string);
				}
				else if (option == 2) // price higher than
				{
					int price_higher_than = read_integer("Price higher than: ");
					
					filter_sort_print_by_price_higher_than(price_higher_than);
				}
				else
					printf("Unknown option entered!");
			}
				break;

			case 5:
			{
				char given_type[100];
				printf("Input desired type: ");
				scanf("%s", &given_type);
				
				// Bonus
				int asc_desc = read_integer("1. Ascending\n2. Descending:\n>> ");
				if (asc_desc != 1 && asc_desc != 2)
				{
					printf("Unknown option entered!");
					break;
				}

				/*
				int cmp = read_integer("1. Surface\n2. Price\n3. Address\n4. Type\n>> ");
				if (cmp != 1 && cmp != 2 && cmp != 3 && cmp != 4)
				{
					printf("Unknown option entered!");
					break;
				}
				*/

				int surface_greater_than;
				printf("Surface greater than: ");
				scanf("%d", &surface_greater_than);

				filter_sort_print_by_surface(given_type, asc_desc, surface_greater_than);
			}
				break;
				
			case 6:
			{
				int result = undo_operation();
				if (result == -1)
					printf("Failed to undo last operation!");
				else
					printf("Success!");
			}
				break;
				
			case 7:
			{
				int result = redo_operation();
				if (result == -1)
					printf("Failed to redo last operation!");
				else
					printf("Success!");
			}
				break;

			case 8:
			{
				show_offers();
			}
				break;

			case 9:
			{
				int surface = read_integer("Surface: ");
				filer_sort_print_by_surface_lab3(surface);
			}
				break;
				
			default:
				printf("Invalid option entered!");
		}
		printf("\n");
	}
}
