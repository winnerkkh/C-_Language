// Workshop 8: Virtual Functions
// File: Account.cpp
// Date: 2017/07/20
// Name: Kyunghoon Kim
// Student No: 056-845-100
// Student Email: khkim12@myseneca.ca

#include "Account.h"

using namespace std;

namespace ict{ 
	

	// constructor   
	Account::Account(double balanceValue) {

		if (!(balanceValue >= 0)) {

			balance = 1.0;
		}
		
		else {

			balance = balanceValue;
		}
	}



	// credit (add) an amount to the account balance
	void Account::credit(double creditAmount) {

		balance += creditAmount;
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double debitAmout) {

		bool result= false;

			if (balance > debitAmout) {

				result = true;
				balance -= debitAmout;
				}

		return result;
	}


	//implementation of getBalance function to get and return the value of balnce.
	double Account::getBalance() const
	{
		return balance;
	} 

	//implementation of setBalance function to assign the instance varialbe
	void Account::setBalance(double newBalance )
	{
		balance = newBalance;
	} 
}