#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

set<pii> h;
int n, x, y;
int cnt[5];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        h.insert({x, y});
    }

    for (auto t: h)
    {
        x = t.first, y = t.second;
        if (h.count({x, y + 1}) && h.count({x, y - 1}) && h.count({x + 1, y}) && h.count({x - 1, y}))
        {
            int sum = h.count({x + 1, y + 1}) + h.count({x - 1, y + 1}) + h.count({x + 1, y - 1}) + h.count({x - 1, y - 1});
            cnt[sum] ++;
        }
    }

    for (int i = 0; i < 5; i++)
        printf("%d\n", cnt[i]);
    return 0;
}