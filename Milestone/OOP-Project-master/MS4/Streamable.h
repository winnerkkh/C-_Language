// Final Project Milestone 3
// Version 1.0
// Date 7/11/2017
// Author Kyunghoon Kim (056-845-100)
/////////////////////////////////////////////////////////////////


//can't have the same name of ifndef and define with other header file(which is MyFile.h)
#ifndef SICT_STREAMABLE_H_
#define SICT_STREAMABLE_H_

#include <iostream>
#include <fstream> 

namespace sict {
	
	class Streamable {
	
	private:
	
	public:
		//Pure virtual function
		//Checking the file and output if they are stroed information correctly or not
		virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const = 0;
		
		//Pure virtual function
		//load the file 
		virtual std::fstream& load(std::fstream& file) = 0;
		
		//Pure virtual function
		//store the user input from the console into the file
		virtual	std::ostream& write(std::ostream& os, bool linear)const = 0;
		
		//Pure virtual function
		//read the file output from the file to the console.
		virtual	std::istream& read(std::istream& is) = 0;
	};
}
#endif