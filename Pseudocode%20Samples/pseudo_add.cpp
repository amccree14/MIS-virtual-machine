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
	double temp = 0;
	
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




