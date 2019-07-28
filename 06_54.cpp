#include <iostream>
#include <vector>

using namespace std;

class pair_c
{
private:
    int buf;
    bool isBuf = false;

public:
    vector<pair<int, int>> list;
    void set(int input)
    {
        if (isBuf)
        {
            list.push_back(make_pair(buf, input));
            isBuf = false;
            return;
        }
        buf = input;
        isBuf = true;
    }
};

int main()
{
    vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};
    pair_c test;

    for (int x : data)
    {
        test.set(x);
    }

    for (pair<int, int> pair : test.list)
    {
        cout << "{" << pair.first << "," << pair.second
             << "}" << endl;
    }
    return 0;
}
