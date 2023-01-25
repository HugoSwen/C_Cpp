/*
邻项交换证明法
*/
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 5e5 + 10;

int n;
PII cow[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w, s;
        scanf("%d%d", &w, &s);
        cow[i] = {w, s};
    }

    // 按照w + 从小到大的顺序排序
    sort(cow, cow + n, [](PII a, PII b)
         { return a.first + a.second < b.first + b.second; });

    int res = -2e9, sum = 0; // sum 为当前牛的承重
    for (int i = 0; i < n; i++)
    {
        int w = cow[i].first, s = cow[i].second;
        res = max(res, sum - s);
        sum += w; // 更新承重
    }

    cout << res << endl;
    return 0;
}