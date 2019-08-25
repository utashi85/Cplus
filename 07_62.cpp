#include <string>
#include <vector>
#include <iostream>

#include <windows.h>

using namespace std;

const vector<uint16_t> data{16, 8, 9, 22, 14, 7, 5, 4, 3, 23};
uint16_t dataMini;
uint16_t dataMax;

DWORD WINAPI getMini(LPVOID vdParam)
{
    dataMini = data[0];

    for (uint16_t index = 1; index < data.size(); index++)
    {
        dataMini = (dataMini < data[index] ? dataMini : data[index]);
    }
}

DWORD WINAPI getmMax(LPVOID vdParam)
{
    dataMax = data[0];

    for (uint16_t index = 1; index < data.size(); index++)
    {
        dataMax = (dataMax > data[index] ? dataMax : data[index]);
    }
}

int main()
{
    HANDLE hThread[2];
    DWORD dwThreadId[2];

    dataMini = 0;
    dataMax = 0;

    //スレッド起動
    hThread[0] = CreateThread(
        NULL,            //セキュリティ属性
        0,               //スタックサイズ
        getMini,         //スレッド関数
        NULL,            //スレッド関数に渡す引数
        0,               //作成オプション(0またはCREATE_SUSPENDED)
        &dwThreadId[0]); //スレッドID

    hThread[1] = CreateThread(
        NULL,            //セキュリティ属性
        0,               //スタックサイズ
        getmMax,         //スレッド関数
        NULL,            //スレッド関数に渡す引数
        0,               //作成オプション(0またはCREATE_SUSPENDED)
        &dwThreadId[1]); //スレッドID

    //スレッドの終了を待つ
    for (HANDLE &hT : hThread)
    {
        WaitForSingleObject(hT, INFINITE);
        CloseHandle(hT);
    }
    cout << "mini:" << dataMini << "\n"
         << "max:" << dataMax << endl;

    return 0;
}
