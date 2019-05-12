#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

struct ROMAN_NUM {
    int num;
    char* roman;
};

ROMAN_NUM roman[] = 
{
    {1,"Ⅰ"}
};

class StudyCplus
{
private: //非公開だよ
    bool isPrime(int x);
    int sumDivisor(int num);
    int excessiveNumber(int num);
    int ArmstrongNumber(int digit);

    unsigned int grayEncode(unsigned int num);
    unsigned int grayDecode(unsigned int num);

public: //公開
    void program010();
};

/*
**素数判定(エラトステネスの篩)
**https://ja.wikipedia.org/wiki/%E3%82%A8%E3%83%A9%E3%83%88%E3%82%B9%E3%83%86%E3%83%8D%E3%82%B9%E3%81%AE%E7%AF%A9
*/
bool StudyCplus::isPrime(int x)
{
    //0と１は素数でない
    if(x < 2) return false;
    //偶数は素数でない
    if(0 == fmod(x,2)) return false;

    //1-8までの素数を判定済み
    //奇数のみの判定でよい＆元の値の平方根まで
    for(int i=3;i <= sqrt(x);i+=2)   {
        //割り切れたので素数でない
        //cout << "fmod(" << x << "," << i << ")=" << fmod(x,i) << "\n";
        if(0==fmod(x,i)) return false;
    };
    return true;
};

/*
** 約数の総和
*/
int StudyCplus::sumDivisor(const int num)
{
    int ret=1;

    //1，2，3は素数なので１
    if(4>num){ return ret; };

    //素因数は平方根以下
    for(int i=2;i<=sqrt(num);i++){
        if(0 == fmod(num,i)){
            //割り切れる
            ret+=i;
            //商も約数になる ただし平方根の場合は同じ同じ値なので加算しない。
            if(i!=(num/i)){ ret+=num/i;  };
        }else{
            //割り切れない 何もしない
        };
    };

    return ret;
};

/*
** アームストロング数
** Michael F . Armstrongにちなんだアームストロング数はナルシシスト数、拡張完全数（plus perfect number）、
** 拡張完全桁不変数（pluperfect digital invariant）という呼び名もありますが、ある数の桁数がnのとき、
** その数の各桁の数のn乗の総和が元の数と 等しい数です。
** 例えば、3桁の最小のアームストロング数は153で13＋53＋33と等しく なります。 
*/
int StudyCplus::ArmstrongNumber(int digit)
{
    long long max_num;  //最大値
    long long num;  //最大値

    if(digit < 2 ){
        num = -1;
    };

    num = 10 ^ (digit-1);//指定桁の最小値
    max_num = 10 ^ (digit) - 1;
    while(num<0){

        num++;
        //問題発生時
        if(num>max_num){num=-1;};
    };
    return num;
};

/*
** グレイコード　エンコード
*/
unsigned int StudyCplus::grayEncode(unsigned int num)
{
    //隣のBitのNorを取る
    return num ^ (num >> 1);
};

/*
** グレイコード　デコード
*/
unsigned int StudyCplus::grayDecode(unsigned int num)
{
    unsigned int tmp=0;
    unsigned int ret=0;
    tmp = num;
    ret = num;
    do{
        //ビットシフト　右へ１
        tmp>>=1;
        ret^=tmp;
    }while(0!=tmp); //tmpが０になったら終わり

    return ret;
};


void StudyCplus::program010()
{
    unsigned int x;

    cout << "グレイコード" << endl;
    for(unsigned int i = 0;i < 32;i++)
    {
        x = StudyCplus::grayEncode(i);
        cout << std::bitset<8>(i) << "\t" << std::bitset<8>(x) << "\t" << std::bitset<8>(StudyCplus::grayDecode(x)) << endl;
    }
    return;
};

int main()
{
    StudyCplus ctest;
    cout << "ST program010 ===================" << endl;
    ctest.program010();
    return 0;
};