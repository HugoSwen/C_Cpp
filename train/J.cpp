#include <iostream>
#include <cstdio>
using namespace std;
using ll = long long;

const int N = 2505, MOD = 998244353;
int n, k;
ll f[N][N];

void solve()
{
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= k; i++)
        f[0][i] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            f[i][j] = 0;

    for (int i = 0; i < n; i++)
        for (int l = 1; l <= k; l++)
            for (int r = 1; i + l * r <= n && l - 1 + r <= k; r++)
                f[i + l * r][r] = (f[i + l * r][r] + f[i][l]) % MOD;
    
    ll ans = 0;
    for (int i = 1; i <= k; i++)
        ans = (ans + f[n][i]) % MOD;
    printf("%lld\n", ans);
}

int main()
{
    int T;
    cin >> T;
    while (T --)
        solve();

    return 0;
}