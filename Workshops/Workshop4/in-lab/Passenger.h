/***********************************************************
// Workshop 4: CONSTRUCTORS (lab)
// Passenger.h
// Date 6/08/2017
// Author Kyunghoon Kim
***********************************************************/

// guard header file
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H


namespace sict {

#define LENGTH 32


	// declare passenger class
	class Passenger {
	
	// declare instance variables
	private:
		char passengerName[LENGTH + 1];
		char passengerDestination[LENGTH + 1];


	// declare member functions 
	public:
		Passenger();
		Passenger(const char* pName, const char* destinationName);
		bool isEmpty() const;
		void display() const;
	};
}
#endif

