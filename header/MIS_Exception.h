#ifndef H_MIS_EXCEPTION
#define H_MIS_EXCEPTION

/******************
* FILE: MIS_Exception.h
* Author: Arthur Kung
* Date: Novermeber 7, 2016
*
* Details:
*	- defines the unique exception class we can use for our generic errors
*		as an subclass of std::runtime_error
******************/

class MIS_Exception:public std::runtime_error
{
	public:
		MIS_Exception(std::string const& msg):std::runtime_error(msg){}
};



#endif

