#include "stdafx.h"
#include "offer.h"

/*
	Create an offer with the given type, address, surface and price and return it
*/
struct Offer create_offer(char* type, char* address, int surface, int price)
{
	struct Offer offer;
	strcpy(offer.type, type);
	strcpy(offer.address, address);
	offer.surface = surface;
	offer.price = price;

	return offer;
}

/*
	Checks is offer_addr matches address
	Return
		-1 - false
		1 - true
*/
int has_address(char* offer_addr, char* address)
{
	char* found = strstr(offer_addr, address);

	if (found != NULL && strlen(offer_addr) == strlen(address))
		return 1;

	return -1;
}