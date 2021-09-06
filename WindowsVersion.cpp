#define BUILD_WINDOWS                                            //Mandiate because the getversionEx was depracted [https://stackoverflow.com/questions/22303824/warning-c4996-getversionexw-was-declared-deprecated/27323983]
#include <Windows.h>
#include<iostream>
#include <tchar.h>

int main(int argc, _TCHAR* argv[])
{
    OSVERSIONINFOEX osv = { sizeof(osv) };

    GetVersionEx((OSVERSIONINFO*)&osv);
     
    std::cout << osv.dwMajorVersion;
    std::cout << osv.dwMinorVersion;

    system("PAUSE");
}
