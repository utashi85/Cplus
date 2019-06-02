#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#define UTFSP 0x20
#define UTF80 0x30
#define UTF89 0x39
#define UTF8A 0x41
#define UTF8Z 0x5a
#define UTF8a 0x61
#define UTF8z 0x7a
#define UTFHYPHEN 0x2D

bool isNumber(string x){
    for(int i=0;i<x.size();i++){
        if((UTF80>x[i]) || (UTF89<x[i])){ return false; }
    }
    return true;
}

bool split(string s_input ,string s_delims , vector<string>& v_response){
    const char delim = UTFSP;

    /** 置換 **/
    for(int i=1;i < s_delims.size();i++){
        for(int j=0;j<s_input.size();j++){
            if(s_input[j]==s_delims[i]){s_input[j]=s_delims[0];}
        }
    }

    s_delims.c_str();
    string item;
    istringstream stream(s_input);

    /** split **/
    while(getline(stream,item,s_delims[0])) {
        if(!item.empty()) {
            v_response.push_back(item);
        }
    }
    return true;
}

bool covForm(string input,string& reForm){
    vector<string> v_input;
    split(input,"-.",v_input);
    string tmp="";
    if(3!=v_input.size()){ return false; }
    for(int i=0;i<3;i++){
        if(4==v_input[i].size()){
            if(1==i){return false;}
            if(2==i){
                tmp=v_input[i];
                v_input[i]=v_input[0];
                v_input[0]=tmp;
            }
        }else if(2!=v_input[i].size()){
            return false;
        }
    }
    reForm = v_input[0] + "-" + v_input[1] + "-" + v_input[2];
    return true;
}



int main()
{
    string test = "2019-06-02";
    string ret = "";
    if( !covForm(test,ret) ){return 0;};
    cout<<ret<<endl;

    test = "02.06.2019";
    if( !covForm(test,ret) ){return 0;};
    cout<<ret<<endl;

    test = "02-06-2019";
    if( !covForm(test,ret) ){return 0;};
    cout<<ret<<endl;

    return 0;
};

