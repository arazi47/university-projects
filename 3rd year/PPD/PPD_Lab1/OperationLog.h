#pragma once

#include <vector>
#include "Operation.h"

class OperationLog
{
public:
	OperationLog();
	~OperationLog();

	void log(OperationType type, int amount);
	void printAllOperations();

private:
	std::vector<Operation> operations;
};

