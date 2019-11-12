
#include "../Share/lib_str_func.h"
#include "../Share/argparser.h"



int calcEquation(int x, int y, char eq_operator)
{
	//char operator_error[60] = "Can't use supplied opertor: %c\nExiting Program\n";

	if (eq_operator == '+')
		return (x + y);
	else if (eq_operator == '*')
		return (x*y);
	else
	{
		raiseError(1, __FILE__, __func__, __LINE__, ARGS_ERROR);
		return ERROR;
	}
}

int main(int argc, char *argv[])
{	
	char user_equation[MAX_SON_ARG_INPUT_LEN];
	int x = ERROR, y= ERROR, operator_index = ERROR, result = ERROR;

	// args parser
	if (ensureArgs(argc, 1, argv) == FALSE)
			raiseError(2, __FILE__, __func__, __LINE__, ARGS_ERROR);

	if (YES == strcpy_s(user_equation, MAX_SON_ARG_INPUT_LEN, argv[1]))
	{
		// Search for '+' arithmetic operator index
		operator_index = getCharindex('+', user_equation);

		// if '+' wasn't found look for '*'
		if (operator_index == ERROR)
			operator_index = getCharindex('*', user_equation);

		// verify operator was found
		if (operator_index == ERROR)
			raiseError(1, __FILE__, __func__, __LINE__, ARGS_ERROR);
	}

		
	// calculate
	x = getFirstIntFromString(user_equation, operator_index);
	y = getLastIntFromString(user_equation, operator_index + 1);
	result = calcEquation(x, y, user_equation[operator_index]);

	//need to delete
	printf("result: %d", result);
	
	ExitProcess(result);	
}
 

