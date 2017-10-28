// OOP244 Workshop 6: CLASS WITH A RESOURCE
// File: Contact.cpp
// Version: 1.0
// Date: 2017/06/22
// Author: KYUNGHOON KIM
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

// ignore warning message
#define _CRT_SECURE_NO_WARNINGS


//insert header files
#include <iostream>
#include <cstring>
#include "Contact.h"




//using namespace
using namespace std;


//declare the namespace sict
namespace sict {

	//declare the constructor to initialize members
	Contact::Contact() {
		strncpy(memberName, "", MAX_CHARACTER_LENGTH);
		memberName[MAX_CHARACTER_LENGTH - 1] = '\0';
		phoneNumber = nullptr;
		phoneNumberNumber = 0;
	}

	//overload constructor with 3 parameters
	Contact::Contact(const char* personName, long long* pNumber, int noOfNumber) {

		// Check if the person name is empty
		if (personName != nullptr && strcmp(personName, "") != 0) {
			strncpy(memberName, personName, MAX_CHARACTER_LENGTH);
			memberName[MAX_CHARACTER_LENGTH - 1] = '\0';
			phoneNumberNumber = 0;

			if (pNumber != nullptr) {

				//allocating dynamic memory of array
				phoneNumber = new long long[noOfNumber];
				
				for (int i = 0; i < noOfNumber; i++) {

					// similar to ipc workshop of finding phone numbers
					int areaCode = (pNumber[i] / 10000000) % 1000;
					if (areaCode == 416) {
						phoneNumber[phoneNumberNumber] = pNumber[i];
						phoneNumberNumber++;
					}
				}
			}
		}

		//if the condition doesn't match, return to the default constructor
		else {
			phoneNumber = nullptr;
			*this = Contact();
		}
	}

	//deallocate of phonnumber array
	Contact::~Contact() {
		delete[] phoneNumber;
	}
	bool Contact::isEmpty() const {
		bool check = false;
		if (strcmp(memberName,"") == 0 && phoneNumber == nullptr && phoneNumberNumber == 0) {
			check = true;
		}
		return check;
	}


	// display function
	void Contact::display() const {

		long long fullPnumber;
		int count = 0;

		//No record, then show this message
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}

		else {
			cout << memberName << endl;
			
			while (count != phoneNumberNumber) {
				fullPnumber = phoneNumber[count];
				cout << "(+" << (fullPnumber / 10000000000) << ") " << ((fullPnumber / 10000000) % 1000) << " " << ((fullPnumber % 10000000) / 10000) << "-" << (fullPnumber % 10000) << endl;
				count++;
			}
		}
	}
}

