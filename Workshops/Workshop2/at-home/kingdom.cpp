/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 5/30/2017
// Author Kyunghoon Kim
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;


// TODO: the sict namespace

namespace sict {

	// TODO:definition for display(...) 

	void display(const struct Kingdom &kingdom) {
		cout << kingdom.m_name<< ", population " << kingdom.m_population << endl;	
	};


	void display(const struct Kingdom *kingdom, int numberOfRec) {
		int totalV = 0;
			cout << "------------------------------" << endl;
			cout << "Kingdoms of SICT" << endl;
			cout << "------------------------------" << endl;
		
			for (int i = 0; i < numberOfRec; i++) {
			cout << i + 1 << ". " << kingdom[i].m_name <<", population " << kingdom[i].m_population << endl;
			totalV += kingdom[i].m_population; // sum all array value of kingdom i		
		}

			cout << "------------------------------" << endl;
			cout << "Total population of SICT: " << totalV<<endl;
			cout << "------------------------------" << endl;
	}

}








