#include "../Share/argparser.h"
#include "../Share/lib_errorHandler.h"


int main(int argc, char *argv[])
{
	if (ensureArgs(argc, EXPECTED_ARGC, argv) != TRUE)
		raiseError(ERROR_ID_1, __FILE__, __LINE__, __func__, ERROR_ID_1_CONTENT);


	return(FALSE);
}