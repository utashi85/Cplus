#include <cassert>

#include <stdio.h>
#include <iostream>
#include <string>

#include <windows.h>

#include <filesystem>
#include <ctime>

using namespace std;

#define thisFolder "C:\\Temp\\Cplus"

bool ckSystemTime(SYSTEMTIME atm, SYSTEMTIME btm)
{
  if (btm.wYear < atm.wYear)
    return false;

  if (btm.wMonth < atm.wMonth)
    return false;

  if (btm.wDay < atm.wDay)
    return false;

  if (btm.wHour < atm.wHour)
    return false;

  return true;
}

void sumDirectorySize(string strFolder)
{

  HANDLE hFind;
  WIN32_FIND_DATA win32fd;
  uintmax_t ret = 0;
  string tmpFolder = strFolder + "\\*.*";

  /** 基準日 */
  SYSTEMTIME stTm;
  stTm.wYear = 2019;
  stTm.wMonth = 6;
  stTm.wDay = 1;
  stTm.wHour = 0;

  hFind = FindFirstFile(tmpFolder.c_str(), &win32fd);

  assert(hFind != INVALID_HANDLE_VALUE);

  do
  {
    /** 時刻取得 */
    FILETIME ftFileTime;
    SYSTEMTIME stFileTime;
    FileTimeToLocalFileTime(&win32fd.ftLastWriteTime, &ftFileTime);
    FileTimeToSystemTime(&ftFileTime, &stFileTime);

    string tmpStr = strFolder + "\\" + win32fd.cFileName;

    /** 基準日より古いか？ */
    if (!ckSystemTime(stTm, stFileTime))
    {
      /** @todo File消す */
      cout << tmpStr << " Let'a DELEATE LastWriteTime :: " << stFileTime.wYear << "/" << stFileTime.wMonth << "/" << stFileTime.wDay << endl;
    }

    /** folderだった場合は再帰する */
    if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
    {
      if ((0 != strcmp(win32fd.cFileName, ".")) && (0 != strcmp(win32fd.cFileName, "..")))
      {
        sumDirectorySize(tmpStr);
      }
    }
  } while (FindNextFile(hFind, &win32fd));

  FindClose(hFind);
}

int main()
{
  sumDirectorySize(thisFolder);
}
