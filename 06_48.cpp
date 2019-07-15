#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class map_c
{
private:
    map<uint16_t, uint16_t> data;

public:
    void setVector(vector<uint16_t> input)
    {
        for (uint16_t x : input)
        {
            data[x] += 1;
        }
    }

    void setVector(uint16_t input)
    {
        data[input] += 1;
    }

    vector<pair<uint16_t, uint16_t>> findMostFrequent()
    {
        vector<pair<uint16_t, uint16_t>> result;

        auto maxElem = *max_element(cbegin(data), cend(data),
                                    [](auto const &a, auto const &b) { return (a.second < b.second); });

        for (auto x : data)
        {
            if (x.second == maxElem.second)
                result.push_back(make_pair(x.first, x.second));
        }
        return result;
    }
};

int main()
{
    map_c test;
    vector<uint16_t> testData{1, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5};
    test.setVector(testData);
    vector<pair<uint16_t, uint16_t>> result = test.findMostFrequent();

    for (auto x : result)
    {
        cout << x.first << ":" << x.second << endl;
    }

    return 0;
}
