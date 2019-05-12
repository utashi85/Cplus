#include <iostream>
#include <cmath>
using namespace std;

class StudyCplus
{
private: //����J����
    bool isPrime(int x);
    int sumDivisor(int num);
    int excessiveNumber(int num);
public: //���J
    void program006(int num);
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
        //std::cout << "fmod(" << x << "," << i << ")=" << fmod(x,i) << "\n";
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
** �ߏ萔 
** �ߏ萔�iabundant number, excessive number�j�́A�^�̖񐔂̑��a�����̐����� �傫���Ȃ鐔�ł��B
** �^�̖񐔂Ƃ́A���̐����g�����������̖񐔂ł��B�^�̖񐔂̑� �a���炻�̐��������������l���ߏ�ƌ����܂��B
** �Ⴆ�΁A 12�̐^�̖񐔂�1, 2, 3, 4, 6�ŁA ���̑��a��16�ł��B�܂�12�͉ߏ萔�ŁA4�i��16�|12�j���ߏ�ł��B 
*/

void StudyCplus::program006(int num)
{
    int x;

    for(int i=num;i>0;i--)
    {
        x = StudyCplus::sumDivisor(i);
        if(x>i){
            std::cout << "### " << i << "\texcessive number " << x - i << "\n";
        };
    };
    return;
};

int main()
{
    StudyCplus ctest;
    std::cout << "ST program006 ===================\n";
    ctest.program006(10000);
    return 0;
};