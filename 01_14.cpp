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
private: //����J����
    bool isIsbn10(string str_code);
public: //���J
    void program014();
};


bool StudyCplus::isIsbn10(string str_code)
{
    unsigned int sum;
    unsigned int counter;
    unsigned int x;
    sum = 0;
    counter = 10;

    //10�������`�F�b�N
//    cout << showbase;
    if(10!=str_code.size()){
        cout << "[Err]10�����ȏ�ł��B" << endl;
        return false;
    };

    for(int i=0;i<str_code.size();++i){
        x = (unsigned int)str_code[i];
        //�������`�F�b�N
        if(STU8NUMBER<=x && EDU8NUMBER>=x){
            sum += (x-STU8NUMBER)*(counter);
            counter--;
        }else if(U8BIGX==x && 1==counter){
            //�`�F�b�N�T����10�̎���X(�啶��)
            //1==counter�ˍŏI
            sum += (10)*(counter);
            counter--;
        }else if(U8HYPHEN==x){
            
        }else{
            cout << "[Err]�s���ȕ������܂܂�Ă��܂��B" << endl;
            return false;
        };
    };
//    cout << "|" << endl;
//    cout << noshowbase;
    if(0!=counter){
        cout << "[Err]������" << 10 - counter << "����܂����B" << endl;
        return false;
    };

    if(0!=fmod(sum,11)){
        //�s��
        cout << "[Err]ISBN�ł͂���܂���B�`�F�b�N�T���G���[" << endl;
        return false;
    };

    cout << "[OK]ISBN�ł��B" << endl;
    return true;
};

//ISBN�̌��� 
/*
������Ƃ��ė^����ꂽ10���̒l���A10����ISBN-10�ԍ��Ƃ��Đ��������ǂ����� �؂���v���O�����������Ȃ���
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
    cout << "\n�s������10����:" << str << endl;
    isIsbn10(str);

    str = u8"XXXXXXXXXX";
    cout << "\n�s������10����:" << str << endl;
    isIsbn10(str);

    str = u8"12345678901";
    cout << "\n����11����:" << str << endl;
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
