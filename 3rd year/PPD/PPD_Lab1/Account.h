#pragma once

#include "OperationLog.h"
#include <mutex>

class Account
{
public:
	Account();
	Account(int balance, int guid);
	~Account();
	
	bool transferIntoAccount(Account &acc, int money);
	void logOperation(OperationType type, int amount);
	void printAllOperations();
	bool check() const;

//private:
	int guid;
	int initialBalance;
	int balance;
	OperationLog log;

	std::mutex *operationMutex;
};

