#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include <vector>
#include <random>
using namespace std;

#define STU8NUMBER 0x30
#define EDU8NUMBER 0x39
#define U8HYPHEN 0x2d
#define U8BIGX 0x58

class StudyCplus
{
private: //非公開だよ
    bool isIsbn10(string str_code);
public: //公開
    void program014();
};


bool StudyCplus::isIsbn10(string str_code)
{
    unsigned int sum;
    unsigned int counter;
    unsigned int x;
    sum = 0;
    counter = 10;

    //10文字かチェック
//    cout << showbase;
    if(10!=str_code.size()){
        cout << "[Err]10文字以上です。" << endl;
        return false;
    };

    for(int i=0;i<str_code.size();++i){
        x = (unsigned int)str_code[i];
        //数字かチェック
        if(STU8NUMBER<=x && EDU8NUMBER>=x){
            sum += (x-STU8NUMBER)*(counter);
            counter--;
        }else if(U8BIGX==x && 1==counter){
            //チェックサムは10の時はX(大文字)
            //1==counter⇒最終
            sum += (10)*(counter);
            counter--;
        }else if(U8HYPHEN==x){
            
        }else{
            cout << "[Err]不正な文字が含まれています。" << endl;
            return false;
        };
    };
//    cout << "|" << endl;
//    cout << noshowbase;
    if(0!=counter){
        cout << "[Err]数字が" << 10 - counter << "個ありました。" << endl;
        return false;
    };

    if(0!=fmod(sum,11)){
        //不正
        cout << "[Err]ISBNではありません。チェックサムエラー" << endl;
        return false;
    };

    cout << "[OK]ISBNです。" << endl;
    return true;
};

//ISBNの検証 
/*
文字列として与えられた10桁の値が、10桁のISBN-10番号として正しいかどうか検 証するプログラムを書きなさい
*/
void StudyCplus::program014()
{
    string str;


    str = u8"4771010676";
    cout << "\nISBN:" << str << endl;
    isIsbn10(str);

    str = u8"477101065X";
    cout << "\nISBN:" << str << endl;
    isIsbn10(str);

    str = u8"4771011676";
    cout << "\nNot ISBN:" << str << endl;
    isIsbn10(str);

    str = u8"aaaaaaaaaa";
    cout << "\n不正文字10文字:" << str << endl;
    isIsbn10(str);

    str = u8"XXXXXXXXXX";
    cout << "\n不正文字10文字:" << str << endl;
    isIsbn10(str);

    str = u8"12345678901";
    cout << "\n数字11文字:" << str << endl;
    isIsbn10(str);

    return;
};

int main()
{
    StudyCplus ctest;
    cout << "ST program014 ===================" << endl;
    ctest.program014();
    return 0;
};
