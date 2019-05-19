#include <algorithm>
#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <random>
#include <cassert>
using namespace std;

template<class C, class T>
//　配列内に該当の値があるか？
bool isContains(C const & c,T const & value)
{
    //std::find(first, last, value) は、[first, last) の範囲を検索し、value を発見した場合は、
    //そこへのイテレータを、発見できなかった場合は、last を返す。
    return cend(c) != find(cbegin(c),cend(c),value);
}

template<class C, class... T>
// 1つでもあれば
bool contains_any(C const & c,T &&... vaule)
{  
    //和
    return (... || isContains(c, vaule));
}

template<class C, class... T>
// すべて
bool contains_all(C & c,T &&... vaule)
{
    //積
    return (... && isContains(c, vaule));
}

template<class C, class... T>
bool contains_non(C & c,T &&... vaule)
{
    //forward:関数テンプレートの引数を転送する
    //すべてnotなので和の否定
    return !contains_any(c,forward<T>(vaule) ...);
}

int main(){

    // assertはFalseになるとその先処理しない。

    vector<int> v{1,2,3,4,5,6};
    cout << isContains(v,0) << endl;
    cout << isContains(v,1) << endl;
    cout << isContains(v,6) << endl;
    cout << isContains(v,7) << endl;

    assert(contains_any(v,0,3,30));
    cout << "any True" << endl;

    array<int,6> a{1,2,3,4,5,6};
    assert(contains_all(a,1,3,5,6));
    cout << "all True" << endl;

    list<int> l{1,2,3,4,5,6};
    assert(!contains_non(l,0,6));
    cout << "not all" << endl;

    return 0;
}

