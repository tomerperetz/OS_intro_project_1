/*
====================================================================================================================

Description:
this lib contains all functions related to father main.c.
extended description is in the functions.
====================================================================================================================
*/


#include "./lib_father_funcs.h"

void close_program(FILE *fp) {
	/*
	Description: close program.
	Prameters:
		 - FILE *fp - file pointer.
		 - int expected_argc - number of args expected.
		 - char argv - args
	Returns: nothing if succeded, ERR o.w
	*/

	if (fclose(fp) != IS_FALSE)
		raiseError(4, __FILE__, __func__, __LINE__, ERROR_ID_4_CONTENT);
}

int execute_program(char equation[]) {
	/*
	Description: Executes father program - calulate equations inside out and left to right.
	Prameters:
		 - char equation[] - user equation given as a string.
	Returns: IS_TRUE if succeded, ERR o.w
	*/

	int idx = 0, sub_equation_idx = 0, sub_equation_start_idx = -1, sub_equation_end_idx = -1;
	long result;
	char sub_equation[MAX_SON_ARG_INPUT_LEN], command[MAX_SON_ARG_INPUT_LEN + 4], result_str[MAX_SON_ARG_INPUT_LEN];
	FILE *fp = NULL;

	/*Opens the Computation file*/
	if (fopen_s(&fp, "Computation.txt", "w") != IS_FALSE) {
		raiseError(4, __FILE__, __func__, __LINE__, ERROR_ID_4_CONTENT);
	}
	/*
	main loop that does the followwing:
		 1. runs over the equation.
		 2. parse the sub-equation
		 3. Calls the son process
		 4. Prints the equation after each itration to the Computation.txt file
	*/
	while (equation[idx] != END_OF_STR) {
		// Checks if the current char is equal to (
		if (equation[idx] == OPEN_PARENTHESIS) {
			sub_equation_start_idx = idx;
			sub_equation_idx = 0;
			idx++;
		}
		// Checks if the current char is equal to )
		else if (equation[idx] == CLOSE_PARENTHESIS) {

			/*call son*/
			sub_equation[sub_equation_idx] = END_OF_STR;
			sprintf_s(command, MAX_SON_ARG_INPUT_LEN + 4, "Son %s", sub_equation);
			result = CreateProcessSimpleMain(command);
			if (result == ERR) {
				close_program(fp);
				return ERR;
			}
			else if (result == BRUTAL_TERMINATION_CODE) {
				close_program(fp);
				raiseError(6, __FILE__, __func__, __LINE__, ERROR_ID_6_CONTENT);
				return ERR;
			}
			/*save eqation*/
			fprintf(fp, "%s\n", equation);
			_ltoa_s(result, result_str, MAX_SON_ARG_INPUT_LEN,10);
			sub_equation_end_idx = idx;
			/*replace sub equation*/
			replace_sub_string(equation, sub_equation_start_idx, sub_equation_end_idx, result_str);

			/*initialization*/
			idx = 0;
			sub_equation_idx = 0;
			sub_equation_start_idx = 0;

		}
		//  Checks if the current char is a number/operator 
		else if ((equation[idx] > 47 && equation[idx] < 58) || (equation[idx] > 41 && equation[idx] < 44)) {
			sub_equation[sub_equation_idx] = equation[idx];
			idx++;
			sub_equation_idx++;
		}
		else {
			raiseError(1, __FILE__, __func__, __LINE__, ERROR_ID_1_CONTENT);
		}
	}

	/*save eqation*/
	fprintf(fp, "%s\n", equation);

	/*To Do: Write an Error message*/
	close_program(fp);
	return IS_TRUE;

}
