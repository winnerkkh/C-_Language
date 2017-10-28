// OOP244 Workshop 6: CLASS WITH A RESOURCE - Home part
// File: Contact.h
// Version: 1.0
// Date: 2017/06/27
// Author: KYUNGHOON KIM
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

// header file guard
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

// create namespace
namespace sict {
	
	//declare the length of chracter for array
	const int MAX_CHARACTER_LENGTH = 20;

	//declare the class of contact
	class Contact {

		//declare the instance members
		char memberName[MAX_CHARACTER_LENGTH];
		long long* phoneNumber;
		int phoneNumberNumber;

		//declare the public functions with constructor and destructor
	public:

		// default constructor
		Contact();

		// overload cunstructor with 3 parameters
		Contact(const char* personName, long long* pNumbers, int nOfnumbers);

		// destructor
		~Contact();

		// display function
		void display() const;

		// empty functio for the safety
		bool isEmpty() const;

		//copy constructor
		Contact(const Contact& tempObject);


		Contact& operator=(const Contact& tempObject2);
		
		// overloading += operator
		Contact& operator+=(long long);
	};
}
#endif