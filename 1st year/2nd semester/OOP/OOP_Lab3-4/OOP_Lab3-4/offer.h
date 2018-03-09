#ifndef _OFFER_H
#define _OFFER_H

#include <cstring>

enum OFFER_TYPE 
{
	TYPE_HOUSE,
	TYPE_APARTMENT,
	TYPE_PENTHOUSE
};

struct Offer
{
	int type;
	char address[100];
	int surface;
	int price;

	Offer(int type, char address[100], int surface, int price)
	{
		this->type = type;
		strcpy(this->address, address);
		this->surface = surface;
		this->price = price;
	}

	bool contains_given_string(char given_string[100])
	{
		char* found = strstr(this->address, given_string);

		return found != NULL;
	}

	int get_type()
	{
		return this->type;
	}

	char* get_address()
	{
		return this->address;
	}

	int get_surface()
	{
		return this->surface;
	}

	int get_price()
	{
		return this->price;
	}
};

#endif