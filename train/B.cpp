#include <bits\stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 10;
int n, ans;
ll x[N], y[N];

ll chaji(ll x1, ll y1, ll x2, ll y2)
{
    return x1 * y2 - x2 * y1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &x[i], &y[i]);
    
    for (int i = 0, r = 1; i < n; i++)
    {
        while (y[i] == y[r])
            r = (r + 1) % n;
        int l = (i + n - 1) % n;
        if (y[i] < y[l] && y[i] < y[r])
        {
            r = (i + 1) % n;
            if (chaji(x[i] - x[l], y[i] - y[l], x[r] - x[i], y[r] - y[i]) > 0)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}