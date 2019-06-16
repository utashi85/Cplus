#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream ifs;
    ofstream ifs_a;
    string str;
    vector<string> newFile;

    /** ファイルオープン失敗 */
    ifs.open("C:\\Temp\\Cplus\\04_34_test.txt");
    if (!ifs.is_open()) {
        cerr << "ifstream err" << endl;
        return -1;
    }

    while (getline(ifs, str)) {
        if(0 != str.size()) {
            newFile.push_back(str);
        }
    }
    ifs.close();

    ifs_a.open("C:\\Temp\\Cplus\\04_34_answer.txt");
    if (!ifs_a.is_open()) {
        cerr << "ofstream err" << endl;
        return -1;
    }
    ifs_a.close();

    for(string line:newFile) {
        ifs_a << line << endl;
    }
}
