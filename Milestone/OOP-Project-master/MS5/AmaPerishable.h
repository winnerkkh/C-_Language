// Final Project Milestone 5
// AmaPerishable.h
// Version 1.0
// Date 7/26/2017
// Author Kyunghoon Kim (056-845-100)
// Email Address: khkim12@myseneca.ca
/////////////////////////////////////////////////////////////////



#ifndef SICT_AmaPerishable_H__
#define SICT_AmaPerishable_H__

#include <iostream>
#include "AmaProduct.h"
#include "Date.h"
#include <fstream>


using namespace std;

namespace sict {

	class AmaPerishable : public AmaProduct {

	private:
		Date expiry_;


	public:

		//declare constructor with only one default constructor
		AmaPerishable(char = 'P');
		
		// getter
		const Date& expiry()const;

		// setter
		void expiry(const Date &value);

		std::fstream& store(std::fstream& file, bool addNewLine = true)const;

		std::fstream& load(std::fstream& file);

		std::ostream& write(std::ostream& ostr, bool linear)const;

		std::istream& read(std::istream& istr);

	};

}
#endif