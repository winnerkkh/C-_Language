// OOP244 Workshop 5: operators overloading
// File: w5_in_lab.cpp
// Version: 1.0
// Date: 2017/06/15
// Author: KYUNGHOON KIM
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////



// header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// create namespace
namespace sict {

	//define the Fraction class
	class Fraction {

		private:
			int numberators;
			int denominators;
		
		// make safe empty state function
			
			int gcd() const; // returns the greatest common divisor of num and denom
			int max() const; // returns the maximum of num and denom
			int min() const; // returns the minimum of num and denom
			void reduce();   // simplifies a Fraction by dividing the 
						 // numerator and denominator to their greatest common divisor 
	public:
		//declare the member functions
			Fraction();
			Fraction(int number, int denomi);

			bool isEmpty() const;
			void display() const;

		//declare the + operator overload
			Fraction operator+(const Fraction&);
	};
}
#endif