#include <iostream>
#include <vector>
#include <string>
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

void updateNumber(string &number, string find)
{
    /** 半角スペースを削除します。 */
    number.erase(remove(number.begin(), number.end(), ' '), number.end());

    char x = number[0];
    /** 先頭文字調整 */
    if ('+' == x)
    {
        return;
    }

    if (starts_with(number, find))
    {
        number = "+" + number;
        return;
    }

    if ('0' == x)
    {
        number = "+" + find + number.substr(1);
        return;
    }

    number = "+" + find + number;
    return;
}

void normalize_phone_numbers(vector<string> &numbers, string find)
{
    for (auto idx = 0; idx < numbers.size(); idx++)
    {
        updateNumber(numbers[idx], find);
    }
}

int main()
{
    vector<string> numbers{
        "07555 123456",
        "07555123456",
        "+44 7555 123456",
        "44 7555 123456",
        "7555 123456"};

    normalize_phone_numbers(numbers, "44");

    for (string number : numbers)
    {
        cout << number << endl;
    }
}
