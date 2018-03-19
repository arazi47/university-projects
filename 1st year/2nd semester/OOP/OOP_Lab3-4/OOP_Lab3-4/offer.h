#ifndef _OFFER_H
#define _OFFER_H

#include <string.h>

struct Offer
{
	char type[100];
	char address[100];
	int surface;
	int price;
};

int has_address(char* offer_addr, char* address);

struct Offer create_offer(char* type, char* address, int surface, int price);

#endif