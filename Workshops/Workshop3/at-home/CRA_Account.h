/***********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h 
// Version 1.1
// Date 6/06/2017
// Author Kyunghoon Kim
***********************************************************/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H



namespace sict {

	// define const values 
	#define MAX_NAME_LENGTH 40
	#define MIN_SIN 100000000 
	#define MAX_SIN 999999999
	#define MAX_YRS 4

	// declare the class of CRA_Account 
		class CRA_Account {

		// declare members of instance variable in private class
		private:
			char familyName1[MAX_NAME_LENGTH + 1];
			char givenName1[MAX_NAME_LENGTH + 1];
			int socialNumber;
			int m_year[MAX_YRS];
			double m_balance[MAX_YRS];
			int m_years;

		// declare public functions
		public:
			void set(const char* familyName, const char* givenName, int sin);
			bool isValid() const;
			void display() const;
			void set(int year, double balance);
	};
}

#endif