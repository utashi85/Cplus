#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
 * 責任たらいまわし
 * 参考：https://qiita.com/i-tanaka730/items/073c106c58d7c74c1706
*/

class Request {
private:
    bool permit;            /**< 許可状態 */
    string authorizerRank;  /**< 承認者 */
    string item;            /**< 申請商品 */
    long long price;        /**< 金額 */

    string who;
    string when;
    string why;
public:
    /* Todo 誰が・いつ・なぜ　申請したか */

    /* 申請するものを設定 */
    void set(string itemName, long itemPrice) {
        item = itemName;
        price = itemPrice;
        permit = false;
        authorizerRank = "non";
    };

    /* 設定された金額を取得 */
    long long getPrice(void) {
        return price;
    };

    void setAuthorizer(string rank) {
        authorizerRank = rank;
        permit = true;
    };

    string getResult() {
        if (!permit) {
            return "rejection!!";
        }
        return "approved:" + authorizerRank;
    }
};

class Authority {
private:
    Authority *nextAuthority;
    virtual bool judge(Request *request) const noexcept = 0;
    virtual string rank() const noexcept = 0;

public:
    void setNext(Authority *next)
    {
        nextAuthority = next;
    }

    void approval(Request *request)
    {
        if (judge(request)) {
            request->setAuthorizer(rank());
            return;
        }
        nextAuthority->approval(request);
    }

};

class Staff : public Authority {
private:
    virtual bool judge(Request *request) const noexcept override
    {
        return (request->getPrice() <= 1000);
    }

    virtual string rank() const noexcept override
    {
        return "Staff";
    }
};

class TeamManager : public Authority {
private:
    virtual bool judge(Request *request) const noexcept override
    {
        return (request->getPrice() <= 10000);
    }

    virtual string rank() const noexcept override
    {
        return "TeamManager";
    }
};

class GroupReader : public Authority {
private:
    virtual bool judge(Request *request) const noexcept override
    {
        return (request->getPrice() <= 100000);
    }

    virtual string rank() const noexcept override
    {
        return "GroupReader";
    }
};

class President : public Authority {
private:
    virtual bool judge(Request *request) const noexcept override
    {
        return true;
    }

    virtual string rank() const noexcept override
    {
        return "President";
    }
};

int main ()
{

    Request test[8];
    test[0].set("999", 999);
    test[1].set("1000", 1000);
    test[2].set("1001", 1001);
    test[3].set("9999", 9999);
    test[4].set("10000", 10000);
    test[5].set("10001", 10001);
    test[6].set("99999", 99999);
    test[7].set("100000", 100000);
    test[8].set("100001", 100001);

    President honda;
    GroupReader yamaha;
    TeamManager suzuki;
    Staff kawasaki;

    /* 承認経路設定 */
    kawasaki.setNext(&suzuki);
    suzuki.setNext(&yamaha);
    yamaha.setNext(&honda);

    for (int idx = 0; idx < 9; idx++ )
    {
        Request *request = &test[idx];
        kawasaki.approval(request);
        cout << idx << ":" << request->getPrice() << ":" << request->getResult() << endl;
    }

    return 0;
}
