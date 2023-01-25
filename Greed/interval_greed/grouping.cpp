/*
贪心得到的可行解：cnt
1. ans <= cnt
由于贪心产生的第cnt个组时，该区间与前cnt - 1个组中的最后一个区间共cnt个，两两之间都有交集，因此这cnt个区间不能在同一组
2. ans >= cnt
则 ans = cnt
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5 + 10;

int n;
struct Range
{
    int l, r;
    bool operator<(const Range &w) const // 重载小于号
    {
        return l < w.l;
    }
} range[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    priority_queue<int, vector<int>, greater<int>> heap; // 小根堆命名
    for (int i = 0; i < n; i++)
    {
        auto r = range[i];
        if (heap.empty() || r.l <= heap.top()) // 堆是空的或者当前区间与最小右边界有交集
            heap.push(r.r);                    // 新加一组
        else
            heap.pop(), heap.push(r.r); // 更新最小右边界
    }

    cout << heap.size() << endl;
    return 0;
}