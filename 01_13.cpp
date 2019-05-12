#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include <vector>
#include <random>
using namespace std;

#define MAXNUM 100000

struct ROMAN_NUM {
    int num;
    string roman;
};

class StudyCplus
{
private: //����J����
    double MonteCarlo();
public: //���J
    void program013();
};

void test_ramdom();

/*�@�����e�J�����T���v�����O
**�@<https://www.procrasist.com/entry/pi_1>
** 1�D(x,y) ���C�����Ƃ�-1����1�͈̔͂Ń����_���ɑI��
** 2�Dx�O2+y�O2���v�Z
** 3�Dx�O2+y�O2�@<=�@1 �Ȃ� +1, x�O2+y�O2�@>�@1 �Ȃ牽�����Ȃ�
** 4�DN��J��Ԃ��ē_���΂�܂�
** 5�Dx�O2+y�O2�@<=�@1�������_�̐���N�Ŋ���
*/
double StudyCplus::MonteCarlo(){
    double x,y;
    unsigned long n;
    //�����_���l�̍쐬
    random_device rnd;     // �񌈒�I�ȗ���������𐶐�
    mt19937 mt(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
    uniform_int_distribution<> rand1000000(1, MAXNUM);        // [0, 99] �͈͂̈�l����
    uniform_int_distribution<> rand10(1, 10);        // [1,10] �͈͂̈�l����

    n=0;
    for (int i = 0; i < MAXNUM; ++i) {
        x = (double)(rand1000000(mt)) / MAXNUM;
        y = (double)(rand1000000(mt)) / MAXNUM;
        if(0==fmod(rand10(mt),2)){ x *= -1; };
        if(0==fmod(rand10(mt),2)){ y *= -1; };
        if(1 < pow(x,2)+pow(y,2)){

        }else{
            n++;
        };
    }
    cout << n << endl;
    cout << "�΁F" << 4.0*(double)n / MAXNUM <<endl;
    return 0;
};



//�΂̌v�Z
void StudyCplus::program013()
{
    MonteCarlo();
    return;
};

int main()
{
    StudyCplus ctest;
    cout << "ST program013 ===================" << endl;
    ctest.program013();
    return 0;
};
