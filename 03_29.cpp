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
#define TORF(X) X?"True":"False" 

bool isNumber(string x){
    for(int i=0;i<x.size();i++){
        if((UTF80>x[i]) || (UTF89<x[i])){ return false; }
    }
    return true;
}

bool isBigAtoZ(string x){
    for(int i=0;i<x.size();i++){
        if((UTF8A>x[i]) || (UTF8Z<x[i])){ return false; }
    }
    return true;
}


bool numberPlate(string str,string& ret)
{
    vector<string> v_plate;

    string item;
    istringstream stream(str);

    /** split **/
    getline(stream,item,(char)UTFHYPHEN);
    if(item.empty()||3!=item.size()||!isBigAtoZ(item)){return false;}
    v_plate.push_back(item);

    getline(stream,item,(char)UTFSP);
    if(item.empty()||2!=item.size()||!isBigAtoZ(item)){return false;}
    v_plate.push_back(item);
    v_plate.push_back(str.substr( (int)stream.tellg()));
    if(3>v_plate[2].size()||4<v_plate[2].size()||!isNumber(v_plate[2])){return false;}

    for(auto x:v_plate){ret+=x;}

    return true;
};


int main()
{
    string test = "ABC-XZ 6901";
    string ret = "";
    if( !numberPlate(test,ret) ){return 0;};
    cout<<ret<<endl;

    test = "ABAC-XZ 6901";
    if( numberPlate(test,ret) ){return 0;};
    cout<<test<<"<<";
    cout<<"OK"<<endl;

    test = "ABC-XZZ 6901";
    if( numberPlate(test,ret) ){return 0;};
    cout<<test<<"<<";
    cout<<"OK"<<endl;

    test = "A1C-XZ 6901";
    if( numberPlate(test,ret) ){return 0;};
    cout<<test<<"<<";
    cout<<"OK"<<endl;

    test = "ABC-XZ A901";
    if( numberPlate(test,ret) ){return 0;};
    cout<<test<<"<<";
    cout<<"OK"<<endl;

    test = "abc-XZ 6901";
    if( numberPlate(test,ret) ){return 0;};
    cout<<test<<"<<";
    cout<<"OK"<<endl;

    test = "abc_XZ 6901";
    if( numberPlate(test,ret) ){return 0;};
    cout<<test<<"<<";
    cout<<"OK"<<endl;

    test = "abc XZ-6901";
    if( numberPlate(test,ret) ){return 0;};
    cout<<test<<"<<";
    cout<<"OK"<<endl;

    test = "abc-XZ_6901";
    if( numberPlate(test,ret) ){return 0;};
    cout<<test<<"<<";
    cout<<"OK"<<endl;

    return 0;
};

