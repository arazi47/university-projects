#ifndef _VALIDATOR_H
#define _VALIDATOR_H

int validate_offer(const char* type, const char* address, int surface, int price);

int validate_type(char* type);

int validate_address(char* type);

int validate_surface(int surface);

int validate_price(int price);

#endif // !_VALIDATOR_H
