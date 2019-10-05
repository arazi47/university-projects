// PPD_Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Account.h"
#include <thread>
#include <vector>
#include <ctime>
#include <thread>
#include <mutex>

const int numThreads = 5;
const int operations = 1000;

std::vector<std::thread> threads;
std::mutex operationMutex;
std::vector<Account> accounts;

// TODO
void checkAccounts()
{
	//
}

// The function that the threads are going to execute
void doOperations(int threadId)
{
	// Random seed
	srand((unsigned int)time(0));
	
	// Split the number of operations equally amongst the threads
	for (int i = 0; i < operations / numThreads; ++i)
	{
		// Get a random account
		int accId = rand() % accounts.size();
		int accId2 = rand() % accounts.size();
		accounts[accId].transferIntoAccount(accounts[accId2], rand() % 25);
		std::cout << "Operation done by thread with ID " << threadId << "." << std::endl;
	}
}

/*
	TODO:
		- sa-l intreb pe prof de ce drecu
		cand nu mai dau lock/unlock nu mai ruleaza
*/

int main()
{
	// Create some accounts
	accounts.emplace_back(Account(100, &operationMutex));
	accounts.emplace_back(Account(100, &operationMutex));
	accounts.emplace_back(Account(100, &operationMutex));
	accounts.emplace_back(Account(100, &operationMutex));
	accounts.emplace_back(Account(100, &operationMutex));

	// Create the threads
	for (int i = 0; i < numThreads; ++i)
		threads.emplace_back(std::thread(doOperations, i));

	// Synchronize threads
	for (int i = 0; i < numThreads; ++i)
		threads[i].join();

	for (unsigned int i = 0; i < accounts.size(); ++i)
		std::cout << "Balance for account ID " << i << " is " << accounts[i].balance << "." << std::endl;
}
