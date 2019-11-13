/*
====================================================================================================================
Authors:
	- Segev Elmalem, ID: 203149000
	- Tomer Peretz, ID: 305002206
Project: Son
Input:
Outputs:
Description:
this file convert a string equation with the form: "X+Y" or "X*Y" to integers and returns the calculation result
====================================================================================================================
*/

#include "../Share/lib_str_func.h"
#include "../Share/argparser.h"
#include "../Share/lib_errorHandler.h"
#include "lib_calc_func.h"

int main(int argc, char *argv[])
{	
	/*
	Description: get a string equation from user: "X + Y" or "X * Y". 
	convert numbers to integers and calculate the result.
	parameters:
			 - char* argv - user args. should include program name and equation.
			 - int argc = number of parameters given by user.
	Return: int.
	*/

	char user_equation[MAX_SON_ARG_INPUT_LEN];
	int x = ERR, y= ERR, operator_index = ERR, result = ERR;

	// args parser
	if (ensureArgs(argc, 1, argv) == IS_FALSE)
			raiseError(2, __FILE__, __func__, __LINE__, ERROR_ID_2_CONTENT);

	if (EQUAL == strcpy_s(user_equation, MAX_SON_ARG_INPUT_LEN, argv[1]))
	{
		// Search for '+' arithmetic operator index
		operator_index = getCharindex('+', user_equation);

		// if '+' wasn't found look for '*'
		if (operator_index == ERR)
			operator_index = getCharindex('*', user_equation);

		// verify operator was found
		if (operator_index == ERR)
			raiseError(2, __FILE__, __func__, __LINE__, ERROR_ID_2_CONTENT);
	}

	else
		raiseError(3, __FILE__, __func__, __LINE__, ERROR_ID_3_CONTENT);
		
	// calculate
	x = getFirstIntFromString(user_equation, operator_index);
	y = getLastIntFromString(user_equation, operator_index + 1);
	result = calcEquation(x, y, user_equation[operator_index]);
	ExitProcess(result);	
}
 

