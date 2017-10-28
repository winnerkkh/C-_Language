#pragma once

// workshop 1 - Modular Programming
// tools.h
// OOP244SAB
// 18.5.2017
// Kyunghoon Kim


#ifndef SICT_TOOLS_H
#define SICT_TOOLS_H


namespace sict {

	//Maximum number of simples in an graph
	#define MAX_NO_OF_SAMPLES 20



	// Displays the user interface menu
	int menu();

	// Performs a fool-proof integer entry
	int getInt(int min, int max);

}
#endif
