#include <stdio.h>

int get_x(char *exp)
{
	int x=0;
	printf("arg: %s", exp);
	//x = *(exp + 1) - '0';

	return x;

}

int main(int argc, char *argv[])
{
	
	printf("Program name %s\n", argv[0]);

	if (argc == 2) {
		printf("The argument supplied is %s\n", argv[1]);
	}
	else if (argc > 2) {
		printf("Too many arguments supplied.\n");
	}
	else {
		printf("One argument  .\n");
	}

	//X = get_x(argv[1]);
	//printf("first int: %d\n", X);

	return 0;
}
 

