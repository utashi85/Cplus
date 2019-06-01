#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define UTFSP 0x20
//#define PATTERN_FIND
using namespace std;

/**
 * 回文判定 
 **/
bool isPalindrome(string s_input){
    for(int i=0;i<s_input.size()/2;i++){
        if(s_input[i]!=s_input[s_input.size()-1-i]){ return false; }
    }
    return true;
}

/**
 * 回文捜査 
 **/
void search_palindrome(string s_input,string& s_ret){
    string tmp;
    for(int i=0;i<s_input.length()-1;i++){
        for(int j=0;j<=i;j++){
            tmp = s_input.substr(j,s_input.length()-i);
            if(isPalindrome(tmp)){
                s_ret = tmp;
                return;
            }
        }
    }
}

int main(){

    string s_input = u8"testtesttsettset";
    string s_ret = "";
    if(isPalindrome(s_input)){
        cout << "test01 OK";
    }else{
        cout << "test01 NG";
    }
    cout << endl;

    s_input = u8"_testtesttsettset";
    string ret = "";
    if(isPalindrome(s_input)){
        cout << "test02 NG";
    }else{
        cout << "test02 OK";
    }
    cout << endl;

    s_input = u8"asdfghjkl;testtesttsettsetlikmnhyuiny";
    search_palindrome(s_input,s_ret);
    cout<<s_ret<<endl;

    return 0;


}
