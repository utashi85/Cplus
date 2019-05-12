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
private: //����J����
    vector<ROMAN_NUM> romanBox {
        {1000,"M"},{900,"CM"},
        {500,"D"},{400,"CD"},
        {100,"C"},{90,"�]C"},
        {50,"L"},{40,"�]L"},
        {10,"�]"},{9,"�T�]"},
        {5,"�X"},{4,"�W"},
        {1,"�T"}
    };
    bool isPrime(int x);
    int sumDivisor(int num);
    int excessiveNumber(int num);
    int ArmstrongNumber(int digit);
    void outRomaNumber(int num);

    unsigned int grayEncode(unsigned int num);
    unsigned int grayDecode(unsigned int num);

public: //���J
    void program011();
};

/*
**�f������(�G���g�X�e�l�X���)
**https://ja.wikipedia.org/wiki/%E3%82%A8%E3%83%A9%E3%83%88%E3%82%B9%E3%83%86%E3%83%8D%E3%82%B9%E3%81%AE%E7%AF%A9
*/
bool StudyCplus::isPrime(int x)
{
    //0�ƂP�͑f���łȂ�
    if(x < 2) return false;
    //�����͑f���łȂ�
    if(0 == fmod(x,2)) return false;

    //1-8�܂ł̑f���𔻒�ς�
    //��݂̂̔���ł悢�����̒l�̕������܂�
    for(int i=3;i <= sqrt(x);i+=2)   {
        //����؂ꂽ�̂őf���łȂ�
        //cout << "fmod(" << x << "," << i << ")=" << fmod(x,i) << "\n";
        if(0==fmod(x,i)) return false;
    };
    return true;
};

/*
** �񐔂̑��a
*/
int StudyCplus::sumDivisor(const int num)
{
    int ret=1;

    //1�C2�C3�͑f���Ȃ̂łP
    if(4>num){ return ret; };

    //�f�����͕������ȉ�
    for(int i=2;i<=sqrt(num);i++){
        if(0 == fmod(num,i)){
            //����؂��
            ret+=i;
            //�����񐔂ɂȂ� �������������̏ꍇ�͓��������l�Ȃ̂ŉ��Z���Ȃ��B
            if(i!=(num/i)){ ret+=num/i;  };
        }else{
            //����؂�Ȃ� �������Ȃ�
        };
    };

    return ret;
};

/*
** �A�[���X�g�����O��
** Michael F . Armstrong�ɂ��Ȃ񂾃A�[���X�g�����O���̓i���V�V�X�g���A�g�����S���iplus perfect number�j�A
** �g�����S���s�ϐ��ipluperfect digital invariant�j�Ƃ����Ăі�������܂����A���鐔�̌�����n�̂Ƃ��A
** ���̐��̊e���̐���n��̑��a�����̐��� ���������ł��B
** �Ⴆ�΁A3���̍ŏ��̃A�[���X�g�����O����153��13�{53�{33�Ɠ����� �Ȃ�܂��B 
*/
int StudyCplus::ArmstrongNumber(int digit)
{
    long long max_num;  //�ő�l
    long long num;  //�ő�l

    if(digit < 2 ){
        num = -1;
    };

    num = 10 ^ (digit-1);//�w�茅�̍ŏ��l
    max_num = 10 ^ (digit) - 1;
    while(num<0){

        num++;
        //��蔭����
        if(num>max_num){num=-1;};
    };
    return num;
};

/*
** �O���C�R�[�h�@�G���R�[�h
*/
unsigned int StudyCplus::grayEncode(unsigned int num)
{
    //�ׂ�Bit��Nor�����
    return num ^ (num >> 1);
};

/*
** �O���C�R�[�h�@�f�R�[�h
*/
unsigned int StudyCplus::grayDecode(unsigned int num)
{
    unsigned int tmp=0;
    unsigned int ret=0;
    tmp = num;
    ret = num;
    do{
        //�r�b�g�V�t�g�@�E�ւP
        tmp>>=1;
        ret^=tmp;
    }while(0!=tmp); //tmp���O�ɂȂ�����I���

    return ret;
};

/*
** ���[�}�����ɕϊ����ĕ\��
*/
void StudyCplus::outRomaNumber(int num)
{
    int tmp,i;
    tmp = num;
    i = 0;

    cout << num << " ���[�}�����@>> ";
    do{
        if(tmp>=romanBox[i].num){
            tmp-=romanBox[i].num;
            cout << romanBox[i].roman;
        }else{
            i++;
        };
    }while(0<tmp);
    cout << endl;

    return;
};

void StudyCplus::program011()
{
    for(int i=1;i<2000;i++)
    {
        outRomaNumber(i);
    };
    return;
};

int main()
{
    StudyCplus ctest;
    cout << "ST program011 ===================" << endl;
    ctest.program011();
    return 0;
};