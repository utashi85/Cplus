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
        auto maxElem = *max_element(cbegin(data), cend(data),
                                    [](auto const &a, auto const &b) { return (a.second < b.second); });
        cout << maxElem.first << ":" << maxElem.second << endl;
    }
};

int main()
{
    map_c test;
    vector<uint16_t> testData{1, 1, 3, 5, 8, 13, 3, 5, 8, 8, 5};
    test.setVector(testData);
    test.findMostFrequent();
    return 0;
}
