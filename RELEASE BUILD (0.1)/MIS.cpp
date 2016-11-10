/******************
* FILE: MIS.cpp
* Author: Arthur Kung
* Date: Nov 8, 2016
*
* Details:
*	- User-facing interface for the MIS system,
*		calls parse() and run().
*
*	- Catches exceptions and outputs meaningful
*		user errors.
******************/

#include <iostream>
#include <fstream>

#include "MIS_System.h"
#include "MIS_Exception.h"


int main(int argc, char* argv[])
{
	
	if (argc == 2)
	{
		MIS_System mis;
		bool success;
		
		try
		{	
			success = mis.parse(argv[1]);
		}	// catch all our MIS_Exceptions
		catch (const MIS_Exception &ex)
		{
			std::cout << "\n\tMIS_EXCEPTION CAUGHT: " << ex.what() << std::endl;
			return 0;
		}	// catch all other standard exceptions
		catch (const std::exception &ex)
		{
			std::cout << "\n\tEXCEPTION CAUGHT: " << ex.what() << std::endl;
			return 0;
		}	// catch anything else that gets thrown
		catch (...)
		{
			std::cout << "\n\tUNKNOWN EXCEPTION CAUGHT!" << std::endl;
			return 1;
		}
		
		
		if (success)
		{
			try
			{
				mis.run();
			}	// catch all our MIS_Exceptions
			catch (const MIS_Exception &ex)
			{
				std::cout << "\n\tMIS_EXCEPTION CAUGHT: " << ex.what() 
							<< std::endl;
				return 0;
			}	// catch all other standard exceptions
			catch (const std::exception &ex)
			{
				std::cout << "\n\tEXCEPTION CAUGHT: " << ex.what() << std::endl;
				return 0;
			}	// catch anything else that gets thrown
			catch (...)
			{
				std::cout << "\n\tUNKNOWN EXCEPTION CAUGHT!" << std::endl;
				return 1;
			}
		}
	}
	else
		std::cout << "Please input a filename." << std::endl;
	
	return 0;
	
}


