#include <iostream>
#include <cmath>
using namespace std;

class StudyCplus
{
private: //非公開だよ
    bool isPrime(int x);
    int sumDivisor(int num);
    int excessiveNumber(int num);
public: //公開
    void program007(int num);
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
        //std::cout << "fmod(" << x << "," << i << ")=" << fmod(x,i) << "\n";
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
** 友愛数 
** 一方の数の真の約数の総和がもう一方の数と等しくなり、互いにそうなるとき、その 2つの数を友愛数（amicable numbers）と言います。
** 友愛数をフレンドリー数（friendly numbers） ＊1と混同してはいけません。
** 例えば、220の真の約数は1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110でその総和は284。
** 284 の真の約数は1, 2, 4, 71, 142でその総和は220なので、220と284は友愛数です。
** この問題の解法は与えられた上限まですべての数について繰り返し計算して、真の 約数の総和を計算することです。
** その総和をsum1とすると、sum1の真の約数の総和も 計算して、それが元の数と等しいかどうか調べます。等しければ、元の数とsum1は友愛数です。
*/
void StudyCplus::program007(int num)
{
    int x;

    for(int i=num;i>0;i--)
    {
        x = StudyCplus::sumDivisor(i);
        if(x>1 && i > x){
//        if(x>1){
            //過剰は除く
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