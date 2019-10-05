#include "pch.h"
#include "Account.h"


Account::Account()
{
}


Account::~Account()
{
}

bool Account::transferIntoAccount(Account & acc, int money)
{
	if (balance < money)
		return false;

	operationMutex->lock();
	balance -= money;
	acc.balance += money;

	logOperation(SEND_MONEY, money);
	acc.logOperation(RECEIVE_MONEY, money);
	operationMutex->unlock();

	return true;
}

void Account::logOperation(OperationType type, int amount)
{
	log.log(type, amount);
}

void Account::printAllOperations()
{
	log.printAllOperations();
}
