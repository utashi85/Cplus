#include <iostream>
#include <cmath>
using namespace std;

class StudyCplus
{
private: //非公開だよ
    int maxNum;
    long long sum_multiple(int n);
public: //公開
    long long a_001;
    bool initialize();
    bool setNumber(int n);
    int gcd(int x,int y);
    int lcm(int x,int y);
    int nlcm(int argc,int *argv);
    bool isPrime(int x);
    int maxPrimenumber(int x);
    int sexyPrime(int x);
};

/*
** 指定された値で割り切れる値の総和
*/
long long StudyCplus::sum_multiple(int n)
{
    int intQuotient;
    intQuotient = 0;

    //最大の商
    intQuotient = maxNum / n;
    //自然数の和を求める
    return n*(((intQuotient+1)*intQuotient)/2);
};

bool StudyCplus::initialize()
{
    return true;
};

bool StudyCplus::setNumber(int n)
{
    long long x;
    long long y;
    long long z;
    StudyCplus::maxNum = n;
    x = StudyCplus::sum_multiple(3);
    y = StudyCplus::sum_multiple(5);
    z = StudyCplus::sum_multiple(15);

    StudyCplus::a_001 = x+y-z;
//    std::cout << "x = " <<  x << "\n"; 
//    std::cout << "y = " <<  y << "\n"; 
//    std::cout << "z = " <<  z << "\n"; 
//    std::cout << ">> " <<  ll_x << "\n"; 

};

/*Greatest Common Divisor　最大公約数*/
int StudyCplus::gcd(int x,int y)
{
    int a =0;
    int b =0;
    int c =0;

    /*ユーグリッド*/

    //大きいほうを判定
    if(x > y)
    {
        a=x;b=y;
    }else{
        a=y;b=x;
    };

    do{
        //あまりを算出
        c = fmod(a,b);
        //次は小さい方と余りで割り算
        a = b;b = c;
    }while(c > 0);

    //あまりなしの時の小さい方が最大公約数
    return a;
};

/*least common multiple 最大公倍数*/
int StudyCplus::lcm(int x,int y)
{
    return x*y/StudyCplus::gcd(x,y);
};

/*least common multiple 最大公倍数*/
int StudyCplus::nlcm(int argc,int *argv)
{
    int x;
    x = argv[0];

    for(int i=1; i < argc; i++ )
    {
        x = StudyCplus::lcm(x,argv[i]);
    };

    return x;
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

int StudyCplus::maxPrimenumber(int x)
{
    do{
        if(true == StudyCplus::isPrime(x)) break;
        x--;
    }while(0 < x);
    return x;
};

int StudyCplus::sexyPrime(int x)
{
    for(int i;i+6 <= x;i++)
    {
        if((StudyCplus::isPrime(i))&&(StudyCplus::isPrime(i+6)))
        {
            std::cout << i << " - " << i + 6 << "\n";
        };
    };
};

int main(){
    int j;
    int mondai03_1[3] = {20,25,80};
    int mondai03_2[5] = {15,40,25,5,10};
    StudyCplus cStudyCplus;

//3または5で割り切れる正の整数の総和 
    std::cout << "001==============\n";
    cStudyCplus.setNumber(255);
    std::cout << "A= " << cStudyCplus.a_001 << "\n";
 
 //最大公約数 
    std::cout << "002==============\n";
    std::cout << " 36,24\n";
    std::cout << "greatest common divisor " << cStudyCplus.gcd(36,24) << "\n";
    std::cout << " 255,128\n";
    std::cout << "greatest common divisor " << cStudyCplus.gcd(255,128) << "\n";
 
 //最小公倍数
    std::cout << "003==============\n";
    std::cout << "1 " << cStudyCplus.nlcm(3, mondai03_1) << "\n";
    std::cout << "2 " << cStudyCplus.nlcm(5, mondai03_2) << "\n";
 
 //与えられた正の整数より小さい最大の素数 
    std::cout << "004==============\n";
    std::cout << "255 " << cStudyCplus.maxPrimenumber(255) << "\n";
    std::cout << "9 " << cStudyCplus.maxPrimenumber(9) << "\n";
    std::cout << "7 " << cStudyCplus.maxPrimenumber(7) << "\n";

//セクシー素数
    std::cout << "005==============\n";
    cStudyCplus.sexyPrime(100);
    return 0;
};


