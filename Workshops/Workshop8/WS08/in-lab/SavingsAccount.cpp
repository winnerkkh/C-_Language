// Workshop 8: Virtual Functions
// File: SavingsAccount.cpp
// Date: 2017/07/20
// Name: Kyunghoon Kim
// Student No: 056-845-100
// Student Email: khkim12@myseneca.ca

#include "SavingsAccount.h"

using namespace std;

namespace ict{ 
	
	// implementation of constructor with 2 parameters and
	SavingsAccount::SavingsAccount(double initialBalance, double savingInterestRate): Account(initialBalance) {
		
		if (savingInterestRate < 0) {
		
			interestRate = 0.0;
		}

		else {
			interestRate = savingInterestRate;
		}
	}


		// implementation of calculating the interest
		double SavingsAccount::calculateInterest() {
			
			double tempBalance = getBalance();
			return interestRate * tempBalance;
		}



		// implementation of Override the display function with the format required
		void SavingsAccount::display(std::ostream& os ) const {

			cout.precision(2);
			cout.setf(ios::fixed);

			os << "Account type: Saving"<< endl;
			os << "Balance: $ " << getBalance() << endl;
			os << "Interest Rate (%): " << interestRate * 100 << endl;
		}




}

