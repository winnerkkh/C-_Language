// Workshop 8: Virtual Functions
// File: Account.h
// Date: 2017/07/20
// Name: Kyunghoon Kim
// Student No: 056-845-100
// Student Email: khkim12@myseneca.ca

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include <iostream>

using namespace std;

namespace ict{
   
	class Account{
		private:
			double balance; // data member that stores the balance

		protected:
			double getBalance() const; // return the account balance
			void setBalance( double ); // sets the account balance

   		public:
			// declare the constructor of Account
			Account(double balanceValue);
		
			//declare the virtual function of credit
			virtual void credit(double creditAmount);
			
			//deckare the virtual function of debit
			virtual bool debit(double debitAmout);

			// declare the pure vitual function of display	
			virtual void display(std::ostream& os) const = 0;
   };
};
#endif
