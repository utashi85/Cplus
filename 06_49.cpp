#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

/** 型の合うグローバル関数を定義する。 */
template <typename T_char>
T_char ToLower(T_char cX) { return tolower(cX); }

class histogram_c
{
private:
    map<char, uint16_t> data;

public:
    void set(string input)
    {
        string buff = input;
        transform(input.begin(), input.end(), buff.begin(), ToLower<char>);
        /** 初期化 */
        for (char ch = 'a'; ch <= 'z'; ch++)
            data[ch] = 0;

        for (auto x : buff)
        {
            /** 英字？ */
            if (isalpha(x))
                data[x]++; /** 加算 */
        }
    }

    vector<pair<char, uint16_t>> findMostFrequent()
    {
        vector<pair<char, uint16_t>> result;

        auto maxElem =
            *max_element(cbegin(data), cend(data),
                         [](auto const &a, auto const &b) { return (a.second < b.second); });

        for (auto x : data)
        {
            if (x.second == maxElem.second)
                result.push_back(make_pair(x.first, x.second));
        }
        return result;
    }

    void coutAll()
    {
        for (auto elem : data)
        {
            cout << elem.first << ":" << elem.second << endl;
        }
    }
};

int main()
{
    vector<pair<char, uint16_t>> result;
    histogram_c test;
    string text = "I don't take coffee, I take tea, my dear\nI like my toast done on one side\nAnd you can hear it in my accent when I talk\nI'm an Englishman in New York";

    test.set(text);
    result = test.findMostFrequent();

    for (auto x : result)
    {
        cout << x.first << ":" << x.second << endl;
    }

    cout << "ALL----------------" << endl;
    test.coutAll();
    return 0;
}
