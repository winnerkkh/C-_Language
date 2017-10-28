// Final Project Milestone 5
// AmaPersishable.cpp
// Version 1.0
// Date 7/8/2017
// Author Kyunghoon Kim (056-845-100)
// Email Address: khkim12@myseneca.ca
/////////////////////////////////////////////////////////////////

#include "AmaPerishable.h"
#include "Date.h"


namespace sict {

	//declare default cunstoructor to pass the value p for fileTag argument in AmaProduct
	AmaPerishable::AmaPerishable(char p) : AmaProduct(p) {

	}


	//getter for expiry_ with the value
	const Date& AmaPerishable::expiry()const {

		return expiry_;

	}


	//setter for expriy variable with the value
	void AmaPerishable::expiry(const Date &value) {

		expiry_ = value;
	}

	// call the parent's store function and save the data into file.
	fstream& AmaPerishable::store(fstream& file, bool addNewLine)const {

		// make the format if the condition falls in the false and state provided format
		AmaProduct::store(file, false);

		file << "," << expiry();

		// adding the new line if addNewLine is true
		if (addNewLine == true) {

			file << endl;
		}

		return file;
	}

	// call the parent's load function and load the data  from a file
	fstream& AmaPerishable::load(fstream& file) {

		// call load function and pass the argument as file
		AmaProduct::load(file);

		// read the file and ignore one chracter
		expiry_.read(file);

		return file;
	}

	// call the parent's wrtie function and write the data on the screen
	ostream& AmaPerishable::write(ostream& ostr, bool linear)const {

		// call write function
		AmaProduct::write(ostr, linear);

		// write the format if the condition matches
		if (err_.isClear() && !isEmpty()) {

			// linear is true then show only expiry data
			if (linear == true) {

				ostr << expiry_;
			}

			// if linear is false then show wite the statement and expiry date
			else {

				ostr << endl;
				ostr << "Expiry date: " << expiry_;
			}
		}

		return ostr;
	}


	// call the parent's read function and rea the data
	istream& AmaPerishable::read(istream& istr) {

		// create temp object
		Date tempObject;

		// call the read function
		AmaProduct::read(istr);

		//check if error is clear or not
		if (err_.isClear()) {

			// show the format if the condition match
			cout << "Expiry date (YYYY/MM/DD): ";

			//putting the data to data tempobject
			istr >> tempObject;

			//checking the type of error "CIN_FAILED"
			if (tempObject.errCode() == CIN_FAILED) {

				err_.message("Invalid Date Entry");
				istr.setstate(ios::failbit);
			}

			//checking the type of error "YEAR_ERROR"
			else if (tempObject.errCode() == YEAR_ERROR) {

				err_.message("Invalid Year in Date Entry");
				istr.setstate(ios::failbit);
			}

			//checking the type of error "MON_ERROR"
			else if (tempObject.errCode() == MON_ERROR) {

				err_.message("Invalid Month in Date Entry");
				istr.setstate(ios::failbit);
			}

			//checking the type of error "DAY_ERROR"
			else if(tempObject.errCode() == DAY_ERROR){

				err_.message("Invalid Day in Date Entry");
				istr.setstate(ios::failbit);
			}

			// set the expiry date of the object to the temporary Date object 
			else {

				expiry_ = tempObject;
			}
		}

		return istr;
	}
}
