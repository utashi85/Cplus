#include <iostream>
#include <vector>

using namespace std;

inline int getSize(vector<int> x, vector<int> y)
{
    return x.size() < y.size() ? x.size() : y.size();
}

class pair_c
{
private:
public:
    vector<pair<int, int>> list;
    void set(vector<int> x, vector<int> y)
    {
        for (int idx = 0; idx < getSize(x, y); idx++)
        {
            list.push_back(make_pair(x[idx], y[idx]));
        }
    }
};

int main()
{
    vector<int> data_x{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> data_y{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    pair_c test;

    test.set(data_x, data_y);

    for (pair<int, int> pair : test.list)
    {
        cout << "{" << pair.first << "," << pair.second
             << "}" << endl;
    }
    return 0;
}
