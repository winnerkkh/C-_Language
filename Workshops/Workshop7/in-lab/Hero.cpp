// OOP244 Workshop 7: Derived Classes
// Hero.cpp
// Version 1.0
// Date 2017/07/13
// Author  Kyunghoon Kim (056-845-100)
// Description
//       This file demonstrates the client module of w7
/////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Hero.h"
using namespace std;

namespace sict{
    //////////////////////////////////////////////
    // Default constructor
    //
    Hero::Hero () {
		//initialize all the instance members 
		m_name[0] = '\0';
		m_attack = 0;
		m_maximumHealth = 0;
		m_health = 0;

    }

    ///////////////////////////////////////////////////
    // Constructor
    // 
    Hero::Hero (const char name[], int maximumHealth, int attack) {
		
		//overloading constructor by userinput;
		strncpy(m_name, name, 40);
		//m_name[40] = '/0';
		m_attack = attack;
		m_health = maximumHealth;
		m_maximumHealth = maximumHealth;
    }


    /////////////////////////////////////////////////////////
    // ostream helper overloaded operator <<
    // 
    ostream& operator<<(ostream& out, const Hero& h) {
	
		if (!h.isEmpty()) {

			out << h.m_name;
		}
		return out;
    }

    /////////////////////////////////////////////////
    // Hero::isEmpty ()
    // return true if the Hero object is uninitialized
    //
    bool Hero::isEmpty () const 
    {
		// checking the instance values if they are initialized or not.
		bool result = false;

		if ((m_name[0] == '\0') && (m_attack != 0) && (m_attack != 0) && (m_maximumHealth != 0) && (m_health != 0)) 
		{

			result = true;
		}

		return result;
    }

    /////////////////////////////////////////////////
    // sets the Hero object's health back to full
    //
    void Hero::respawn() {

		// assign the maxhealth to the instance value of health.
		m_health = m_maximumHealth;

    }

    void Hero::deductHealth(int attack) {

		//keep substracting from the points
		m_health -= attack;
    }

    //////////////////////////////////////////////////////////////////
    // Global helper function
    // compute the damage that A inflicts on B 
    // and of B on A
    //
    void applyDamage (Hero& A, Hero& B) {

		// checking if A and B are alive and check if they are below 0 or not;
		if (A.isAlive() && B.isAlive()) {
			A.deductHealth(B.getAttack());
			B.deductHealth(A.getAttack());
		}
    }

    //////////////////////////////////////////////////////////////////
    // Global helper operator
    // rather than type in fight(hercules, theseus), we use an operator
    // so you can type in hercules * theseus
    //
    // returns a reference to the winner object
    // 
    // so that if hercules is stronger, 
    // (hercules * theseus) == hercules
    // will be true.
    // 
    // note the inputs are const, so that you can be sure that the heros will be unharmed during the fight.
    //
    const Hero & operator* (const Hero & first, const Hero & second) {

        // Display the names of the people fighting

        cout << "AncientBattle! " << first << " vs " << second << " : ";

        // We want our heroes to exit the battle unharmed, so 
        // we make the input arguments const.
        // So how can we modify the objects during the fight?
        // We make copies of them.
        Hero A = first;
        Hero B = second;
        const Hero *winner = nullptr;

        // Now A will fight B, and winner will point to the winner.    
        // Main fight loop
        unsigned int rounds = 0;
        // loop while both are still alive
        // fight for 100 rounds
        while (A.isAlive() && B.isAlive() && rounds < 100)
        {
            rounds++;
            applyDamage(A, B);
        }

        // if we got here, then one Hero is dead, or if both are alive then it was a draw.
        bool draw;

        if (A.isAlive() && B.isAlive()) { draw = true; }
        else { draw = false; }

        // if it was a draw, then we decide by tossing an unfair coin and always
        // declare that A was the winner. 
        if (draw)
        {
            winner = &first;
        }
        else if (A.isAlive())
        {
            winner = &first;
        }
        else
        {
            winner = &second;
        }

        // print out the winner
        cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

        // return a reference to the winner
        return *winner;
    }
}