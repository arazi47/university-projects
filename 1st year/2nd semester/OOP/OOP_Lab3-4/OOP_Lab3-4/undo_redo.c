#include "stdafx.h"
#include "undo_redo.h"

/*
	Undo the last performed operation (add, update, delete)
*/
int undo_operation()
{
	if (undo_length == 0)
		return -1;

	switch (undo_op[undo_length - 1].operation_type)
	{
		case OPERATION_ADD:
		{
			delete_element(undo_op[undo_length - 1].old_offer.address, -1);
		}
			break;

		case OPERATION_DELETE:
		{
			insert_at_position(offers, undo_op[undo_length - 1].index, undo_op[undo_length - 1].old_offer);

			// Add as the last element
			//add_offer(undo_op[undo_length - 1].old_offer.type, undo_op[undo_length - 1].old_offer.address, undo_op[undo_length - 1].old_offer.surface, undo_op[undo_length - 1].old_offer.price);
		}
			break;

		case OPERATION_UPDATE_ADDRESS:
		{
			update_address(undo_op[undo_length - 1].index, undo_op[undo_length - 1].old_offer.address, -1);
		}
			break;

		case OPERATION_UPDATE_PRICE:
		{
			update_address(undo_op[undo_length - 1].index, undo_op[undo_length - 1].old_offer.price, -1);
		}
			break;

		case OPERATION_UPDATE_SURFACE:
		{
			update_address(undo_op[undo_length - 1].index, undo_op[undo_length - 1].old_offer.surface, -1);
		}
			break;

		case OPERATION_UPDATE_TYPE:
		{
			update_address(undo_op[undo_length - 1].index, undo_op[undo_length - 1].old_offer.type, -1);
		}
			break;

		default:
			return -1;
			break;
	}

	redo_op[redo_length].index = undo_op[undo_length - 1].index;
	redo_op[redo_length].old_offer = undo_op[undo_length - 1].old_offer;
	redo_op[redo_length].operation_type = undo_op[undo_length - 1].operation_type;

	++redo_length;
	--undo_length;

	return 1;
}

/*
	Redo the last operation thas has been undone (add, update, delete)
*/
int redo_operation()
{
	if (redo_length == 0)
		return -1;

	switch (undo_op[redo_length - 1].operation_type)
	{
		case OPERATION_ADD:
		{
			//delete_element(undo_op[undo_length - 1].old_offer.address);
			add_offer(redo_op[redo_length - 1].old_offer.type, redo_op[redo_length - 1].old_offer.address, redo_op[redo_length - 1].old_offer.surface, redo_op[redo_length - 1].old_offer.price, -1);
		}
		break;

		case OPERATION_DELETE:
		{
			delete_element(redo_op[redo_length - 1].old_offer.address, -1);
			//insert_at_position(offers, undo_op[undo_length - 1].index, undo_op[undo_length - 1].old_offer);

			// Add as the last element
			//add_offer(undo_op[undo_length - 1].old_offer.type, undo_op[undo_length - 1].old_offer.address, undo_op[undo_length - 1].old_offer.surface, undo_op[undo_length - 1].old_offer.price);
		}
		break;

		case OPERATION_UPDATE_ADDRESS:
		{
			update_address(redo_op[redo_length - 1].index, redo_op[redo_length - 1].old_offer.address, -1);
		}
		break;

		case OPERATION_UPDATE_PRICE:
		{
			update_address(redo_op[redo_length - 1].index, redo_op[redo_length - 1].old_offer.price, -1);
		}
		break;

		case OPERATION_UPDATE_SURFACE:
		{
			update_address(redo_op[redo_length - 1].index, redo_op[redo_length - 1].old_offer.surface, -1);
		}
		break;

		case OPERATION_UPDATE_TYPE:
		{
			update_address(redo_op[redo_length - 1].index, redo_op[redo_length - 1].old_offer.type, -1);
		}
		break;

		default:
			return -1;
			break;
	}

	--redo_length;
	return 1;
}
