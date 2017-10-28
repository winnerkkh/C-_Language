/***********************************************************
// Workshop 4: CONSTRUCTORS(home)
// Passenger.cpp
// Date 6/13/2017
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

		 strncpy(passengerName, "", LENGTH);
		 strncpy(passengerDestination, "", LENGTH);

		 passengerName[LENGTH - 1] = '\0';
		 passengerDestination[LENGTH - 1] = '\0';
	}
	
	//constructor with 2 parameters here
	Passenger::Passenger(const char* pName, const char* destinationName) {
		// compare the strings
		if (pName != nullptr && destinationName != nullptr && strcmp(pName, "")
			!= '\0' && strcmp(destinationName,"") != '\0') {
			strncpy(passengerName, pName, LENGTH);
			strncpy(passengerDestination, destinationName, LENGTH);

			passengerName[LENGTH - 1] = '\0';
			passengerDestination[LENGTH - 1] = '\0';
		}
		
		// make instance variables as empty statement
		else {
			*this = Passenger();
			
		}

	}


	// Another constructor with 5 parameters here
	Passenger::Passenger(const char* pName, const char* destinationName, int yearD, int monthD, int daysD) {
		if (yearD<=2020 && yearD>=2017 && monthD<=12 && monthD>=1 && daysD <= 31 && daysD>=1) {
			
			// compare the strings && assign instance variables with the values
			*this = Passenger(pName, destinationName);
			
			//assign instance variables with the values
			if (!isEmpty()) {
				yearOfDeparture = yearD;
				monthOfDeparture = monthD;
				dayOfDeparture = daysD;
			}
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
		//less than october, there must be 0 in the each month
		if (monthOfDeparture < 10) {
			cout << passengerName << " - " << passengerDestination << " on " << yearOfDeparture << "/0" << monthOfDeparture << "/" << dayOfDeparture << endl;
		}
		
		else{
			cout << passengerName << " - " << passengerDestination << " on " << yearOfDeparture << "/" << monthOfDeparture << "/" << dayOfDeparture << endl;
		}
	}


	// returns passengername function
	const char* Passenger::name() const {
		return passengerName;
	}


	// checking the same destination, date, month, days and year with other passengers 
	bool Passenger::canTravelWith(const Passenger& passengerN) const {
		bool result = false;
		
		if (strcmp(passengerN.passengerDestination, passengerDestination) == 0 && passengerN.yearOfDeparture == yearOfDeparture&& passengerN.monthOfDeparture == monthOfDeparture && passengerN.dayOfDeparture) {
				
			result = true;
		}

		return result;

	}

}