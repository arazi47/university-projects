#pragma once

#include "OperationLog.h"
#include <mutex>

class Account
{
public:
	Account();
	Account(int balance, std::mutex *operationMutex) : balance{ balance }, operationMutex{ operationMutex } {}
	~Account();
	
	bool transferIntoAccount(Account &acc, int money);
	void logOperation(OperationType type, int amount);
	void printAllOperations();

//private:
	int balance;
	OperationLog log;

	// Much easier to just use a pointer to a mutex
	// If it needs to be shared between multiple objects
	std::mutex *operationMutex;
};

