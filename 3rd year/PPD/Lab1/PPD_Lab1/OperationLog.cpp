#include "pch.h"
#include "OperationLog.h"
#include <string>
#include <iostream>


OperationLog::OperationLog()
{
}


OperationLog::~OperationLog()
{
}

void OperationLog::log(OperationType type, int amount)
{
	Operation o(type, operations.size(), amount);
	operations.push_back(o);
}

void OperationLog::printAllOperations()
{
	for (const auto &o : operations)
	{
		std::string type;
		switch (o.type)
		{
			case SEND_MONEY:
				type = "Send money";
				break;
			case RECEIVE_MONEY:
				type = "Receive money";
				break;
			default:
				type = "Unknown operation with type " + o.type;
				break;
		}
		std::cout << "Operation guid: " << o.guid << "; type: " << type << "; amount = " << o.amount << std::endl;
	}
	
	std::cout << std::endl;
}
