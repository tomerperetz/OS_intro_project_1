/*
====================================================================================================================
Description:
this lib holds caluclation functions.
====================================================================================================================
*/


#include "lib_calc_func.h"


int calcEquation(int x, int y, char eq_operator)
{
	/*
	Description: calculate equation - X + Y or X * Y
	parameters:
			 - int X
			 - int Y
			 - char eq_operator - arithmetical operator
	Returns: int
	*/

	if (eq_operator == '+')
		return (x + y);
	else if (eq_operator == '*')
		return (x*y);
	else
	{
		raiseError(2, __FILE__, __func__, __LINE__, ERROR_ID_2_CONTENT);
		return ERR;
	}
}