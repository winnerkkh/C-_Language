// Final Project Milestone 5
// AmaProduct.cpp
// Version 1.0
// Date 7/8/2017
// Author Kyunghoon Kim (056-845-100)
// Email Address: khkim12@myseneca.ca
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS


#include <cstring>
#include <fstream>
#include <cstring>
#include <string> // using for string built in function
#include "AmaProduct.h"


using namespace std;

namespace sict {

	//declare the constructor of the class that receive one argument and assign to filetag variable
	//default vale is as N
	AmaProduct::AmaProduct(char filetag) {

		fileTag_ = filetag;
	}

	//returns a constant pointer (get function)
	const char* AmaProduct::unit()const {

		return unit_;
	}

	// function that copies the char value into the variable "unit_"
	void AmaProduct::unit(const char* value) {

		strncpy(unit_, value, strlen(value) + 1);

		// make sure the last element must be nullptr
		unit_[10] = '\0';
	}


	// store(writing) the data into the file
	fstream& AmaProduct::store(fstream& file, bool addNewLine)const {


		// if the addNewline is true, then add newline
		if (addNewLine == true) {

			file << fileTag_ << ',' << sku() << ',' << name() << ',' << price() << ',' << taxed() << ',' <<quantity() << ',' << unit() << ',' << qtyNeeded() << endl;
		}

		//following format is sku, name, price, taxed, quantity, unit, quantity needed 
		else {

			file << fileTag_ << ',' << sku() << ',' << name() << ',' << price() << ',' << taxed() << ',' << quantity() << ',' << unit() << ',' << qtyNeeded();
		}

		return file;
	}


	// reading a data from file and assign to variable
	fstream& AmaProduct::load(fstream& file) {

		//declare the temporary variable to save the data from a file
		int intData;
		double doubleData;
		bool isTaxed;
		string stringData;


		//reading a data from a file, store it into the temporary variable, ignore(stop reading untill meeting the character ",")
		getline(file, stringData, ',');
		//assign the data into the variable, 
		//c_str() is returning the string data's pointer 
		sku(stringData.c_str());

		getline(file, stringData, ',');
		name(stringData.c_str());

		// price is a double type; thus, getline function doesn't work but use operator >>
		file >> doubleData;
		price(doubleData);
		file.ignore();

		// taxed data "true or false
		file >> isTaxed;
		taxed(isTaxed);
		file.ignore();
		
		//quantity data 
		file >> intData;
		quantity(intData);
		file.ignore();

		//unit data(string) - pointer
		getline(file, stringData, ',');
		unit(stringData.c_str());

		// quantity needed data
		file >> intData;
		qtyNeeded(intData);
		file.ignore();

		return file;
	}

	// 
	ostream& AmaProduct::write(ostream& os, bool linear)const {

		if (!err_.isClear()) {

			os << err_.message();
		}

		else {
			if (linear == true) {

				//set the format for sku (left justified in MAX_UPC_LEN characters)
				os.setf(ios::left);
				os.width(MAX_SKU_LEN);
				os << sku() << "|";

				// set the format for name (left justified 20 characters wide (truncated if longer than 20 chars)
				os.width(20);
				os << name() << "|";

				// set the format for cost((not the price) right justified, 2 digits after decimal point 7 chars wide)
				os.unsetf(ios::left); // unset the left position 
				os.setf(ios::right);
				os.setf(ios::fixed);
				os.width(7); // 7 characters
				os.precision(2); //2 digits 
				os << cost() << "|";

				// set the format for qty on had (right justified 4 characters wide)
				os.width(4); // 4 characters
				os << quantity() << "|";

				// set the format for Unit (left justified 10 characters wide)
				os.unsetf(ios::right);
				os.setf(ios::left);
				os.width(10);
				os << unit() << "|";

				// set the format for Quantity needed: right justified 4 characters wide
				os.unsetf(ios::left);
				os.setf(ios::right);
				os.width(4);
				os << qtyNeeded()<< "|" ;
				os.unsetf(ios::right);
			}

			else {
				// if the linear is false then show the formar as below
				os << "Sku: " << sku() << endl;
				os << "Name: " << name() << endl;
				os << "Price: " << price() << endl;

				if (taxed() == true) {
					os << "Price after tax: " << cost() << endl;
				}

				else {
					os << "Price after tax: " << "N/A" << endl;
				}

				os << "Quantity On Hand: " << quantity() <<" " << unit() << endl;
				os << "Quantity Needed: " << qtyNeeded();
			}
		}
		return os;
	}


	// read the file ( the logic for this function is nested)
	istream& AmaProduct::read(std::istream& istr) {

		// declare the temp variables to store the data
		int intqty;
		int intqtyneed;
		char chartaxed;
		double doubleprice;
		string stringSku;
		string stringName;
		string stringUnit;


			// read stored Sku variable 
			if (!istr.fail()) {
				cout << "Sku: ";
				istr >> stringSku;
				istr.ignore();

			// read stored Name variable
			if (!istr.fail()) {
				cout << "Name: ";
				istr >> stringName;
				name(stringName.c_str());
				istr.ignore();
			}

			// read Unit variable
			if (!istr.fail()) {
				cout << "Unit: ";
				istr >> stringUnit;
				istr.ignore();
			}

			// read taxed if the taxed is adusted or not with specified character
			//
			if (!istr.fail()) {
				cout << "Taxed? (y/n): ";
				istr >> chartaxed;
				if (chartaxed == 'Y' || chartaxed == 'y' || chartaxed == 'N' || chartaxed == 'n') {
					istr.ignore();

					//stored to temp variable for Price to store it in to the variable
					cout << "Price: ";
					istr >> doubleprice;
					istr.ignore();

					//stored to temp variable for quantity to store it in to the variable
					if (!istr.fail()) {
						cout << "Quantity On hand: ";
						istr >> intqty;
						istr.ignore();

						//stored to temp variable for quantityneeded to store it in to the variable
						if (!istr.fail()) {
							cout << "Quantity Needed: ";
							istr >> intqtyneed;

							// store all of temp variables to the instance varia ble to read
							if (!istr.fail()) {

								name(stringName.c_str());
								unit(stringUnit.c_str());
								sku(stringSku.c_str());
								price(doubleprice);
								quantity(intqty);
								qtyNeeded(intqtyneed);
								if (chartaxed == 'Y' || chartaxed == 'y') {
									taxed(true);
								}
								else {
									taxed(false);
								}
								err_.clear();
							}
							// show the error message if the condition doesn't match with given statement.
							else {
								err_.message("Invalid Quantity Needed Entry");
							}
						}
						// show the error message if the condition doesn't match with given statement.
						else {
							err_.message("Invalid Quantity Entry");
						}
					}
					// show the error message if the condition doesn't match with given statement.
					else {
						err_.message("Invalid Price Entry");
					}
				}
				else {
					// show the error message if the condition doesn't match with given statement.
					err_.message("Only (Y)es or (N)o are acceptable");
					istr.setstate(ios::failbit);
				}
			}
		}
		return istr;
	}

}

