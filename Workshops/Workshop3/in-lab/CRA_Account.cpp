/***********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 1.1
// Date 6/01/2018
// Author Kyunghoon Kim
***********************************************************/

#include <iostream>
#include<string.h>
#include "CRA_Account.h"
using namespace std;

namespace sict {

	CRA_Account::CRA_Account() {
		familyName1[MAX_NAME_LENGTH + 1] = "\0";
		givenName1[MAX_NAME_LENGTH + 1] = "\0";
	}

	//Set function
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		socialNumber = sin;

		if (isValid()) {
			//copy the value from user input into familyName1 and givenName1
			strcpy(familyName1, familyName);
			strcpy(givenName1, givenName);
		}
		else {
			socialNumber = -1;
		}
	}
	
	// isValid function
	bool CRA_Account::isValid() const {
		
		bool socialNumber2;
		
		//Checking if the user input is valid or not 
		if (socialNumber >= MIN_SIN && socialNumber <= MAX_SIN && socialNumber) {
			socialNumber2 = true;
		  }

		else {
			socialNumber2 = false;
		  }

		return socialNumber2;
	}

	// display function
	void CRA_Account::display() const {

		//if set function matches with condition, display as below
		if (isValid()) {
			cout << "Family Name: " << familyName1 << endl;
			cout << "Given Name : " << givenName1 << endl;
			cout << "CRA Account: " << socialNumber << endl;
		}

		// if the condition is false, display as below
		else {
			cout << "Account object is empty!" << endl;
		}

	}

}