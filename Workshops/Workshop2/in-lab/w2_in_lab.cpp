/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File w2_in_lab.cpp
// Version 1.0
// Date 5/25/2017
// Author Kyunghoon Kim
*/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array

    // TODO: declare the pKingdom pointer here (don't forget to initialize it)
	Kingdom *pKingdom = nullptr;
	
    cout << "==========\n"
         << "Input data\n"
         << "==========\n"
         << "Enter the number of kingdoms: ";
    cin >> count;
    cin.ignore();

    if (count < 1) return 1;

    // TODO: allocate dynamic memory here for the pKingdom pointer
	pKingdom = new Kingdom[count];

    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;

        // TODO: add code to accept user input for Kingdom i
		read(pKingdom[i]);

    }
    cout << "==========" << endl << endl;

    // testing that "display(...)" works
    cout << "------------------------------" << endl
        << "The first kingdom entered is" << endl
        << "------------------------------" << endl;
    sict::display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;

    // TODO: deallocate the dynamic memory here
	delete[] pKingdom;

    return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {

    cout << "Enter the name of the kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}
