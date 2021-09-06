#include <Windows.h>
#include<iostream>

int main()
{
    HANDLE hFile = CreateFile(L"C:\\abc1.txt", GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS,0,0);
    CloseHandle(hFile);
    if (hFile == FALSE) {
        std::cout << "hFile Create Fails & Error No : " << GetLastError() << std::endl;
    }
    std::cout << "hFile Creation Success : " << std::endl;

    CloseHandle (hFile);

    system("pause");
    return 0;
}
