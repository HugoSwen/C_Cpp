#include <bits\stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e6 + 10, mod = 1e9 + 7, dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
int n, pos, nag;
ll a, minv, ans;

void solve()
{
    pos = nag = 0;
    minv = 2e9;
    ans = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a);
        if (a > 0)
            pos++;
        else nag++;
        minv = min(minv, abs(a));
        ans += abs(a);
    }

    if (n == 1)
    {
        printf("%lld\n", a);
        return;
    }

    if (pos == n || nag == n)
        ans -= 2 * minv;
    
    printf("%lld\n", ans);
}

int main()
{
    int T;
    cin >> T;
    // T = 1;
    while (T--)
        solve();

    return 0;
}
