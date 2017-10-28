// Final Project Milestone 2
// Version 1.0
// Date 7/10/2017
// Author Kyunghoon Kim (056-845-100)
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include "ErrorMessage.h"

using namespace std;

namespace sict{


	//implementation of a default constructor
	ErrorMessage::ErrorMessage() {

		message_ = nullptr;
	}

	//implementation of a constructor with an arguement
	ErrorMessage::ErrorMessage(const char* errorMessage) {
		
		message_ = nullptr;
		message(errorMessage);
	}

	//implementation of an operator 
	ErrorMessage& ErrorMessage::operator=(const char* errorMessage) {
		
		clear();
		message(errorMessage);

		return *this;
	}

	// implementation of de-allocate the momoney pointed by message_
	ErrorMessage::~ErrorMessage() {

		delete[] message_;
	}


	//implementation of flush dealocate memory
	void ErrorMessage::clear() {

		delete[] message_;
		message_ = nullptr;
	}


	// implementation of checking if the variable is cleared or not.
	bool ErrorMessage::isClear() const {

		bool result = false;

		if (message_ == nullptr) {

			result = true;
		}

		return result;
	}


	void ErrorMessage::message(const char* value) {

		clear();

		//Confirming the number of letter length from the argument(parameter)
		int checkingLength = strlen(value) + 1;

		//allocatring new memory into the variable "message_"
		message_ = new char[checkingLength+1];

		//copy the value of the parameter "value" into the variable "message_ with the length"
		strncpy(message_, value, checkingLength);

	}


	// the variable message_ has the address itself. Thus, I do not need to put &<---mark.
	// char* message_; and char message[] ==> smae thing.
	const char*ErrorMessage::message()const {

		return message_;
	}

	//implementation of the helper fucntion for cout
	ostream& operator<<(ostream& os, const ErrorMessage& errorMSG) {
		
		if (!errorMSG.isClear()) {
			os << errorMSG.message();
		}

		return os;	
	}
}

