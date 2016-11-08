/**************************
*
*	Sample code, do not assume this will work as is, because it is
*		untested in its current form.
*
**************************/


	// add takes 3-13 parameters, with the first parameter being a variable
	//		and the remaining parameters being either variables or
	//		immediate values. We don't care WHAT those values are.

void C_ADD::execute()
{
		// check storage variable type. If it's a NUMERIC type....
	if (opList[0].type == PARAM_TYPE::VAR_NUM)
	{
			// create temporary variable for storage
		long long temp = 0;
			// loop through every parameter and add them based on
			//	their declared types (casting their returned void*
			//	to their respective types)
		for (int i = 1; i < opList.size(); ++i)
		{
			switch(opList.type)
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					temp += *static_cast<long long*>(opList[i]->getValue());
					break;

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					temp += *static_cast<double*>(opList[i]->getValue());
					break;				
				
					// the below 4 cases are ignored because they are invalid
					//	parameter types for ADD. += doesn't make sense
					//	for character at all, and is not implemented for
					//	strings in our virtual machine.
					
				//case PARAM_TYPE::CHAR:
				//case PARAM_TYPE::VAR_CHA:
				//	temp += *static_cast<char*>(opList[i]->getValue());
				//	break;
				
				//case PARAM_TYPE::STRING:
				//case PARAM_TYPE::VAR_STR:
				//	temp += *static_cast<string*>(opList[i]->getValue());
				//	break;
				
					// if there are no matches, throw an exception
				default
					throw MIS_Exception("ERROR: Invalid parameter type!"
										" (ADD parameter" 
										+ std::to_string(i+1) + ")\n");
			}
		}
			// store the final value into the given variable
		opList[0].setValue(static_cast<void*>(&temp));		
	}
		// otherwise, if it's a REAL type... (see above for comments)
	else if (opList[0].type == PARAM_TYPE::VAR_REAL)
	{
		double temp = 0;
			switch(opList.type)
			{
				case PARAM_TYPE::NUMERIC:
				case PARAM_TYPE::VAR_NUM:
					temp += *static_cast<long long*>(opList[i]->getValue());
					break;

				case PARAM_TYPE::REAL:
				case PARAM_TYPE::VAR_REA:
					temp += *static_cast<double*>(opList[i]->getValue());
					break;				
				
				//case PARAM_TYPE::CHAR:
				//case PARAM_TYPE::VAR_CHA:
				//	temp += *static_cast<char*>(opList[i]->getValue());
				//	break;
				
				//case PARAM_TYPE::STRING:
				//case PARAM_TYPE::VAR_STR:
				//	temp += *static_cast<string*>(opList[i]->getValue());
				//	break;
				
				default
					throw MIS_Exception("ERROR: Invalid parameter type!"
										" (ADD parameter" 
										+ std::to_string(i+1) + ")\n");
			}
		}
		opList[0].setValue(static_cast<void*>(&temp));
	}
		// otherwise, if it's neither a REAL or NUMERIC variable, it's an error
	else
		throw MIS_Exception("ERROR: Invalid storage type! (ADD)\n");
		
	
	return;	
}










////////////// I think separating every command class into its own
////////////// cpp file may be useful here. It's debatable, since it will
////////////// also make finding all the relevant command classes to adjust
////////////// code more irritating.











void C_SUB::execute()
{
	

	auto temp;
	// subtract 3rd param from second param
	temp = opList[1] - opList[2];

	oplist[0].setValue(temp);
	
	return;	
	
}

void C_DIV::execute()
{

	auto temp;
	// If second param is zero throw exception/error
	// divide 3rd param from second param
	temp = opList[1] / opList[2];

	oplist[0].setValue(temp);
	
	return;	
	
}

void C_ASSIGN::execute()
{
	// storing second parameter into firs 
	oplist[0].setValue(opList[1]);
	
	return;	
	
}

void C_OUT::execute() {
		// start at begininng of oplist to print out every value 
		for (int i = 0; i < oplist.size() - 1; ++i)
	{
		std::cout << oplist[i].getvalue() << endl;
	}
	
	return;
}
	
