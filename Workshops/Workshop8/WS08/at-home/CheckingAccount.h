// Workshop 8: Virtual Functions
// File: CheckingAccount.h
// Date: 2017/07/21
// Name: Kyunghoon Kim
// Student No: 056-845-100
// Student Email: khkim12@myseneca.ca

#ifndef SICT_CHECKINGACCOUNT_H__
#define SICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class CheckingAccount : public Account {
		private:
			double transactionFee;

			// declare the chargeFee member function that updates the balance
			double chargeFee();

		public:

			// Constructor initialize with two parameters that receive balance and transaction fee
			CheckingAccount(double initialBalance, double transacFee);

			// declare override debit function from checking Account
			bool debit(double debitAmout);

			// declare override credit function from checking Account
			void credit(double creditAmount);

			// declare override display function from checking Account
			void display(std::ostream& os) const;
	};
};
#endif
