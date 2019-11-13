#include "../Share/argparser.h"
#include "../Share/hardCodedData.h"
#include "../Share/lib_errorHandler.h"
#include "../Share/lib_str_func.h"
#include "winAPI.h"

void add_sub_string_to_string(char dest_str[], char sub_str[], int start_idx) {
	int idx = 0;
	for (idx = 0; sub_str[idx] != END_OF_STR; idx++, start_idx++)
		dest_str[start_idx] = sub_str[idx];
	dest_str[start_idx] = END_OF_STR;

}

void replace_sub_string(char *string, int sub_str_start_idx, int sub_str_end_idx, char *new_sub_string) {
	char string_start[MAX_FATHER_ARG_INPUT_LEN], string_end[MAX_FATHER_ARG_INPUT_LEN];

	strcpy_s(string_end, MAX_FATHER_ARG_INPUT_LEN, &string[sub_str_end_idx + 1]);
	string[sub_str_start_idx] = END_OF_STR;
	strcpy_s(string_start, MAX_FATHER_ARG_INPUT_LEN, string);
	sprintf_s(string, MAX_FATHER_ARG_INPUT_LEN, "%s%s%s", string_start, new_sub_string, string_end);
	//add_sub_string_to_string(string, new_sub_string, sub_str_start_idx);
	//add_sub_string_to_string(string, string_end, sub_str_start_idx + strlen(new_sub_string));
}

int execute_program(char equation[]) {
	int idx = 0, sub_equation_idx = 0, sub_equation_start_idx = -1, sub_equation_end_idx = -1, result=-1;
	char sub_equation[MAX_SON_ARG_INPUT_LEN], command[MAX_SON_ARG_INPUT_LEN+4], result_str[MAX_SON_ARG_INPUT_LEN];
	FILE *fp = NULL;

	/*To Do: Write an Error message*/
	if (fopen_s(&fp, "Computation.txt", "w") != IS_FALSE) {
		raiseError(1, __func__ ,__FILE__, __LINE__, ERROR_ID_1_CONTENT);
		
	}
	while (equation[idx] != END_OF_STR) {
		
		if (equation[idx] == OPEN_PARENTHESIS) {
			sub_equation_start_idx = idx;
			sub_equation_idx = 0;
			idx++;
		}
		else if (equation[idx] == CLOSE_PARENTHESIS) {
			/*save eqation*/
			fprintf(fp, "%s\n", equation);
			/*call son*/
			sub_equation[sub_equation_idx] = END_OF_STR;
			sprintf_s(command, MAX_SON_ARG_INPUT_LEN + 4, "Son %s", sub_equation);
			result = CreateProcessSimpleMain(command);
			_itoa(result, result_str, 10);
			sub_equation_end_idx = idx;
			/*replace sub equation*/
			replace_sub_string(equation, sub_equation_start_idx, sub_equation_end_idx, result_str);
			printf("%s\n", equation);
			
			/*initialization*/
			idx = 0;
			sub_equation_idx = 0;
			sub_equation_start_idx = 0;
			
		}
		else {
			sub_equation[sub_equation_idx] = equation[idx];
			idx++;
			sub_equation_idx++;
		}
	}

	/*save eqation*/
	fprintf(fp, "%s\n", equation);

	/*To Do: Write an Error message*/
	if (fclose(fp) != IS_FALSE) {
		raiseError(1, __func__, __FILE__, __LINE__, ERROR_ID_1_CONTENT);

	}
	
	return IS_TRUE;
}

int main(int argc, char *argv[]) {
	char equation[MAX_FATHER_ARG_INPUT_LEN];
	if (ensureArgs(argc, EXPECTED_ARGC, argv) != IS_TRUE)
		raiseError(1, __func__, __FILE__, __LINE__, ERROR_ID_1_CONTENT);
	
	strcpy_s(equation, MAX_FATHER_ARG_INPUT_LEN, argv[1]);
	
	execute_program(equation);
	return IS_FALSE;
}