#include "runtests.h"

void test_dynamic_array()
{
	//DynamicArray* da = create_dynamic_array(2);
	offers = create_dynamic_array(2);
	if (offers == NULL)
		assert(0);
	
	assert(offers->capacity == 2);
	assert(offers->length == 0);
	
	char house[] = "house";
	char apartment[] = "apartment";
	char addr1[] = "addr1";
	char addr2[] = "addr2";
	char addr3[] = "addr3";
	
	struct Offer o1 = create_offer(house, addr1, 5, 5);
	add(offers, o1);
	assert(offers->length == 1);
	
	struct Offer o2 = create_offer(house, addr2, 3, 18);
	add(offers, o2);
	assert(offers->length == 2);
	
	// capacity must double
	struct Offer o3 = create_offer(apartment, addr3, 10, 3);
	add(offers, o3);
	assert(offers->length == 3);
	assert(offers->capacity == 4);

	delete_element(addr1, 1);
	assert(offers->length == 2);
	
	undo_operation();
	assert(offers->length == 3);

	redo_operation();
	assert(offers->length == 2);
	
	destroy(offers);
}

void test_validators()
{
	assert(validate_address("stuff") == 1);
	assert(validate_address("") == -1);

	assert(validate_type("") == -1);
	assert(validate_type("type") == -1);
	assert(validate_type("house") == 1);
	assert(validate_type("apartment") == 1);
	assert(validate_type("penthouse") == 1);

	assert(validate_price(-5) == -1);
	assert(validate_price(0) == -1);
	assert(validate_price(7129) == 1);

	assert(validate_surface(-813) == -1);
	assert(validate_surface(0) == -1);
	assert(validate_surface(812) == 1);
	assert(validate_surface(1001) == -1);
}

void run_tests()
{
	test_dynamic_array();
	test_validators();
}