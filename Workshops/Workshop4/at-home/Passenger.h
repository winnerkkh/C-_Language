/***********************************************************
// Workshop 4: CONSTRUCTORS (home)
// Passenger.h
// Date 6/13/2017
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
		char passengerName[LENGTH];
		char passengerDestination[LENGTH];
		int yearOfDeparture;
		int monthOfDeparture;
		int dayOfDeparture;


	// declare member functions 
	public:
		Passenger();
		Passenger(const char* pName, const char* destinationName);
		bool isEmpty() const;
		void display() const;
	
	// declare member fuctions (lab part)	
		Passenger(const char* pName, const char* destinationName, int yearD, int monthD, int daysD);
		const char* name() const;
		bool canTravelWith(const Passenger&) const;

	};
}
#endif

