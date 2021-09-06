#define BUILD_WINDOWS
#include <Windows.h>
#include<iostream>
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
	PROCESS_INFORMATION pi;
	STARTUPINFO si = { sizeof(si) };
	TCHAR name[] = _T("notepad");
	BOOL success = CreateProcess(NULL,name, NULL, NULL, FALSE, 0, nullptr, nullptr, &si, &pi);

	if (success) {
		std::cout << "PID :" << pi.dwProcessId << std::endl;
		std::cout << "hProcess : " << pi.hProcess << std::endl;


		WaitForSingleObject(pi.hProcess, INFINITE);
		DWORD code;
		GetExitCodeProcess(pi.hProcess, &code);
		std::cout << "Notepad has Exited . Exit Code : " << code << std::endl;
	}

	else {
		std::cout << "Process Creation Failed & Error No :" <<GetLastError() << std::endl;

	}
	
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	system("pause");
	return 0;
}
