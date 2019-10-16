#include "pch.h"
#include <iostream>
#include "Account.h"
#include <thread>
#include <vector>
#include <ctime>
#include <thread>
#include <mutex>

const int numAccounts = 5;
const int numThreads = 2;
const long long int operations = 99999;

std::vector<std::thread> threads;
std::vector<Account> accounts;

void checkAccounts()
{
	bool failed = false;
	int failedAccounts = 0;
	for (const auto &account : accounts)
	{
		if (!account.check()) {
			++failedAccounts;
			if (!failed)
				failed = true;
		}
	}

	if (!failed)
		std::cout << "All accounts are checked!" << std::endl;
	else
		std::cout << failedAccounts << " accounts did not pass the check." << std::endl;
}

// The function that the threads are going to execute
void doOperations(int threadId)
{
	// Random seed
	srand((unsigned int)time(0));
	
	// Split the number of operations equally amongst the threads
	for (long long int i = 0; i < operations / numThreads; ++i)
	{
		// Get two random accounts
		int accId = rand() % accounts.size();
		int accId2 = rand() % accounts.size();

		// This operation is not valid, do not proceed with it
		if (accId == accId2)
		{
			--i; // We need to do 1 more operation
			continue;
		}

		accounts[accId].transferIntoAccount(accounts[accId2], rand() % 25);
		//std::cout << "Operation done by thread with ID " << threadId << "." << std::endl;

		// 10% chance to randomly check the accounts
		// Seems low but it's not
		//if (rand() % 10 + 1 > 9)
		//	checkAccounts();
	}
}

void createAccounts()
{
	// Create some accounts
	int guid = 0;
	for (int i = 0; i < numAccounts; ++i)
		accounts.emplace_back(Account(100, guid++));
}

int main()
{
	createAccounts();
	
	int t0 = time(NULL);
	// Create the threads
	for (int i = 0; i < numThreads; ++i)
		threads.emplace_back(std::thread(doOperations, i));

	// Synchronize threads
	for (int i = 0; i < numThreads; ++i)
		threads[i].join();
	int t1 = time(NULL);

	printf("elapsed time %d\n", t1 - t0);

	for (unsigned int i = 0; i < accounts.size(); ++i)
		std::cout << "Balance for account ID " << i << " is " << accounts[i].balance << "." << std::endl;

	// One last consistency check
	checkAccounts();
}
