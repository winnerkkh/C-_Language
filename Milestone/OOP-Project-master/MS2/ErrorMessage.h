// Final Project Milestone 2
// Version 1.0
// Date 7/10/2017
// Author Kyunghoon Kim (056-845-100)
/////////////////////////////////////////////////////////////////



#ifndef SICT_ErrorMessage_H__
#define SICT_ErrorMessage_H__

#include <iostream>
#include <cstring>

namespace sict {

	class ErrorMessage {

		private:

			//declare private member
			char* message_;


		public:

			//declare default constructor
			ErrorMessage();

			//declare a constructor with an arguement
			ErrorMessage(const char* errorMessage);


			//declare a deleted copy constructor to prevent an ErrorMessage object to be copied.
			ErrorMessage(const ErrorMessage& em) = delete;

			//declare a deleted assignment operator overload to prevent an ErrorMessage object to be assigned to another
			ErrorMessage& operator=(const ErrorMessage& em) = delete;

			//
			ErrorMessage& operator=(const char* errorMessage);

			//declare a deconstructor
			virtual ~ErrorMessage();

			//declare clear function to deallocate new memory
			void clear();

			//declare the isClear function to check if the variable is nullptr or not
			bool isClear()const;

			//set the error message and make the error message equal to value
			void message(const char* value);

			//declare the function to show the error message
			const char* message()const;
	};


		// declare the helper function of stream. 
	std::ostream& operator<<(std::ostream& os, const ErrorMessage& errorMSG);

}
#endif