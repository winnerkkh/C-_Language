// Final Project Milestone 6
// AidApp.cpp
// Version 1.0
// Date 8/06/2017
// Author Kyunghoon Kim (056-845-100)
// Email Address: khkim12@myseneca.ca
/////////////////////////////////////////////////////////////////



#include "AidApp.h"

using namespace std;



namespace sict {


	// definition of constructor
	AidApp::AidApp(const char* filename) {

		//copy the argument to the variable file_name;
		strcpy(filename_, filename);

		for (int i = 0; i < MAX_NO_RECS; i++) {

			// initialize all the product_ elements to nullptr
			product_[i] = nullptr;
			
		}
		noOfProducts_ = 0;

		// call the loadRecs() function
		loadRecs();

	}

	// definition of pause function
	void AidApp::pause()const {

		// print the following sentence
		cout << "Press Enter to continue..." << endl;

		// flush the buffer after new line (based on the note, it recommend "2000"
		cin.ignore(2000, '\n');
	}

	// definition of menu function to list all the options
	int AidApp::menu() {

		int result = -1;
		bool selection= false;

		// list all the menu options
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "1- List products" << endl
			<< "2- Display product" << endl
			<< "3- Add non-perishable product" << endl
			<< "4- Add perishable product" << endl
			<< "5- Add to quantity of purchased products" << endl
			<< "0- Exit program" << endl;
		cout << "> ";

		// taking the user input for the seletion of option
		cin >> result;
		cout << endl;

		if (selection <= 5 && selection <= 0) {
			selection = true;
		}

		// clear the buffur
		cin.ignore();

		// return the result either -1 or the number selection
		return result;
	}


	// definition of the loadRecs function
	void AidApp::loadRecs() {


		//make a variable for chracter
		char idChracter;

		//Set readIndex to zero
		int readIndex = 0;

		//open the file with using ios:in
		datafile_.open(filename_, ios::in);



		//if fail to open datafile_, then close and close the file, and open the file again
		//and create a file to write
		if (datafile_.fail()) {

			datafile_.clear();
			datafile_.close();
			datafile_.open(filename_, ios::out);
			datafile_.close();

		}

		else {
			do {

				// deallocate the memory
				delete[] product_[readIndex];

				// taking the character to idCharacter
				datafile_ >> idChracter;

				if (datafile_.fail()) {
					idChracter = ' ';

				}

				// need to ignore comma (,)
				datafile_.ignore();

				// if it is P
				if (idChracter == 'P') {
					 
					// using AmaPerishable class and allocation memory
					Product* tempObj = new AmaPerishable();

					//load tempobject from datafile
					tempObj->load(datafile_);

					//assign the value to product_ variable
					product_[readIndex] = tempObj;

					//increase the size of readindex
					readIndex++;
				}

				// if it is N
				else if (idChracter == 'N') {

					//using non-pherishable class and allocation memory
					Product* tempObj = new AmaProduct();

					//load tempobject from datafile
					tempObj->load(datafile_);

					//assign the value to product_ variable
					product_[readIndex] = tempObj;

					//increase the size of readindex
					readIndex++;
				}

				else {

					product_[readIndex] = nullptr;
				}


			} while (!datafile_.fail());
			noOfProducts_ = readIndex;
			datafile_.close();
		}
	}


	// definition of the saveRecs function
	void AidApp::saveRecs() {

		// open the data file for wrting to save into the file
		datafile_.open(filename_, ios::out);

		//store the data file to each element of product_
		for (int i = 0; i < noOfProducts_; i++) {
			product_[i]->store(datafile_);
		}

		// clear the function to initialize and close the file.
		datafile_.close();
	}




	// definition of listProducts function
	void AidApp::listProducts()const {

		double totalOperator = 0;


		//display  GUI formatting
		cout << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl
			<<  "-----|--------|--------------------|-------|----|----------|----|----------" << endl;


		// list all the data through for loop
		for (int i = 0; i < noOfProducts_; i++) {

	

			// setting the format 
			cout.width(4);
			cout << i + 1 << " | ";


			// print the current product element 
			cout << *product_[i] << endl;

			// sum of all the list of price
			totalOperator += *product_[i];

			// if the list reches 10, then pause
			if ((i + 1) % 10 == 0) {
				pause();
			}

			
		}

		// footer
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Total cost of support: $" << totalOperator << endl << endl;
	}





