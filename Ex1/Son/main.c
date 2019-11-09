#include <stdio.h>
#include "../Share/lib_str_func.h"

_CRT_SECURE_NO_WARNINGS


#define YES 0 //need to delete

int calcEquation(int x, int y, char eq_operator)
{
	if (eq_operator == '+')
		return (x + y);
	else if (eq_operator == '*')
		return (x*y);
	else
	{
		printf("cant use supplied opertor: %c\nExiting Program\n", eq_operator);
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	// insert defines

	char user_equation[32];
	int x = -1, y=-1 , operator_index = -1, result=-1;
	
	printf("Program name %s\n", argv[0]);

	// verify input is valid
	if (argc == 2) {
		printf("The argument supplied is %s\n", argv[1]);
	}
	else if (argc > 2) {
		printf("Too many arguments supplied.\nPlease restart program with a valid input.");
		exit(1);
	}
	else {
		printf("One argument  .\nPlease restart program with a valid input.");
		exit(1);
	}

	if (YES == strcpy_s(user_equation, 32, argv[1]))
	{
		// Search for '+' arithmetic operator index
		operator_index = getCharindex('+', user_equation);

		// if '+' wasn't found look for '*'
		if (operator_index == -1)
			operator_index = getCharindex('*', user_equation);

		// verify operator was found
		if (operator_index == -1)
		{
			printf("couldn't locate arithmetical operator.\nPlease use '+' or '-' only.\nExiting program.\n");
			exit(1);
		}

		
		x = getFirstIntFromString(user_equation, operator_index);
		y = getLastIntFromString(user_equation, operator_index + 1);
		result = calcEquation(x, y, user_equation[operator_index]);

		printf("result: %d", result);

		return 0;
	}
		
	//X = get_x(argv[1]);
	//printf("first int: %d\n", X);

	return 0;
}
 

