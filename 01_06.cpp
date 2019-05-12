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
    void program006(int num);
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
** 過剰数 
** 過剰数（abundant number, excessive number）は、真の約数の総和が元の数よりも 大きくなる数です。
** 真の約数とは、その数自身を除いた正の約数です。真の約数の総 和からその数を差し引いた値を過剰と言います。
** 例えば、 12の真の約数は1, 2, 3, 4, 6で、 その総和は16です。つまり12は過剰数で、4（＝16－12）が過剰です。 
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