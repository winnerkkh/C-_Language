// OOP244 Workshop 5: operators overloading
// File: w5_in_home.cpp
// Version: 1.0
// Date: 2017/06/15
// Author: KYUNGHOON KIM
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////


//insert header files
#include <iostream>
#include "Fraction.h"

//using namespace
using namespace std;


//declare the namespace sict
namespace sict {

	// declare implement the default constructor
	Fraction::Fraction() {

		numberators = 0;
		denominators = 0;

	}


	// make implement the two-argument constructor
	Fraction::Fraction(int number, int denomi) {

		if (number > 0 && denomi > 0) {

			numberators = number;
			denominators = denomi;
			reduce();
		}

		else {

			*this = Fraction();
		}


	}

	// implement the max query
	// max returns the maximum of the numerator and denominator
	int Fraction::max() const {
		int resultMnumber = 0;

		if (numberators > denominators) {

			resultMnumber = numberators;
		}

		else if (denominators > numberators) {

			resultMnumber = denominators;
		}

		return resultMnumber;
	}


	// implement the min query
	int Fraction::min() const {
		int resultNnumber = 0;

		if (denominators > numberators) {

			resultNnumber = numberators;
		}

		else if (numberators > denominators) {

			resultNnumber = denominators;
		}

		return resultNnumber;
	}


	// implement the min query
	// min returns the maximum of the numerator and denominator
	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();
		int mx = max();
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}


	// implement the reduce modifier
	// reduce simplifies the fraction by dividing the numerator and denominator by the greatest common divisor
	void Fraction::reduce() {


		//prevent changing the values of gcd
		// make a new temp 
		int temp = gcd();

		numberators /= temp;
		denominators /= temp;

	}

	// implement the display query
	// display inserts num/denom into the output stream
	void Fraction::display() const {

		if (denominators == 1) {

			cout << numberators;
		}

		else if (numberators > 0 && denominators > 0) {
			cout << numberators << "/" << denominators;
		}

		else {
			cout << "no fraction stored";
		}
	}


	// implement the isEmpty query
	// isEmpty returns true if Fraction object is in a safe empty state

	bool Fraction::isEmpty() const {

		bool confrim = false;

		if (numberators == 0 && denominators == 0) {

			confrim = true;
		}
		return confrim;
	}

	// implement the + operator
	// + operator adds the rhs to the current object and reduces the result
	Fraction Fraction:: operator+(const Fraction& tempOtherFraction) const {

		Fraction tempFirstFraction = *this;

		//if both num and deno are valid
		if (!tempFirstFraction.isEmpty() && !tempOtherFraction.isEmpty()) {

			//caculating addtion
			tempFirstFraction.numberators = (tempFirstFraction.denominators *tempOtherFraction.numberators) + (tempOtherFraction.denominators * tempFirstFraction.numberators);
			tempFirstFraction.denominators = (tempFirstFraction.denominators * tempOtherFraction.denominators);
		}
		tempFirstFraction.reduce();

		return tempFirstFraction;
	}

	// implement the * operator
	Fraction Fraction:: operator*(const Fraction& tempOtherFraction) const {

		Fraction tempFirstFraction = *this;

		//if both num and deno are valid
		if (!tempFirstFraction.isEmpty() && !tempOtherFraction.isEmpty()) {

			//caculating multiplication
			tempFirstFraction.numberators = tempFirstFraction.numberators *tempOtherFraction.numberators;
			tempFirstFraction.denominators = tempFirstFraction.denominators * tempOtherFraction.denominators;
		}

		tempFirstFraction.reduce();

		return tempFirstFraction;


	}


	// implement the == operator
	bool Fraction:: operator==(const Fraction& tempOtherFraction) const {

		bool result = false;

		if (!isEmpty() && !tempOtherFraction.isEmpty() && numberators == tempOtherFraction.numberators && denominators == tempOtherFraction.denominators) {

			result = true;

		}

		return result;
	}


	// implement the != operator
	bool Fraction:: operator!=(const Fraction& tempOtherFraction) const {

		bool result = true;


		// passing in the currect object for == operator and parameter from above and make equation opposite.
		if (*this == tempOtherFraction || isEmpty() || tempOtherFraction.isEmpty()) {
			result = false;

		}

		return result;
	}



	// implement the += operator
	Fraction Fraction:: operator+=(const Fraction& tempOtherFraction) {

		if (!isEmpty() && !tempOtherFraction.isEmpty()) {
			*this = *this + tempOtherFraction;

		}

		return *this;
	}
}

