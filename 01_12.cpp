#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

struct ROMAN_NUM {
    int num;
    string roman;
};

class StudyCplus
{
private: //非公開だよ
    unsigned int countCollatz(unsigned int num);
public: //公開
    void program012();
};

unsigned int StudyCplus::countCollatz(unsigned int num){
    unsigned int counter;
    unsigned long long tmp;

    counter = 0;
    tmp = (unsigned long long)num;

    do{
        if(0==fmod(tmp,2)){
            tmp = tmp/2;
        }else{
            tmp = 3*tmp+1;
        };
        counter++;
    }while(1<tmp);
//    cout << num << ":" << counter << endl;
    return counter;
};


//最長コラッツ数列 
void StudyCplus::program012()
{
    unsigned int maxCollatzNum,maxCollatz;
    unsigned int Collatz;

    maxCollatzNum=0;
    maxCollatz=0;

    for(unsigned int i=2;i<=1000000;i++)
    {
        Collatz = countCollatz(i);
        if(maxCollatz<Collatz){
            maxCollatz = Collatz;
            maxCollatzNum = i;
        };
    };
    cout << "最長コラッツ数列　先頭:" << maxCollatzNum << " 列数:" << maxCollatz <<endl;
    return;
};

int main()
{
    StudyCplus ctest;
    cout << "ST program012 ===================" << endl;
    ctest.program012();
    return 0;
};