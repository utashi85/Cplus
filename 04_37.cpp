#include <cassert>

#include <stdio.h>
#include <iostream>
#include <string>

#include <windows.h>

#include <filesystem>
#include <regex>

using namespace std;

using cmatch = std::match_results<const char *>;

void getMatch(string strMach, string strFolder, vector<string> &ret)
{

    HANDLE hFind;
    WIN32_FIND_DATA win32fd;
    string tmpFolder = strFolder + "\\*.*";

    hFind = FindFirstFile(tmpFolder.c_str(), &win32fd);

    assert(hFind != INVALID_HANDLE_VALUE);

    do
    {

        string tmpStr = strFolder + "\\" + win32fd.cFileName;

        /** folderだった場合は再帰する */
        if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if ((0 != strcmp(win32fd.cFileName, ".")) && (0 != strcmp(win32fd.cFileName, "..")))
            {
                getMatch(strMach, tmpStr, ret);
            }
        }
        else
        {
            cmatch results;
            if (regex_search(win32fd.cFileName, results, regex(strMach.c_str())))
            {
                ret.push_back(win32fd.cFileName);
            }
        }
    } while (FindNextFile(hFind, &win32fd));

    FindClose(hFind);
}

int main()
{
    string strMach = "04";
    string strFolder = "C:\\Temp\\Cplus";
    vector<string> ret;

    getMatch(strMach, strFolder, ret);
    for (auto item : ret)
        cout << item << endl;
}
