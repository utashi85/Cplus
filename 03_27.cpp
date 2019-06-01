#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define UTFSP 0x20
//#define PATTERN_FIND
using namespace std;

bool split(string s_input ,string s_delims , vector<string>& v_response){
    const char delim = UTFSP;

    /** 置換 **/
    for(int i=1;i < s_delims.size();i++){
#ifdef PATTERN_FIND
        unsigned int pos = s_input.find(s_delims[i]);
        while(pos != string::npos){
            s_input[pos]=s_delims[0];
            pos = s_input.find(s_delims[i]);
        }
#else
        for(int j=0;j<s_input.size();j++){
            if(s_input[j]==s_delims[i]){s_input[j]=s_delims[0];}
        }
#endif
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

int main(){
    vector<string> v_response;
    string s_delims = "!, ";
    string s_input = u8"testStart 03!27,hoge!hoge!testEnd";
    if(split(s_input,s_delims,v_response)){
        cout << "{"<<endl;
        for(auto x:v_response){
            cout<<">"<<x<<"<"<<endl;
        }
        cout << "}"<<endl;
    }
    return 0;
}