	// definition of SearchProducts function
	int AidApp::SearchProducts(const char* sku) const {

		// make a variable to assign the return value
		int searchIndex = -1;


		//search the matching value through for loop
		for (int i = 0; i < noOfProducts_; i++) {
			if (*product_[i] == sku) {

				//assign i to search variable
				searchIndex = i;
				i = noOfProducts_;
			}
		}

		return searchIndex;
	}


	// definition of addquantity function
	void AidApp::addQty(const char* sku) {


		// assign the return value of searchproduct function
		int searchReturnValue = SearchProducts(sku);
		// variable for the purchased number
		int purchasedNum = 0;
		// variable for the limit of 
		int numOfAmoutLimit = product_[searchReturnValue]->qtyNeeded() - (product_[searchReturnValue]->quantity());
		

		// Giving the condition if the function returns -1
		if (searchReturnValue == -1) {

			// if the function return -1 then display the message
			cout << "Not found!" << endl;
		}

		// if the searchreturnvalue returns index i
		else {
			//display non-linear
			product_[searchReturnValue]->write(cout, false);
			cout << endl;

			// getting the value of purchased items
			cout << endl << "Please enter the number of purchased items: ";
			cin >> purchasedNum;

			// if the purchasednum variable does not match with the type from user input
			if (cin.fail()) {

				// clear the buffur value
				cin.ignore();

				// display the error message
				cout << "Invalid quantity value!" << endl;
			}

			else {
				//giving a condition if the purchased number is less than or equal to the amount required.
				if (purchasedNum <= numOfAmoutLimit) {

					//the if the condition above is true, 
					//then assign the purchased number value to the instance varialble in the product class 
					*product_[searchReturnValue] += purchasedNum;
				}

				// if the purchased num is not less than or equal which is greater, store only the max limit of purchsed number
				else {

					*product_[searchReturnValue] += numOfAmoutLimit;
					cout << "Too many items; only " << numOfAmoutLimit << " is needed, please return the extra " << (purchasedNum - numOfAmoutLimit) << " items." << endl;
				}

				// save the all the records 
				saveRecs();

				// display the message that all the record updated
				cout << endl << "Updated!" << endl;
				cout << endl;
				cin.clear();
			}
		}

	}

	// definition of addProduct function
	void AidApp::addProduct(bool isPerishable) {
	
		//declare new object
		Product* product;

		//allocation to amaPerishable or amaProduct beased on the argument return value
		if (isPerishable == true) {

			// allocation of AmaPerishable;
			product = new AmaPerishable;
		}

		else {

			// allocation of AmaProduct
			product = new AmaProduct;
		}

		
		product->read(cin);

		if (cin.fail()) {

			product->write(cout, false);
			cin.clear();
			cin.ignore(2000, '\n');
		}

		else {

			product_[noOfProducts_] = product;
			noOfProducts_++;
			saveRecs();
			cout << endl;
			cout << "Product added" << endl;
			cout << endl;

		}
	}



	// definition of run function
	int AidApp::run() {
	
		// declare variables to run switch function
		int option;
		int exitFlag = 0;
		int output = 0;
		
		do {
	
			option = menu();
			switch (option) {

			case 1:
				// list all products
				listProducts();
				pause();
				break;


			case 2:
				
				// searching the function index ( doesn't return index number if the condition is false, return -1 
				char sKuReceivingValue[FILE_NAME_LENGTH];

				cout << "Please enter the SKU: ";

				//receving the sku number from the user
				cin >> sKuReceivingValue;
				cin.ignore();
				cout << endl;
				output = SearchProducts(sKuReceivingValue);
				// searching the sku, if cannot find it, returns -1
				if (output == -1) {

					// diplay the message
					cout << "Not found!" << endl << endl;
				}


				else {

					// returns index number from searchproduct function and write it 
					// putting the false because of the formating vertical by putting false'
					product_[output]->write(cout, false);
					cout << endl << endl;
				}

				pause();
				break;

			case 3:

				// call the non=perishable product function by having the argument false
				addProduct(false);
				break;

			case 4:
				// call the perishable product function by having the argument true
				addProduct(true);
				break;

			case 5:

				char findingSku[FILE_NAME_LENGTH];

				cout << "Please enter the SKU: ";
				cin >> findingSku;
				cout << endl;
				cin.ignore();

				addQty(findingSku);
				break;


			case 0:
				// exit display
				cout << "Goodbye!!" << endl;

				//exitFlag turns to 1
				exitFlag = 1;
				break;



			default:

				cout << "===Invalid Selection, try again.===" << endl;
				break;
			}

		} while ( exitFlag != 1);
		return 0;
	}
}


