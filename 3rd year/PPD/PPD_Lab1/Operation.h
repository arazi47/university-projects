#pragma once

enum OperationType
{
	SEND_MONEY,
	RECEIVE_MONEY,
};

class Operation
{
public:
	Operation();
	Operation(OperationType type, int guid, int amount) : type{ type }, guid{ guid }, amount{ amount } {}
	~Operation();

//private:
	OperationType type;
	int guid;
	int amount;
};

