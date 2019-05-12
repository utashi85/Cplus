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
    void program007(int num);
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
** �F���� 
** ����̐��̐^�̖񐔂̑��a����������̐��Ɠ������Ȃ�A�݂��ɂ����Ȃ�Ƃ��A���� 2�̐���F�����iamicable numbers�j�ƌ����܂��B
** �F�������t�����h���[���ifriendly numbers�j ��1�ƍ������Ă͂����܂���B
** �Ⴆ�΁A220�̐^�̖񐔂�1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110�ł��̑��a��284�B
** 284 �̐^�̖񐔂�1, 2, 4, 71, 142�ł��̑��a��220�Ȃ̂ŁA220��284�͗F�����ł��B
** ���̖��̉�@�͗^����ꂽ����܂ł��ׂĂ̐��ɂ��ČJ��Ԃ��v�Z���āA�^�� �񐔂̑��a���v�Z���邱�Ƃł��B
** ���̑��a��sum1�Ƃ���ƁAsum1�̐^�̖񐔂̑��a�� �v�Z���āA���ꂪ���̐��Ɠ��������ǂ������ׂ܂��B��������΁A���̐���sum1�͗F�����ł��B
*/
void StudyCplus::program007(int num)
{
    int x;

    for(int i=num;i>0;i--)
    {
        x = StudyCplus::sumDivisor(i);
        if(x>1 && i > x){
//        if(x>1){
            //�ߏ�͏���
            if(i==StudyCplus::sumDivisor(x)){
                std::cout << "### amicable numbers " << i << " || " << x << "\n";
            };
        };
    };
    return;
};

int main()
{
    StudyCplus ctest;
    std::cout << "ST program007 ===================\n";
    ctest.program007(1000000);
    return 0;
};