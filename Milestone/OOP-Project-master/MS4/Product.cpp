// Final Project Milestone 4
// Version 1.0
// Date 7/14/2017
// Author Kyunghoon Kim (056-845-100)
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Product.h"

using namespace sict;
using namespace std;

namespace sict {

	// implementation of the no argument constructor
	Product::Product() {
		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0.0;
		taxed_ = true;
		quantity_ = 0;
		qtyNeeded_ = 0;

	}

	// implementation of five argument constructor

	Product::Product(const char* skuBarcode, const char* nameName, bool taxTaxed, double pricePrice, int needquantity) {

		// use setter functions (saving time)
		sku(skuBarcode);
		name(nameName);
		price(pricePrice);
		taxed(taxTaxed);
		qtyNeeded(needquantity);

		//quantity must set as 0
		quantity_ = 0;
	}


	//assgin to current object
	Product& Product::operator=(const Product& givenObject) {

		// double check if the instance variables match with givenObject
		if (this != &givenObject) {

			//assigne givenObject members to current object's variables
			sku(givenObject.sku_);
			name(givenObject.name_);
			price(givenObject.price_);
			taxed(givenObject.taxed_);
			qtyNeeded(givenObject.qtyNeeded_);
			quantity(givenObject.quantity_);
		}
		else {
			name_ = nullptr;
		}

		//return currect object of variables
		return *this;
	}

	// copy constructor from assgined operator
	Product::Product(const Product& givenObject1) {
		name_ = nullptr;
		*this = givenObject1;
	}

	// implementation of destructor
	Product::~Product() {

		delete[] name_;
		name_ = nullptr;
	}

	//implementation of setters for the instance members
	void Product::sku(const char *sku) {

		// set the sku value to instance member
		if (sku != nullptr) {
			strncpy(sku_, sku, MAX_SKU_LEN);
			sku_[MAX_SKU_LEN] = '\0';
		}
	}

	void Product::name(const char *name) {
		if (name != nullptr) {
			// declare temp variable fo the re-use
			int length = strlen(name) + 1;

			//allocate the dynamic memory to the pointer value of name
			name_ = new char[length + 1];
			strncpy(name_, name, length);
			name_[length] = '\0';
		}
	}

	void Product::price(double price) {

		// set the price value to instance member
		price_ = price;
	}

	void Product::taxed(bool taxed) {

		// set the tax to instance member
		taxed_ = taxed;
	}

	void Product::quantity(int quantity) {

		// set the quantity to instance member
		quantity_ = quantity;
	}

	void Product::qtyNeeded(int qtyNeeded) {

		// set the qty Needed to instance member
		qtyNeeded_ = qtyNeeded;
	}


	//implementation of getters for the instance members
	const char *Product::sku() const {

		// get the sku 
		return sku_;
	}

	double Product::price() const {

		// get the price
		return price_;
	}

	const char *Product::name() const {

		// get name
		return name_;
	}
	bool Product::taxed() const {

		// get taxed
		return taxed_;
	}

	int Product::quantity() const {

		// get quantity
		return quantity_;
	}

	int Product::qtyNeeded() const {

		// get the number of quantity needed
		return qtyNeeded_;
	}



	//implementation of cost function
	//(If the Product is not taxed the return value of cost() will be the same as price)

	double Product::cost() const {

		double result = 0.0;

		if (taxed_ == true) {

			result = price() * (TAX + 1);
		}

		else {

			result = price();
		}

		return result;
	}


	//implementation isEmpty function to check if the product is has value or not
	bool Product::isEmpty() const {

		bool result = false;

		if (sku_[0] == '\0' && name_ == nullptr && price_ == 0.0 && taxed_ == true && quantity_ == 0 && qtyNeeded_ == 0) {

			result = true;
		}

		return result;
	}


	// implemenation of member ==operator overload
	bool Product:: operator==(const char* givenObject) const {

		bool result = false;
		if (strcmp(sku_, givenObject) == 0) {

			result = true;
		}

		return result;
	}


	//implementation of member += operator overload

	int Product::operator+=(int addingNumberQty) {

		return quantity_ += addingNumberQty;
	}

	//implementation of member -= operator overload

	int Product::operator-=(int substractingNumberQty) {

		return quantity_ -= substractingNumberQty;
	}

	//implementation of Non-Member operator overload
	double operator+=(double& totalCost, const Product& quantityOfProduct) {

		return totalCost += (quantityOfProduct.quantity() * quantityOfProduct.cost());
	}


	//implementation of Non-member IO operator overloads
	ostream& operator<<(ostream& ostr, const Product& show) {
		return show.write(ostr, true);
	}

	istream& operator >> (istream& istr, Product& show) {
		return show.read(istr);
	}


}

