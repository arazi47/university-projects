#include "stdafx.h"
#include "validator.h"

/*
	Validates all the given arguments
	Length check, specific string check (type)
	Value check (surface, price)
*/
int validate_offer(const char* type, const char* address, int surface, int price)
{
	if (surface <= 0 || surface >= 1000)
		return -1;

	if (price <= 0)
		return -1;

	if (strlen(type) == 0 || strlen(address) == 0)
		return -1;

	if (!(strcmp(type, "house") == 0) && !(strcmp(type, "apartment") == 0) && !(strcmp(type, "penthouse") == 0))
		return -1;

	return 1;
}

int validate_type(char* type)
{
	/*
		strcmp(x, y):
			0 = equal
			< 0 = x < y
			> 0 = x > y
	*/

	if (!(strcmp(type, "house") == 0) && !(strcmp(type, "apartment") == 0) && !(strcmp(type, "penthouse") == 0))
		return -1;

	return 1;
}

int validate_address(char* type)
{
	if (strlen(type) == 0)
		return -1;

	return 1;
}

int validate_surface(int surface)
{
	if (surface <= 0 || surface >= 1000)
		return -1;

	return 1;
}

int validate_price(int price)
{
	if (price <= 0)
		return -1;

	return 1;
}
