#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int n;
struct range
{
    int l, r;
    bool operator<(const range &w) const // 重载小于号
    {
        return r < w.r;
    }
} Range[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        Range[i] = {l, r}; // 结构体赋值
    }

    sort(Range, Range + n); // 结构体数组排序

    int res = 0, rb = -2e9; // 初始化
    for (int i = 0; i < n; i++)
        if (Range[i].l > rb)        // 当前区间左端点在rd右边，即两者无交集
            res++, rb = Range[i].r; // 答案+1，更新rd

    cout << res << endl;
    return 0;
}
