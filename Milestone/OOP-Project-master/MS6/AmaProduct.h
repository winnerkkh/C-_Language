// Final Project Milestone 5
// AmaProduct.h
// Version 1.0
// Date 7/8/2017
// Author Kyunghoon Kim (056-845-100)
// Email Address: khkim12@myseneca.ca
/////////////////////////////////////////////////////////////////



#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__

#include <iostream>
#include "Product.h"
#include "ErrorMessage.h"


namespace sict {

	// declare the class which is derived from a Product class
	// child class(derived class) : parent class
	class AmaProduct : public Product { 

		//declare instance members
	private:
		
		//Holds a single character to tag the records as Perishable or non-Perishable product in a file
		char fileTag_; 

		//Unit of Measurement
		char unit_[11];

	protected:

		//create a new object err_ from ErrorMessage class
		ErrorMessage err_;

	public:

		// declare constructor with a default value 'N'
		AmaProduct(char filetag = 'N');

		// declare unit function to return a constant pointer
		const char* unit()const;

		// declare overloading function of unit
		void unit(const char* value);
		std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& istr);
	};
}
#endif