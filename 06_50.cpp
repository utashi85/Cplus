#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 先頭に特定の文字列があるか判定
 * @param str    検索対象
 * @param prefix 検索文字
 *
 * @retval true  strの先頭がprefixと一致する
 * @retval false strの先頭がprefixと異なる
 */
bool starts_with(string str, string find)
{
    return str.find(find) == 0;
}

/**
 * 先頭に特定の文字列がある電話番号をすべて返す
 * @param numbers 電話番号リスト
 * @param find    検索文字
 *
 * @return hitした要素をすべて返す
 */
vector<string> filter_numbers(vector<string> numbers, string find)
{
    vector<string> result;

    /** 検索文字 Or ’+’ & 検索文字でヒットした場合にコピーする */
    copy_if(numbers.begin(), numbers.end(), back_inserter(result),
            [find](string number) { return starts_with(number, find) ||
                                           starts_with(number, "+" + find); });
    return result;
}

int main()
{
    vector<string> numbers{
        "+40744909080",
        "44 7520 112233",
        "+44 7555 123456",
        "40 7200 123456",
        "7555 123456"};

    auto result = filter_numbers(numbers, "44");

    for (string number : result)
    {
        std::cout << number << std::endl;
    }
}
