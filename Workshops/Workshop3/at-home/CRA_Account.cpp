/***********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 1.1
// Date 6/06/2017
// Author Kyunghoon Kim
***********************************************************/

#include <iostream>
#include<string.h>
#include "CRA_Account.h"
using namespace std;

namespace sict {

	//Set function
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		socialNumber = sin;

		if (isValid()) {

			strcpy(familyName1, familyName);
			strcpy(givenName1, givenName);
			m_years = 0;
		}

		else {
			strcpy(familyName1, "");
			strcpy(givenName1, "");
			socialNumber = -1;
		}
	}

	// isValid function
	bool CRA_Account::isValid() const {

		bool socialNumber2;
		const int NUMOFSIN = 9;
		int temp[NUMOFSIN];
		int tempSin = socialNumber;
		int sumOfeven = 0;
		int addTemp = 0;
		int oneInt;
		int highInt;

		// store each integer into temp[i] separately
		for (int i = NUMOFSIN - 1; i >= 0; i--) {
			temp[i] = tempSin % 10;
			tempSin /= 10;
		}

		// sum of element number of index 0,2,4,6 value  
		for (int i = 0; i <NUMOFSIN - 1 ; i++) {
			if (i % 2 == 0) {
				sumOfeven += temp[i];
			}
		// sum of even index 1, 3, 5, 7
			else {
				addTemp = temp[i] * 2;

				if (addTemp >= 10) {
					sumOfeven += addTemp % 10;
					addTemp /= 10;
				}
				sumOfeven += addTemp;
			}
		}

		//final sum
		oneInt = ((sumOfeven / 10) + 1) * 10;
		highInt = oneInt-sumOfeven;
		

		//Checking if the user input is valid or not 
		if (socialNumber >= MIN_SIN && socialNumber <= MAX_SIN && socialNumber && highInt==temp[NUMOFSIN-1]) {
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
			for (int i = 0; i < MAX_YRS; i++) {
				
				cout.setf(ios::fixed);
				cout.precision(2);
					
				if (m_balance[i] > 0 && m_balance[i] > 2) {
					cout << "Year (" << m_year[i] << ") balance owing: " << m_balance[i] << endl;
				}
				else if (m_balance[i] < 0 && (m_balance[i]*-1) > 2) {
					cout << "Year (" << m_year[i] << ") refund due: " << m_balance[i]*-1 << endl;
				}
				else {
					cout << "Year (" << m_year[i] << ") No balance owing or refund due!" << endl;
				}
			}
		}

		// if the condition is false, display as below
		else {
			cout << "Account object is empty!" << endl;
		}

	}

	// store the array of year and balance
	void CRA_Account::set(int year, double balance) {
		if (m_years < MAX_YRS && isValid()) {
			m_year[m_years] = year;
			m_balance[m_years] = balance;
			m_years++;
		}	
	}

}