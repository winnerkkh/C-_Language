/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File w2_at_home.cpp
// Version 1.0
// Date 5/30/2017
// Author KYUNGHOON KIM

// Description
// Please refer to each comments on TODO
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(Kingdom&);

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
    display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;

    // expand the array of Kingdoms by 1 element
    // TODO: allocate dynamic memory for count + 1 Kingdoms
	Kingdom *pKingdomNew = new Kingdom[count+1];

	//Create a new pointer array of Kingdom to copy the original information
	//because original information list is smaller (count = 2) but we want to add
	//1 more kindom so count + 1


    // TODO: copy elements from original array into this newly allocated array
	for (int i = 0; i < count; ++i) {
		pKingdomNew[i] = pKingdom[i];
	}

	//Readd back the old information pKingdom into the new kingdom (pKingdomNew)

    // TODO: deallocate the dynamic memory for the original array
	delete[] pKingdom;
	pKingdom = nullptr; // <--- optional(refer to text book)

	// delte the original information of old array because we want to use the same format
	// to put information into orgininal pKingdom later.

    // TODO: copy the address of the newly allocated array into pKingdom pointer
	pKingdom = pKingdomNew;

	// we originally use the array of pKingdome with new information later


	
    // add the new Kingdom

    cout << "==========\n"
        << "Input data\n"
        << "==========\n"
        << "Kingdom #" << count + 1 << ": " << endl;
   
	// TODO: accept input for the new element in the array
	read(pKingdom[count]);
	// for this part, count = 2 until count++ 0=>1, 1=>2, 2=>3 (Kingdom #1:)

    count++;
    cout << "==========\n" << endl;

    // testing that the overload of "display(...)" works
    display(pKingdom, count);
    cout << endl;

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
