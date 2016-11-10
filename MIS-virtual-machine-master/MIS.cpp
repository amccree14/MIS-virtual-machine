/******************
* FILE: MIS.cpp
* Author: Arthur Kung
* Date: Nov 8, 2016
*
* Details:
*	- User-facing interface for the MIS system,
*		calls parse() and run().
******************/

#include <iostream>

#include "MIS_System.h"


int main(int argc, char* argv[])
{
	
	if (argc == 2)
	{
		MIS_System mis;
	
		mis.parse(argv[1]);
		mis.run();
	}
	else
		std::cout << "Please input a filename." << std::endl;
	
	return 0;
	
}


