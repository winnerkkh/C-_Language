// Final Project Milestone 1
// Data.h
// Version 1.0
// Date 7/8/2017
// Author Kyunghoon Kim (056-845-100)
/////////////////////////////////////////////////////////////////

#ifndef SICT_DATE_H__
#define SICT_DATE_H__

#include <iostream>
#include "general.h"


// define the validation
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

namespace sict{

   class Date {
   private:
      
	  //Declare Data Memembers
	  int year_;
	  int mon_;
	  int day_;
	  int readErrorCode_;


      int value()const;
	  void errCode(int errorCode);
	

   public:
      
	   //declare constructor of the class
	   Date();
	   Date(int yearNumber, int monthNumber, int dayNumber);
	   int mdays()const;

	   // declare errCode
	   int errCode()const;
	   bool bad()const;


	   //declare operator functions
	   bool operator==(const Date& D)const;
	   bool operator!=(const Date& D)const;
	   bool operator<(const Date& D)const;
	   bool operator>(const Date& D)const;
	   bool operator<=(const Date& D)const;
	   bool operator>=(const Date& D)const;


	   //declare IO member-funtions
	   std::istream& read(std::istream& istr);
	   std::ostream& write(std::ostream& ostr)const;

   };

   std::istream& operator>>(std::istream& istreamO, Date& d);
   std::ostream& operator<<(std::ostream& ostreamO, const Date& s);
}
#endif