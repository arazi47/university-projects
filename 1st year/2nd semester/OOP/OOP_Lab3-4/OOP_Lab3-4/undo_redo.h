#ifndef _UNDO_REDO_H
#define _UNDO_REDO_H

#include "offer.h"

enum OPERATION_TYPE
{
	OPERATION_ADD,
	OPERATION_DELETE,
	OPERATION_UPDATE_TYPE,
	OPERATION_UPDATE_ADDRESS,
	OPERATION_UPDATE_SURFACE,
	OPERATION_UPDATE_PRICE
};

struct operation
{
	int operation_type;
	struct Offer old_offer;

	// when we have OPERATION_ADD
	int index;
} undo_op[1000], redo_op[1000];

int undo_length;
int redo_length;

int undo_operation();
int redo_operation();

#endif // !_UNDO_REDO_H
