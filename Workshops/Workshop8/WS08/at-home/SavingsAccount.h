// Workshop 8: Virtual Functions
// File: SavingsAccount.h
// Date: 2017/07/20
// Name: Kyunghoon Kim
// Student No: 056-845-100
// Student Email: khkim12@myseneca.ca

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account{
		private:
    		double interestRate; // interest rate (percentage) 
		public:
	
			// declare the constructor of SavingAccount
			SavingsAccount(double initialBalance, double savingInterestRate);

			// declare the calculateInterest function
			double calculateInterest();

			// declare the overrid the display function
			void display(std::ostream& os) const;

   };
};
#endif
