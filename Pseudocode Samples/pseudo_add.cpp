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

		// temporary value for storing the sum of our parameters
		// maybe we should use auto for our temp type since the ADD command should be able
		//to take in both int and float
	/* auto */ double temp = 0;
	
		// loop through the vector and add all parameters (except the first
		//	one) together
	for (int i = 1; i < oplist.size(); ++i)
	{
		temp += oplist[i].getValue();
	}
	
		// save the summed value into the variable location provided
		//	in the first parameter
	oplist[0].setValue(temp);
	
		// done
	return;	
	
}

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
	
