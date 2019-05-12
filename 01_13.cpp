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
private: //非公開だよ
    double MonteCarlo();
public: //公開
    void program013();
};

void test_ramdom();

/*　モンテカルロサンプリング
**　<https://www.procrasist.com/entry/pi_1>
** 1．(x,y) を，両方とも-1から1の範囲でランダムに選択
** 2．x＾2+y＾2を計算
** 3．x＾2+y＾2　<=　1 なら +1, x＾2+y＾2　>　1 なら何もしない
** 4．N回繰り返して点をばらまく
** 5．x＾2+y＾2　<=　1だった点の数をNで割る
*/
double StudyCplus::MonteCarlo(){
    double x,y;
    unsigned long n;
    //ランダム値の作成
    random_device rnd;     // 非決定的な乱数生成器を生成
    mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
    uniform_int_distribution<> rand1000000(1, MAXNUM);        // [0, 99] 範囲の一様乱数
    uniform_int_distribution<> rand10(1, 10);        // [1,10] 範囲の一様乱数

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
    cout << "π：" << 4.0*(double)n / MAXNUM <<endl;
    return 0;
};



//πの計算
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
