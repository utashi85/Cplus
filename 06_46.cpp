#include <iostream>
#include <vector>

#define MAXINDEX (5)

using namespace std;

inline uint16_t incrementIdx(uint16_t idx)
{
    uint16_t ret = idx + 1;
    return (ret < MAXINDEX ? ret : 0);
}

class Cago_c
{
private:
    uint16_t Baggage[MAXINDEX];
    uint16_t head;
    uint16_t tail;
    uint16_t count;

public:
    /** 初期化 */
    void initialize()
    {
        head = 0;
        tail = 0;
        count = 0;
    }
    /** 追加 */
    void setPush(uint16_t input)
    {
        Baggage[tail] = input;
        tail = incrementIdx(tail);
        count++;
        /** 上書き発生 */
        if (MAXINDEX < count)
        {
            count = MAXINDEX;
            /** 先頭が上書きされたので調整 */
            head = incrementIdx(head);
        }
    }
    /** 削除 */
    void popOut(void)
    {
        if (count != 0)
        {
            head = incrementIdx(head);
            count--;
        }
    }
    /** データ取得 */
    uint16_t getTop(void)
    {
        return Baggage[head];
    }
    /** 件数取得 */
    uint16_t getSize(void)
    {
        return count;
    }
    /** から？ */
    bool isEmpty(void)
    {
        return (count == 0 ? true : false);
    }
    /** 全出力 */
    void allCout(void)
    {
        uint16_t cnt = count;
        uint16_t idx = head;
        cout << "Baggage = { ";
        while (cnt > 0)
        {
            cout << Baggage[idx] << ", ";
            idx = incrementIdx(idx);
            cnt--;
        }
        cout << " }" << endl;
    }
};

int main()
{
    Cago_c test;
    test.initialize();
    cout << "isEmpty:" << (test.isEmpty() ? "True" : "False") << endl;
    test.setPush(1);
    test.setPush(2);
    test.setPush(3);
    test.setPush(4);

    cout << "test 1" << endl;
    cout << "isEmpty:" << (test.isEmpty() ? "True" : "False") << endl;
    cout << "size:" << test.getSize() << endl;
    test.allCout();

    cout << "--popOut--" << endl;
    test.popOut();
    cout << "isEmpty:" << (test.isEmpty() ? "True" : "False") << endl;
    cout << "size:" << test.getSize() << endl;
    test.allCout();
    test.setPush(5);
    test.setPush(6);
    test.setPush(7);
    test.allCout();
    cout << "getTop:" << test.getTop() << endl;
    cout << "popOut X 3" << endl;
    test.popOut();
    test.popOut();
    test.popOut();
    test.allCout();
    cout << "isEmpty:" << (test.isEmpty() ? "True" : "False") << endl;
    cout << "size:" << test.getSize() << endl;
    cout << "popOut X 3" << endl;
    test.popOut();
    test.popOut();
    test.popOut();
    cout << "isEmpty:" << (test.isEmpty() ? "True" : "False") << endl;
    cout << "size:" << test.getSize() << endl;
    test.allCout();

    cout << "size:" << test.getSize() << endl;
    return 0;
}
