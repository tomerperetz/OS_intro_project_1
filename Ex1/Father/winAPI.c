#include "winAPI.h"

/**
* Demonstrates win32 process creation and termination.
*/
int CreateProcessSimpleMain(char *command)
{
	PROCESS_INFORMATION procinfo;
	DWORD				waitcode;
	DWORD				exitcode;
	BOOL				retVal;
	
	retVal = CreateProcessSimple(command, &procinfo);


	if (retVal == 0)
	{
		printf("Process Creation Failed!\n");
		return ERR;
	}


	waitcode = WaitForSingleObject(
		procinfo.hProcess,
		INFINITE); /* Waiting 5 secs for the process to end */

	//printf("WaitForSingleObject output: ");
	//switch (waitcode)
	//{
	//case WAIT_TIMEOUT:
	//	printf("WAIT_TIMEOUT\n"); break;
	//case WAIT_OBJECT_0:
	//	printf("WAIT_OBJECT_0\n"); break;
	//default:
	//	printf("0x%x\n", waitcode);
	//}

	//if (waitcode == WAIT_TIMEOUT) /* Process is still alive */
	//{
	//	printf("Process was not terminated before timeout!\n"
	//		"Terminating brutally!\n");
	//	TerminateProcess(
	//		procinfo.hProcess,
	//		BRUTAL_TERMINATION_CODE); /* Terminating process with an exit code of 55h */
	//	Sleep(10); /* Waiting a few milliseconds for the process to terminate */
	//}

	GetExitCodeProcess(procinfo.hProcess, &exitcode);

	//printf("The exit code for the process is 0x%x\n", exitcode);


	CloseHandle(procinfo.hProcess); /* Closing the handle to the process */
	CloseHandle(procinfo.hThread); /* Closing the handle to the main thread of the process */
	return exitcode;
}

// oOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO /

BOOL CreateProcessSimple(LPTSTR CommandLine, PROCESS_INFORMATION *ProcessInfoPtr)
{
	STARTUPINFO	startinfo = { sizeof(STARTUPINFO), NULL, 0 }; /* <ISP> here we */
															  /* initialize a "Neutral" STARTUPINFO variable. Supplying this to */
															  /* CreateProcess() means we have no special interest in this parameter. */
															  /* This is equivalent to what we are doing by supplying NULL to most other */
															  /* parameters of CreateProcess(). */

	return CreateProcess(NULL, /*  No module name (use command line). */
		CommandLine,			/*  Command line. */
		NULL,					/*  Process handle not inheritable. */
		NULL,					/*  Thread handle not inheritable. */
		FALSE,					/*  Set handle inheritance to FALSE. */
		NORMAL_PRIORITY_CLASS,	/*  creation/priority flags. */
		NULL,					/*  Use parent's environment block. */
		NULL,					/*  Use parent's starting directory. */
		&startinfo,				/*  Pointer to STARTUPINFO structure. */
		ProcessInfoPtr			/*  Pointer to PROCESS_INFORMATION structure. */
	);
}