/***********************************************************
// Workshop 4: CONSTRUCTORS(lab)
// Passenger.cpp
// Date 6/08/2017
// Author Kyunghoon Kim
***********************************************************/


// headers and namespace
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict {

	//make empty statement for objective
	Passenger::Passenger() {

		 strncpy(passengerName, "", LENGTH - 1 );
		 strncpy(passengerDestination, "", LENGTH - 1);

		 passengerName[LENGTH - 1] = '\0';
		 passengerDestination[LENGTH-1] = '\0';
	}
	
	//constructor with 2 parameters here
	Passenger::Passenger(const char* pName, const char* destinationName) {
		// compare the strings
		if (pName != nullptr && destinationName != nullptr && strcmp(pName, "") != 0 && strcmp(destinationName,"") != 0) {
			strncpy(passengerName, pName, LENGTH - 1);
			strncpy(passengerDestination, destinationName, LENGTH - 1);
		}
		
		// make instance variables as empty statement
		else {
			*this = Passenger();
			
		}

	}



    //implement isEmpty query 
	bool Passenger::isEmpty() const {
		
		bool confirm = false;
		
		if(strcmp(passengerName, "") == 0 && strcmp(passengerDestination, "") == 0){
		//if (passengerName != nullptr && passengerDestination != nullptr) {
			confirm = true;
		}

		return confirm;
	}


	//disply passenger info
	void Passenger::display() const {
		cout << passengerName << " - " << passengerDestination << endl;
	}
}