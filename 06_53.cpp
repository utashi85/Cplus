#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct PointList
{
    int point;

    PointList(int inputted_point)
    {
        point = inputted_point;
    }

    bool operator<(const PointList &another) const
    {
        return point < another.point;
    };
};

double GetAvg(vector<PointList> pointList)
{
    int fulsize = pointList.size();
    int trim = fulsize * 0.05;
    double ret = 0;

    for (int index = trim; index < fulsize - trim; index++)
    {
        ret += pointList[index].point;
    }
    return ret / (fulsize - (2 * trim));
}

int main(void)
{
    vector<int> testData{7, 7, 8, 9, 7, 9, 6, 5, 6, 3, 8, 8, 3, 10, 5, 6, 4, 2, 3, 8, 1, 4, 8, 8, 3, 6, 7, 10, 9, 7, 5, 6, 1, 4, 7, 10, 10, 8, 7, 4, 5, 5, 5, 1, 2, 6, 8, 3, 10, 1, 7, 10, 2, 8, 7, 9, 6, 4, 7, 10, 9, 3, 3, 2, 7, 4, 8, 3, 10, 4, 8, 1, 6, 10, 6, 4, 7, 7, 5, 8, 6, 8, 5, 9, 8, 1, 2, 10, 8, 4, 2, 3, 2, 6, 4, 10, 3, 2, 7, 7, 4, 3, 7, 7, 6, 7, 6, 2, 4, 4, 3, 9, 8, 10, 8, 2, 4, 10, 5, 5, 2, 9, 6, 10, 10, 7, 3, 5, 4, 1, 10, 2, 7, 7, 2, 1, 8, 5, 2, 2, 9, 2, 2, 8, 4, 5, 10, 8, 9, 1, 1, 6, 1, 3, 1, 10, 7, 6, 2, 2, 2, 2, 2, 4, 10, 5, 10, 10, 1, 9, 8, 4, 4, 10, 7, 5, 1, 8, 9, 6, 8, 2, 4, 6, 9, 7, 4, 1, 10, 3, 2, 5, 9, 4, 6, 5, 5, 2, 10, 5};
    vector<PointList> moviesPointList;
    for (int point : testData)
    {
        moviesPointList.push_back(PointList(point));
    }

    sort(moviesPointList.begin(), moviesPointList.end()); //ソート実行

    cout << GetAvg(moviesPointList) << endl;

    return 0;
}
