/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 5/25/2017
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
}








