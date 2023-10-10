/*
贪心得到的可行解：cnt
1. ans <= cnt
由于cnt是在所有互相没有交集的区间中各选一个点，由于ans包含的区间有或没有交集
2. ans >= cnt
则 ans = cnt
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

int n;
vector<PII> range;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range.push_back({l, r});
    }

    sort(range.begin(), range.end(), [](PII a, PII b)
         { return a.second < b.second; });

    int res = 0, rb = -2e9;
    for (int i = 0; i < n; i++)
        if (range[i].first > rb)
            res++, rb = range[i].second;

    cout << res << endl;
    return 0;
}
