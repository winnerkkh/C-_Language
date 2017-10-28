// Workshop 9: Classes with Resources Review
// File: String.cpp
// Date: 2017/07/27
// Name: Kyunghoon Kim
// Student No: 056-845-100
// Student Email: khkim12@myseneca.ca

#include <cstring>
#include <iostream>
#include "String.h"



using namespace std;

namespace sict{
    
    
    //////////////////////////////////////////////////////
    //
    // Default Constructor
    // String::String();
    //
    // initialize the string to ""
    //
    // 
    String::String(){
       // initialize the string to ""

		strncpy(m_pString, "", STRING_BUFFERSIZE);
		m_pString[0] = '\0';
    }


    //////////////////////////////////////////////////////
    //
    // String::String(const char* p);
    //
    // Construct a String from a char array
    // You may assume the input string pSource 
    // has a length of < 50, and the internal buffer has enough
    // space to hold it.
    //
    // 
    String::String(const char* pSource){

		strncpy(m_pString, pSource, 50);		
    }

    //////////////////////////////////////////////////////
    //
    // String::String(const String &s, int capacity);
    //
    // Copy constructor
    //
    // Construct a String from another String
    //
    // 
    String::String(const String& other) 
    {
		
		*this = other;
		
    }

    
    //////////////////////////////////////////////////////
    //
    // String::operator=(const String& other)
    // 
    // Assignment operator
    // copy string "other" to this object
    //   
    //     
    String& String::operator=(const String& other) {

		if (this != &other) {
			strncpy(m_pString, other.m_pString, STRING_BUFFERSIZE);
		}
		return *this;
    }

    //////////////////////////////////////////////////////
    //
    // String::~String
    // 
    // destructor
    // 
    // clean up the internal string buffer  
    // 
    String::~String() {

		
    }


    //////////////////////////////////////////////////////
    //
    // String::length()
    // 
    // return the length of the string
    // 
    // 
    int String::length() const {
       
		int len;

		len = strlen(m_pString);

		return len;
    }

    //////////////////////////////////////////////////////
    //
    // String::operator const char*() const
    // 
    // convert the String to a char*
    // 
    // 
    String::operator const char *() const {
      
		
		// syntax converting to char array by having "(const char*)" from any types of 
		return (const char*) m_pString;

    }

    //////////////////////////////////////////////////////
    //
    // String::empty()
    // 
    // 
    // returns true if the string is empty
    // i.e. either the first char is \0, or 
    // length is 0.
    bool String::empty() const {
      
		bool result = false;

		if (m_pString[0] == '\0') {

			result = true;
		}

		return result;
    }

    //////////////////////////////////////////////////////
    //
    // String::operator bool()
    // 
    // same as empty(), just wrapped in an operator
    // 
    //         
    String::operator bool() const {

		return !empty();
       
    }
     
     
    //////////////////////////////////////////////////////
    //
    // String::operator==(const String& s2) const
    // 
    // returns true if *this == s2.
    // You can use the strcmp function to check if 
    // two strings are equal, or write your own
    // treating the string as a char-array
    //           
    bool String::operator==(const String& s2) const {
     
		bool result = false;

		if (strcmp(m_pString, s2.m_pString) ==0 ) {

			result = true;
		}

		return result;
    }
        

        
    //////////////////////////////////////////////////////
    //
    // String::operator+=(const String& s2)
    // 
    // Concatenates s2 to the end of *this
    //
    // implements *this = (*this + s2)
    // return *this
    // 
    //         
    String& String::operator+=(const String& s2) {

		strcat(m_pString, s2.m_pString);

		return *this;
    }
    
    //////////////////////////////////////////////////////
    //
    // String::operator+(const String& s2) const
    // 
    // implements the operator (*this + s2)
    // returns the expression
    // DOES NOT MODIFY *this
    // 
    //     
    String String::operator+(const String& s2) const {

		String tempObject = *this;
      
		tempObject += s2;

		//tempObject.m_pString += s2.m_pString;
		return tempObject;
    }
      


    //////////////////////////////////////////////////////
    //
    // String::operator+=(char c)
    // 
    // Adds a single char c to the end of the string in *this
    // 
    //        
    String& String::operator+= (char c) {


		
		m_pString[length()] = c;
		
		//consider null
		m_pString[length()+1] = '\0';

		return *this;
    }


    
    
    
    //////////////////////////////////////////////////////
    //
    // operator<<
    // 
    // Print the string to the output stream
    // 
    // clean up the internal string buffer  
    //     
    std::ostream& operator<<(std::ostream& ostream, const String &s) {


		ostream << (const char*)s;
	

		return ostream;
    }


    //////////////////////////////////////////////////////
    //
    // operator>>
    // 
    // Input a string from an input stream into the String s
    // 
    // Note: the input can be ANY length in character. You will need to 
    // read it one char at a time. 
    // 
    std::istream& operator>>(std::istream& istream, String &s)
    {
        s = "";
        char tempC = 0;
        do
        {
            tempC = istream.get();
            if (tempC != '\n')
            {
                s += tempC;
            }
            else
                break;
        } while(1);
        return istream;
    }

  
}
