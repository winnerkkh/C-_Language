// Final Project Milestone 1
//
// Version 1.0
// Date 7/8/2017
// Author Kyunghoon Kim (056-845-100)
/////////////////////////////////////////////////////////////////

#include "Date.h"
#include "general.h"

using namespace std;


namespace sict{

   int Date::value()const {
       return year_ * 372 + mon_ * 31 + day_;
   }

   int Date::mdays()const {
       int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
       int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
       mon--;
       return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
   }


   //Sets the private member of readErrorCode_ 
   // checking if the parameter has the error or not
   void Date::errCode(int errorCode) {
	   readErrorCode_ = errorCode;
   }


   //sets the accessor or getter member functions(overloads)
   int Date::errCode()const {
	   return readErrorCode_;
   }

  

   //sets the accessor or getter member functions(overloads)
   bool Date::bad()const {
	   bool confirm = true;

	   if (readErrorCode_ != 0) {

		   confirm = false;
	   }

	   return confirm;
   }



   //sets the default constructor
   //assigning initial value to each member when the object started
   Date::Date() {
	   year_ = 0;
	   mon_ = 0;
	   day_ = 0;
	   readErrorCode_ = NO_ERROR;
   }

   //sets the three argument constructor
   //assign the values to instance values 
   Date::Date(int yearNumber, int monthNumber, int dayNumber) {

	   year_ = yearNumber;
	   mon_ = monthNumber;
	   day_ = dayNumber;
	   readErrorCode_ = NO_ERROR;
   }


   //comparing object(integer values)
	   bool Date::operator==(const Date& D)const {
		   bool confirm = false;

		   if (year_ == D.year_ && mon_ == D.mon_ && day_ == D.day_) {
			   confirm = true;
		   }

		   return confirm;
	   }

	   //comparing object(integer values)
	   //Used "*this" because I would not like to repeat the similar syntaxes; copied object and gave some different condtion(equaition)
	   bool Date::operator!=(const Date& D)const {
		   bool confirm = true;

		   if (*this == D){
			   confirm = false;
		   }

		   return confirm;
	   }

	   //comparing object
	   bool Date::operator<(const Date& D)const {
		   bool confirm;
		
		   if (this->value() < D.value())
			   confirm = true;
		   else
			   confirm = false;

		   return confirm;
	   }

	   //comparing object
	   bool Date::operator>(const Date& D)const {
		   bool confirm;

		   if (this->value() > D.value())
			   confirm = true;
		   else
			   confirm = false;
		   return confirm;
	   }

	   //comparing object
	   bool Date::operator<=(const Date& D)const {
		   bool confirm = false;

		   if (this->value() <= D.value()) {
			   confirm = true;
		   }

		   return confirm;
	   }

	   //comparing object
	   bool Date::operator>=(const Date& D)const {
		   bool confirm = false;

		   if (this->value() >= D.value()) {
			   confirm = true;
		   }

		   return confirm;
	   }

	   istream& Date::read(istream& istr) {

		   //to ignore the special characters such as / ? $ % and buffer need a syntax "cin.ignore(); " one by one
		   //assigning values to each variable from the user console input
		   istr >> year_;
		   istr.ignore();

		   istr >> mon_;
		   istr.ignore();

		   //do not need ignore() because the main function has it.
		   istr >> day_;
		
		   // fail<-- built-in function in iostream
		   // checking the integer values of year, momth and date if they are valid or not.

		   if (!(istr.fail())) {
			   if (year_ < MIN_YEAR || year_ > MAX_YEAR) {
				   errCode(YEAR_ERROR);
			   }
			   else if (mon_ < 1 || mon_>12) {
				   errCode(MON_ERROR);
			   }
			   else if(day_ < 1 || day_ > mdays()) {
				   errCode(DAY_ERROR);
			   }
		   }

		   // error occured if above condition does not match 
		   else {
			   readErrorCode_ = CIN_FAILED;
		   }
		   return istr;
	   }


	   // write on the console with the specific format provided 
	  ostream& Date::write(ostream& ostr)const {
		  
		  ostr << year_;
		  ostr << "/"; 
		if(mon_ < 10){ostr << "0";}		  
		ostr << mon_;
		  ostr << "/";
		  if(day_ < 10){ostr << "0";}	  
		  ostr << day_;
		  return ostr;
	  }


	  // helper functions(overloading)
	  // Instead of using like a cin >> date; & date.write();
	  istream& operator >> (istream& istreamO, Date& d) {
		
		  d.read(istreamO);
		  return istreamO;
	  }

	  ostream& operator<<(ostream& ostreamO, const Date& s) {

		  s.write(ostreamO);
		  return ostreamO;
	  }

}
