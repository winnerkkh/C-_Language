// Workshop 8: Virtual Functions
// File: CheckingAccount.cpp
// Date: 2017/07/21
// Name: Kyunghoon Kim
// Student No: 056-845-100
// Student Email: khkim12@myseneca.ca

#include "CheckingAccount.h"

using namespace std;

namespace ict {

	// define the constructor implementation of SavingsAccount as well as checking account's constructor 
	CheckingAccount::CheckingAccount(double initialBalance, double transacFee) :Account(initialBalance) {

		if (transacFee < 0) {

			transactionFee = 0.0;
		}

		else {
			transactionFee = transacFee;
		}
	}


	// define the chargeFee member functions updates the balance by deducting the transactionFee from the balance.
	double CheckingAccount::chargeFee() {

		double totalBalance;

		// Need getbalance() and setBalance to confirm the total Balance
		totalBalance = getBalance() -transactionFee;
		setBalance(totalBalance);

		return totalBalance;
	}



	// the implementation of override debit for class checkingAccount.
	bool CheckingAccount::debit(double debitAmout) {

		bool result = false;

		//checking if the chargeFee is worked or not.
		if (Account::debit(debitAmout)) {
			chargeFee();
			result = true;
		}

		return result;
	}


	// the implementation of override credit for class checkingAccount
	void CheckingAccount::credit(double creditAmount) {

		//perferoming the credit operation in Account class with the argument from checkingAccount Class
		Account::credit(creditAmount);

		//update chargefee
		chargeFee();
	}


	// the implementation of override display for class checkingAccount
	void CheckingAccount::display(std::ostream& os) const {

		// making the format below
		os << "Account type: Checking" << endl;
		os << "Balance: $ " << getBalance() << endl;
		os << "Transaction Fee: " << transactionFee << endl;
	}
}


