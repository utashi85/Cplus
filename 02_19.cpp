#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include <vector>
#include <list>
#include <random>
using namespace std;

//push_backを再帰的に処理する。
template<typename T, typename... Rest>
void push_back(T&& x, Rest&&... rest) {
    (x.push_back(rest), ...);
}

int main(){

    int i;
    vector<int> v;
    push_back(v,10,21,33,41);
    cout << "test001 :"; 
    for(int x : v)
    {
        cout << " " << x;
    };
    cout << endl;

    list<int> ls;
    push_back(ls,10,21,33,41);
    cout << "test002 :"; 
    for (int y : ls) {
        cout << " "  << y ;
    };
    cout << endl;
    return 0;
}

