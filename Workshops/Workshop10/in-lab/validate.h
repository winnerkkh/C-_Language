// Workshop 10: Function Templates 
// File: validate.h
// Date: 2017/0/8/03
// Name: Kyunghoon Kim
// Student No: 056-845-100
// Student Email: khkim12@myseneca.ca




#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_

#include <iostream>

// include other headers
#include "Car.h"
#include "Employee.h"
#include "Student.h"


namespace ict {

	//declare the template function with a type identifier which is T1
	template <typename T>

	// declare validate function with 5 different parameters using template T
	bool validate(const T& minRange, const T&  maxRange, const T* testValueRange, int numElement, bool* resultResult) {
		bool result = true;

		// checking the each element i if the argument of min and max are true or not.
		for (int i = 0; i < numElement; i++) {

			// true if min is less than the test value and max is greater than the testvalue
			if (testValueRange[i] >= minRange && testValueRange[i] <= maxRange) {

				resultResult[i] = true;
			}

			else {

				resultResult[i] = false;
			}

			// assign the bool type into the bool type variable of its validate function.
			if (resultResult[i] == false) {
				result = false;
			}
		}
		return result;
	}
}
#endif