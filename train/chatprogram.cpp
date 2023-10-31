#include <bits\stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

ll n, k, m, c, d;
ll a[N];
int flag[N], cnt;
bool st[N];

// 判断大于等于 mid 的数是否大于等于 k 个 （找最大）
bool check(ll x)
{
    memset(flag, 0, (n + 2) * 4);
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] >= x) st[i] = 1, cnt++;
        else st[i] = 0;
    
    if (cnt >= k)
        return true;
    
    for (ll i = 1; i <= n; i++)
        if (!st[i])
        {
            int mr = min(m, i);
            ll maxd = c + d * (mr - 1);
            if (a[i] + maxd < x) continue;
            else if (a[i] + c >= x) // 加上最小的也满足要求
            {
                flag[max(m, i)]++; // 加上maxd这种情况末尾的坐标
                flag[min(n + 1, i + m)]--;
            } else
            {
                ll delta = x - a[i] - c, len;
                if (delta % d) len = delta / d + 1;
                else len = delta / d;

                flag[max(m, i)]++;
                flag[min(n + 1, i + m - len)]--;
            }
        }
    
    for (int i = m; i <= n; i++)
    {
        cnt += flag[i];
        if (cnt >= k)
            return true;
    }

    return false;
}

void solve()
{
    scanf("%lld%lld%lld%lld%lld", &n, &k, &m, &c, &d);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    ll l = 0, r = 1e15;
    while (l < r)
    {
        ll mid = l + r  + 1>> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    
    printf("%lld", r);
}

int main()
{
    int t;
    t = 1;

    while (t --)
    {
        solve();
    }
    return 0;
}
