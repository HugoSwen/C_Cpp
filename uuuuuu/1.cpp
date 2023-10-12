#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MOD = 998244353, N = 1e6 + 10;
int p[N], f[N], dep[N], cnt[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y)
{
    x = find(x), y = find(y);

    if (x == y)
        return;
    if (dep[x] < dep[y])
        swap(x, y);

    cnt[y] += cnt[x];
    p[x] = y;
}

ll qmi(ll a, ll b, int p)
{
    ll res = 1 % p;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }

    return res;
}

vector<int> G[N];
void dfs(int u, int fa, int d)
{
    dep[u] = d;
    for (auto v : G[u])
    {
        if (v == fa)
            continue;
        f[v] = u;
        dfs(v, u, d + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    f[1] = 1;
    for (int i = 1; i < N; ++i)
        p[i] = i, cnt[i] = 1;
    int n;
    cin >> n;
    vector<PII> op(n - 1);
    for (auto &[x, y] : op)
        cin >> x >> y;
    for (int i = 1; i <= n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, -1, 1);
    ll ans = 1;
    for (auto [x, y] : op)
    {
        x = find(x), y = find(y);
        if (find(f[x]) != y && find(f[y]) != x)
        {
            cout << 0 << '\n';
            return 0;
        }
        ans *= ((ll)cnt[x] * cnt[y]) % MOD;
        ans %= MOD;
        merge(x, y);
    }
    cout << qmi(ans, MOD - 2, MOD) << '\n';
}
