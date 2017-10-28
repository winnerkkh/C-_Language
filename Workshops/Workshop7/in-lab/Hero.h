// OOP244 Workshop 7: Derived Classes
// Hero.h
// Version 1.0
// Date 2017/07/13
// Author Kyunghoon Kim(056-845-100)
// Description
//       This file demonstrates the client module of w7
/////////////////////////////////////////////////////


#ifndef HERO_H
#define HERO_H

#include <iostream>

namespace sict {
    class Hero {
        char m_name[41];    
        int  m_attack;
        int  m_maximumHealth;
        int  m_health;
        
        bool isEmpty () const;

    public:
        // constructors
        Hero ();
        Hero (const char name[], int maximumHealth, int attack);

        // member functions
        void respawn();
        bool isAlive () const           {    return m_health > 0;  	}
        int  getAttack () const         {    return m_attack;       }
        void deductHealth(int);

        // friend helper function to insert name into ostream
        friend std::ostream& operator<<(std::ostream&, const Hero&);
    };

    void applyDamage (Hero& A, Hero& B);
    const Hero & operator*(const Hero &, const Hero &);
}

#endif
