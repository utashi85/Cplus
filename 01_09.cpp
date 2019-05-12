#include <iostream>
#include <cmath>
using namespace std;

class StudyCplus
{
private: //����J����
    bool isPrime(int x);
    int sumDivisor(int num);
    int excessiveNumber(int num);
    int ArmstrongNumber(int digit);
public: //���J
    void program009(int num);
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
** �f��������
*/
void StudyCplus::program009(int num)
{
    int x;
    int sqrtX;

    cout << num << " �f���������@>>";

    x = num;
    //2�Ŋ������E�܂�
    while(0==fmod(x,2)){
        cout << " 2";
        x=x/2;
    }

    //X��1�ɂȂ������_�ŏI��
    if(1!=x){
        //2�Ŋ���Ȃ�=�c��͊�Ŋ����
        sqrtX = (int)sqrt(x);
        for(int i=3;i<=(int)sqrtX;i+=2)
        {
            //����؂�邩����
            if(0==fmod(x,i))
            {
                cout << " " << i;
                x=x/i;
            };
        };
        if(1!=x)
        {
            //�f�����c����
            cout << " " << x;
        };
    }
    cout << endl;
    return;
};

int main()
{
    StudyCplus ctest;
    cout << "ST program009 ===================" << endl;
    ctest.program009(255);
    ctest.program009(125552);
    return 0;
};