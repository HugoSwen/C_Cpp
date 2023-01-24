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
