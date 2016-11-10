#ifndef H_LABEL_LINK
#define H_LABEL_LINK

/******************
* FILE: labelLink.h
* Author: Arthur Kung
* Date: Nov 9, 2016
*
* Details:
*	- declares a struct that contains information the MIS_System's parsing
*		sequence requires in order to late-link label calls.
*
*		ie: a 'JMP' can legally pass a label that isn't declared until
*			later in the program code.
*
*	- If that happens, then the parser will be unable to find the index for 
*		that JMP's label, so it will set aside creating that command until 
*		it finishes parsing the entire file. After it completes its parse cycle,
*		it will return to the JMP calls it left aside and attempt to match them 
*		to labels.
*
*		At this point, if it still cannot find the label the JMP commands are
*		requesting, the parser will decide there's an error and throw an
*		exception.
******************/


#include <string>

#include "Command.h"

struct labelLink
{
	Command* obj;
	std::string text;
	long long index;
	
	labelLink(Command* _obj,std::string _text, long long _index):
					obj(_obj), text(_text), index(_index){}

};

#endif
