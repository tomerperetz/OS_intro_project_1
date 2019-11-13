/*
====================================================================================================================
Authors:
	- Segev Elmalem, ID: 203149000
	- Tomer Peretz, ID: 305002206
Project: Son
Input:
Outputs:
Description:
this script calculates the result of an equation and steps of solution.
order of the calculation is determined by parenthesis order - inside out and left to right.
====================================================================================================================
*/

#include "../Share/argparser.h"
#include "../Share/hardCodedData.h"
#include "../Share/lib_errorHandler.h"
#include "../Share/lib_str_func.h"
#include "winAPI.h"
#include "./lib_father_funcs.h"

int main(int argc, char *argv[]) {
	char equation[MAX_FATHER_ARG_INPUT_LEN];
	if (ensureArgs(argc, EXPECTED_ARGC, argv) != IS_TRUE)
		raiseError(1, __FILE__, __func__, __LINE__, ERROR_ID_1_CONTENT);
	
	strcpy_s(equation, MAX_FATHER_ARG_INPUT_LEN, argv[1]);
	
	if (execute_program(equation) == IS_TRUE) {
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"\
			   "\t\tProgram ended succesfuly! Results has been printed to './Computation.txt'\n"\
			   "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		return IS_FALSE; // Program has finished with no Error!
	}
	else
		return IS_TRUE; // An Error occurred! Program exit with code 1
}