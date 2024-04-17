#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e5 + 10;
ll t[N];
ll n, Q, tc;

void solve()
{
    ll M;
    scanf("%lld", &M);
    ll x = M / tc;
    ll rest = n - x;
    if (rest < 0) rest = 0;
    printf("%lld\n", t[rest] + tc);
}

int main()
{
    cin >> n >> Q >> tc;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &t[i]);
    sort(t + 1, t + n + 1);

    for (int i = 1; i <= n; i++)
        t[i] += t[i - 1];

    while (Q --)
        solve();
    return 0;
}