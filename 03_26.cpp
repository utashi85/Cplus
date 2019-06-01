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

bool capitalize(vector<string> v_input , string s_separator , string& s_response){
    s_response = "";
    for(auto x:v_input){
        if(0!=s_response.length()){s_response += s_separator;}
        s_response += x;
    }
    return true;
}

int main(){
    vector<string> v_input{"this","is","an","example"};
    string s_separator = u8" ";
    string s_response;
    if(capitalize(v_input,s_separator,s_response)){
        cout<<">"<<s_response<<"<"<<endl;
    }
    return 0;
}
