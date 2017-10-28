// Final Project Milestone 4
// Product.h
// Date 7/14/2017
// Author Kyunghoon Kim (056-845-100)
/////////////////////////////////////////////////////////////////


#ifndef SICT_PRODUCT_H__
#define SICT_PRODUCT_H__

#include <iostream>
#include "general.h"
#include "Streamable.h"

namespace sict {

	// declare the class of Product
	class Product : public Streamable{


		private:

			// declare the private instance members
			char sku_[MAX_SKU_LEN + 1];
			char *name_;
			double price_;
			bool taxed_;
			int quantity_;
			int qtyNeeded_;


		public:

			// declare no argument constructor
			Product();
			
			// declare five argument constructor
			Product(const char* skuBarcode, const char* nameName, bool taxTaxed = true, double pricePrice = 0.0, int needquantity = 0);

			// declare assigning to current object members
			Product& operator=(const Product& givenObject);

			// declare copy constructor
			Product(const Product& givenObject1);

			// declare destructor
			virtual ~Product();

			// declare setters
			void sku(const char *sku);
			void name(const char *name);
			void price(double price);
			void taxed(bool taxed);
			void quantity(int quantity);
			void qtyNeeded(int qtyNeeded);



			//declare getters
			const char *sku() const;
			double price() const;
			const char *name() const;
			bool taxed() const;
			int quantity() const;
			int qtyNeeded() const;

			//declare cost function
			double cost() const;

			//declare isEmpty function
			bool isEmpty() const;

			//declare operator functions
			bool operator==(const char* addingNumberQty) const;
			int operator+=(int givenObject);
			int operator-=(int substractingNumberQty);
	};		


	//Non-Member operator overload
	double operator+=(double& totalCost, const Product& quantityOfProduct);


	//Non-member IO operator overloads:
	std::ostream& operator<<(std::ostream& ostr, const Product&  show);
	std::istream& operator >> (std::istream& istr, Product& show);
}
#endif
