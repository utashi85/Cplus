#include <iostream>
#include <vector>

#define MAXINDEX (32)

using namespace std;

class heap_c
{
private:
    vector<uint16_t> data;
    bool swap(uint16_t &A, uint16_t &B)
    {
        if (A > B)
        {
            uint16_t buf = A;
            A = B;
            B = buf;
            return true; /** swap実行 */
        }
        return false; /** 親のほうが小さい */
    }

    void push_heap(void)
    {
        uint32_t idx = data.size();
        while (idx > 1)
        {
            if (!swap(data[((idx / 2) - 1)], data[idx - 1]))
            {
                return;
            }
            idx = idx / 2;
        }
        return;
    }

    void pop_heap(void)
    {
        uint32_t idx = 1;
        while (2 * idx < data.size())
        {
            uint32_t idx_parent = idx;
            idx = ((data[(2 * idx) - 1] > data[2 * idx]) ? (2 * idx) + 1 : (2 * idx));
            if (!swap(data[idx_parent - 1], data[idx - 1]))
                return;
        }

        /** 奇数個の場合 */
        if (2 * idx == data.size())
            swap(data[idx - 1], data[(2 * idx) - 1]);
        return;
    }

public:
    void push(uint16_t input)
    {
        data.push_back(input);
        push_heap();
    }

    void pop(void)
    {
        /** 末端を先頭に代入 */
        data[0] = data[data.size() - 1];
        /** 末端を削除 */
        data.pop_back();
        pop_heap();
    }

    uint16_t top(void) { return data[0]; }

    uint32_t size() { return data.size(); }

    bool empty() { return data.empty(); }

    void cout_All()
    {
        for (uint8_t idx; idx < data.size(); idx++)
            cout << data[idx] << " ";
        cout << endl;
        return;
    }
};

int main()
{
    vector<uint16_t> data{16, 8, 9, 22, 14, 7, 5, 4, 3, 23};
    heap_c testHeap;
    cout << "test start" << endl;
    for (auto x : data)
    {
        testHeap.push(x);
    }

    while (!testHeap.empty())
    {
        cout << " " << testHeap.top() << endl;
        testHeap.pop();
    }
    return 0;
}
