#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include <vector>
#include <random>
using namespace std;

//　再帰的処理
template<typename T>
int mininum(T x,T y) {
    // 単なる比較
    return x < y ? x : y;
}
template<typename T, typename... Rest>
int mininum(T x, Rest... rest) {
    return mininum(x,mininum(rest...));
}

int main(){

    int ret = 0;
    ret = mininum(9,10);
    cout << "test001 " << "mininum(9,10) = " << ret << endl;
    ret = mininum(10,4);
    cout << "test002 " << "mininum(10,4) = " << ret << endl;

    ret = mininum(8,3,10);
    cout << "test003 " << "mininum(8,3,10) = " << ret << endl;
    ret = mininum(3,4,5);
    cout << "test004 " << "mininum(3,4,5) = " << ret << endl;
    ret = mininum(10,9,8,7);
    cout << "test005 " << "mininum(10,9,8,7) = " << ret << endl;

    return 0;
}

