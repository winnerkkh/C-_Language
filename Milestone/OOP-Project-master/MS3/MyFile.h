// Final Project Milestone 3
// Version 1.0
// Date 7/11/2017
// Author Kyunghoon Kim (056-845-100)
/////////////////////////////////////////////////////////////////


//can't have the same name of ifndef and define with other header file(which is Streamable.h)
#ifndef SICT_STREAMABLE_H__
#define SICT_STREAMABLE_H__
#include "Streamable.h"
#include "Streamable.h"
#include "Streamable.h" // Streamable.h is inluded three times on purpose.

namespace sict{
  class MyFile : public Streamable {
    char fname_[256];
    char text_[10000];
  public:
    MyFile(const char* fname);
    std::fstream& store(std::fstream& file, bool addNewLine)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
    void print();
  };
  std::ostream& operator<<(std::ostream& ostr, const MyFile& mf);
  std::istream& operator>>(std::istream& istr, MyFile& mf);
}
#endif