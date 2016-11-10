#include "z_dbg.h"

void showType(OP_Param_Base* op)
{
	PARAM_TYPE t = op->getType();
	
	switch(t)
	{
		case PARAM_TYPE::NUMERIC:
			std::cout << "\nNUMERIC: ";
			std::cout << *static_cast<long long*>(op->getValue());
			break;
		case PARAM_TYPE::VAR_NUM:
			std::cout << "\nVAR_NUM: ";
			std::cout << *static_cast<long long*>(op->getValue());
			break;
		
		case PARAM_TYPE::REAL:
			std::cout << "\nREAL: ";
			std::cout << *static_cast<double*>(op->getValue());
			break;
		case PARAM_TYPE::VAR_REA:
			std::cout << "\nVAR_REA: ";
			std::cout << *static_cast<double*>(op->getValue());
			break;
			
		case PARAM_TYPE::STRING:
			std::cout << "\nSTRING: ";
			std::cout << *static_cast<std::string*>(op->getValue());
			break;
		case PARAM_TYPE::VAR_STR:
			std::cout << "\nVAR_STR: ";
			std::cout << *static_cast<std::string*>(op->getValue());
			break;
			
		case PARAM_TYPE::CHAR:
			std::cout << "\nCHAR: ";
			std::cout << *static_cast<char*>(op->getValue());
			break;
		case PARAM_TYPE::VAR_CHA:
			std::cout << "\nVAR_CHA: ";
			std::cout << *static_cast<char*>(op->getValue());
			break;
		default:
			std::cout << "\nNONE? ";
	}
	
	std::cout << std::endl;
	
}

