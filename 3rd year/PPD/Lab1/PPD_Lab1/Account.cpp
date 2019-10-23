#include "pch.h"
#include "Account.h"


Account::Account()
{
}

Account::Account(int balance, int guid) : initialBalance{ balance }, balance{ balance }, guid{ guid }
{
	this->operationMutex = new std::mutex();
}


Account::~Account()
{
}

bool Account::transferIntoAccount(Account & acc, int money)
{
	if (balance < money)
		return false;

	if (this->guid < acc.guid)
	{
		this->operationMutex->lock();
		acc.operationMutex->lock();
	}
	else
	{
		acc.operationMutex->lock();
		this->operationMutex->lock();
	}

	balance -= money;
	acc.balance += money;

	logOperation(SEND_MONEY, money);
	acc.logOperation(RECEIVE_MONEY, money);

	this->operationMutex->unlock();
	acc.operationMutex->unlock();

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

bool Account::check() const
{
	int ib = this->initialBalance;
	for (const auto &log : this->log.operations)
	{
		ib += log.type == SEND_MONEY ? -log.amount : +log.amount;
	}

	return ib == this->balance;
}