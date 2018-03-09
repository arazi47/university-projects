#include "stdafx.h"

int read_integer(const char* text)
{
	int option;
	cout << text;
	cin >> option;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << text;
		cin >> option;
	}

	return option;
}

void print_menu()
{
	cout << "0. Exit" << endl
		<< "1. Add real estate" << endl
		<< "2. Update real estate" << endl
		<< "3. Delete real estate" << endl
		<< "4. Display all offers containing a given string (sorted ascending by their price)" << endl
		<< "5. Display all offers of a given type, having the surface grater than a given value" << endl
		<< "6. Undo" << endl
		<< "7. Redo" << endl;
}

void run()
{
	while (true)
	{
		print_menu();

		int option = read_integer(">> ");

		switch (option)
		{
			case 0:
				exit(0);
				break;
			
			case 1:
				// add real estate
				break;
			
			case 2:
				break;
			
			case 3:
				break;

			case 4:
				break;

			case 5:
				break;

			case 6:
				break;
				
			case 7:
				break;

			default:
				cout << "Invalid option entered!" << endl;
		}
	}
}