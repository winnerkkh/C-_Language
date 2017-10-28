// Final Project Milestone 6
// AidApp.h
// Version 1.0
// Date 8/06/2017
// Author Kyunghoon Kim (056-845-100)
// Email Address: khkim12@myseneca.ca
/////////////////////////////////////////////////////////////////



#ifndef SICT_AidApp_H__
#define SICT_AidApp_H__

#include <iostream>

#include "general.h"
#include "Product.h"
#include "AmaProduct.h"
#include "AmaPerishable.h"
#include "Streamable.h"

namespace sict {

	class AidApp {

		public:
			int run();
			
			AidApp(const char* filename);

		private:

			// declare private member 
			char filename_[FILE_NAME_LENGTH];
			Product *product_[MAX_NO_RECS];
			std::fstream datafile_;
			int noOfProducts_;

			
			// declare copy constructors( assign delete to prevent copied or assign)
			AidApp(const AidApp& A) = delete;
			AidApp& operator=(const AidApp& A) = delete;


			// declare private functions
			void pause()const;
			int menu();
			void loadRecs();
			void saveRecs();
			void listProducts()const;
			int SearchProducts(const char* sku)const;
			void addQty(const char* sku);
			void addProduct(bool isPerishable);

	};


}
#endif
