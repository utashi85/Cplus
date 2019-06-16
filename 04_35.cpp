#include <cassert>

#include <stdio.h>
#include <iostream>
#include <string>

#include <windows.h>

#include <filesystem>
#include <sys/stat.h>

using namespace std;

#define thisFolder "C:\\Temp\\Cplus"

uintmax_t sumDirectorySize(string strFolder)
{

    HANDLE hFind;
    WIN32_FIND_DATA win32fd;
    uintmax_t ret = 0;
    string tmpFolder = strFolder + "\\*.*";

    hFind = FindFirstFile(tmpFolder.c_str(), &win32fd);

    assert(hFind != INVALID_HANDLE_VALUE);

    do
    {
        string tmpStr = strFolder + "\\" + win32fd.cFileName;
        if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if ((0 != strcmp(win32fd.cFileName, ".")) && (0 != strcmp(win32fd.cFileName, "..")))
            {
                ret += sumDirectorySize(tmpStr);
            }
        }
        else
        {
            cout << tmpStr << " :: " << win32fd.nFileSizeHigh * MAXDWORD + win32fd.nFileSizeLow << endl;
            ret += win32fd.nFileSizeHigh * MAXDWORD + win32fd.nFileSizeLow;
        }
    } while (FindNextFile(hFind, &win32fd));

    FindClose(hFind);

    return ret;
}

int main()
{
    uintmax_t ret = sumDirectorySize(thisFolder)/(1024*1024);

    cout << thisFolder << " Size(MB):" << ret << endl;
}
